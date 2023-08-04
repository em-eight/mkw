"""
Assembly file generators.
"""

import argparse
from pathlib import Path, PurePosixPath
import os
from re import I
import struct
import shutil

import jinja2
from ast import literal_eval

from mkwutil.lib.ppc_dis import InlineInstruction, disasm_iter, label_name
from mkwutil.lib.dol import DolBinary
from mkwutil.lib.rel import Rel, dump_staticr
from mkwutil.lib.symbols import Symbol, SymbolsList
from mkwutil.sections import DOL_SECTIONS, REL_SECTIONS, REL_SECTION_IDX, Section
from mkwutil.lib.slices import Slice, SliceTable
from mkwutil.ppcdis_adapter.ppcdis_disas import get_dol_disaser, get_rel_disaser
from ppcdis import Disassembler

from mkwutil.project import *

jinja_env = jinja2.Environment(
    loader=jinja2.PackageLoader("mkwutil", "gen_asm"),
    autoescape=jinja2.select_autoescape(),
)
jinja_env.filters["addr"] = lambda x: "0x%08x" % (x)


def is_text_addr(addr):
    # could be less hardcoded using mkwutil.lib
    return (0x805103b4<=addr and addr<0x8088f400) or (0x80004000<=addr and addr<0x80006460) or (0x800072c0<=addr and addr<0x80244de0)

class AsmGenerator:
    """Generates assembly files."""

    def __init__(self, data, _slice, symbols, output, rel=False):
        self.data = data
        self.slice = _slice
        self.symbols = symbols
        self.output = output
        self.symbol_locs = sorted([sym.addr for sym in symbols])
        self.is_rel = rel


    # TODO Define symbols in ASM

    def emit_symbol(self, address):
        """Maybe emits a symbol, if there is one."""
        if address not in self.symbols:
            return
        name = self.symbols[address].name
        print(f'.global "{name}"\n"{name}":', file=self.output)

    def dump_bss(self):
        """Writes a bss segment."""
        for part in self.slice.split(self.symbol_locs):
            self.emit_symbol(part.start)
            print(".skip 0x%x" % len(part), file=self.output)

    def dump_data(self):
        """Writes a data segment."""
        for part in self.slice.split(self.symbol_locs):
            self.emit_data_words(part)

    def emit_data_words(self, part: Slice):
        """Emits a bunch of data segment words."""
        for address, chunk in self.iter_data_chunks(part, 4):
            if len(chunk) == 4:
                self.emit_symbol(address)
                print(".4byte 0x%08X" % struct.unpack(">I", chunk), file=self.output)
            else:
                self.emit_data_bytes(address, chunk)

    def emit_data_bytes(self, address, data):
        """Emits a few data segment bytes."""
        while len(data) > 0:
            self.emit_symbol(address)
            byte_val = data[0]
            print(".byte 0x%02x" % (byte_val), file=self.output)
            data = data[1:]
            address += 1

    def get_data_chunk(self, part: Slice) -> bytes:
        view = memoryview(self.data)
        view = view[part.start - self.slice.start :]
        view = view[: len(part)]
        return bytes(view)

    def iter_data_chunks(
        self, part: Slice, chunk_size: int
    ) -> Iterator[tuple[int, bytes]]:
        offset = part.start - self.slice.start
        # Use memoryview to scan over data efficiently.
        view = memoryview(self.data)
        view = view[offset : part.stop - self.slice.start]
        # Align first word.
        if offset % chunk_size != 0 and len(view) > chunk_size:
            cut = chunk_size - offset
            left, view = view[:cut], view[cut:]
            yield self.slice.start + offset, bytes(left)
            offset += len(left)
        while len(view) > 0:
            if len(view) > chunk_size:
                bs = len(view)
            else:
                bs = chunk_size
            left, view = view[:bs], view[bs:]
            yield self.slice.start + offset, bytes(left)
            offset += len(left)

    def dump_text(self):
        """Writes a disassembled text segment."""
        for part in self.slice.split(self.symbol_locs):
            assert part.start % 4 == 0, "misaligned text"
            self.emit_symbol(part.start)
            for ins in disasm_iter(self.get_data_chunk(part), part.start, self.symbols):
                print(ins.disassemble(dont_use_labels=self.is_rel), file=self.output)

    def dump_section_body(self):
        name = self.slice.section
        if "bss" in name:
            self.dump_bss()
        elif name == "text":
            self.dump_text()
        else:
            self.dump_data()

    def format_segname(self, name):
        if name in ("extab", "extabindex"):
            # The linker is supposed to auto-generate those.
            # It will crash if we try to feed it those sections with object files.
            return name + "_"
        return "." + name

    def dump_section_header(self):
        """Writes the header to output."""
        # section permissions
        perm = self.compute_perm()
        print(
            f""".include "macros.inc"
.section {self.format_segname(self.slice.section)}, "{perm}" # {self.slice}""",
            file=self.output,
        )

    def compute_perm(self):
        """Computes the memory permissions."""
        name = self.slice.section
        perm = "wa"
        if name == "text":
            perm = "ax"
        # if "bss" in name:
        #     perm = "ba"
        if name == "rodata" or "2" in name:
            perm = perm.replace("w", "")
        return perm

    def dump_section(self):
        """Writes unit header and body to output."""
        self.dump_section_header()
        self.dump_section_body()

class CAsmGenerator:
    """Generates C files with assembly functions."""

    def __init__(self, disaser, _slices, symbols, out_h, out_c, cpp_mode):
        self.disaser = disaser
        self.slices = _slices
        self.symbols = symbols
        self.out_h = out_h
        self.out_c = out_c
        self.cpp_mode = cpp_mode
        # The list of seen extern declarations.
        self.extern_addrs = set()
        self.extern_functions = []
        self.extern_data = []
        # Output dirs
        self.func_dir = Path("./source") / "func"
        self.jtl_dir = Path("./source") / "jtl"
        self.func_dir.mkdir(exist_ok=True)
        self.jtl_dir.mkdir(exist_ok=True)

    def lookup_sym(self, addr):
        start, end = self.disaser._sym.get_containing_symbol(addr)
        sym = self.symbols.get(addr)
        if sym is not None:
            sym.size = end-addr
            return sym
        else:
            return Symbol(start, f"lbl_{addr:x}", end-addr)


    def dump_source(self):
        """Writes the C file to output."""
        functions = []
        rodata = []
        data = []
        bss = []

        for _slice in self.slices:
            addr = _slice.start
            while addr < _slice.stop:
                sym = self.lookup_sym(addr)
                if _slice.section == "text":
                    func_body = [f"#include \"asm/{addr:x}.s\"\n"]
                    # only called to collect refs lmao
                    self.disassemble_function(addr)
                    functions.append(
                        {
                            "addr": sym.addr,
                            "size": sym.size,
                            "name": sym.name,
                            "inline_asm": func_body,
                        }
                    )
                elif _slice.section == "rodata":
                    rodata_c = self.decompile_data(addr, const=True)
                    rodata.append(rodata_c)
                elif _slice.section == "data":
                    data_c = self.decompile_data(addr, const=False)
                    data.append(data_c)
                elif _slice.section == "bss":
                    # Remove duplicate extern declaration
                    self.extern_data.remove((addr, sym.name))
                    bss.append({
                        "size": sym.size,
                        "name": sym.name,
                    })

                addr += sym.size

        # Sort extern functions.
        self.extern_functions.sort(key=lambda ref: ref[0])
        self.extern_data.sort(key=lambda ref: ref[0])
        # Write out to C file.
        template = jinja_env.get_template("source.c.j2")
        template.stream(
            header=Path(self.out_h.name).name,
            cpp=self.cpp_mode,
            functions=functions,
            rodata=rodata,
            data=data,
            bss=bss,
            extern_functions=list({"name": a[1], "addr": a[0]} for a in self.extern_functions),
            extern_data=list({"name": a[1], "addr": a[0]} for a in self.extern_data),
        ).dump(self.out_c)
        # Write out to H file.
        template = jinja_env.get_template("source.h.j2")
        template.stream(functions=functions).dump(self.out_h)


    def disassemble_function(self, fn_start_vma):
        inline_asm, refs = self.disaser.function_to_text_with_referenced(fn_start_vma, inline=True, extra=False,
            hashable=False, declare_mangled=False)
        self.collect_refs(refs)
        return inline_asm.split("\n")

    def decompile_data(self, addr, const):
        txt, refs = self.disaser.data_to_text_with_referenced(addr, const=const)
        self.collect_refs(refs)
        # Remove duplicate extern declaration
        self.extern_data.remove((addr, self.disaser._sym.get_name(addr)))
        return txt

    def collect_refs(self, refs):
        for (addr, name) in refs:
            if addr not in self.extern_addrs:
                self.extern_addrs.add(addr)

                if is_text_addr(addr):
                    self.extern_functions.append((addr, name))
                else:
                    self.extern_data.append((addr, name))


def get_asm_path(folder, _slice):
    assert _slice.section is not None
    return folder / ("%s_%08x_%08x.s" % (_slice.section, _slice.start, _slice.stop))


class DOLSrcGenerator:
    """Generates assembly files from DOL."""

    def __init__(
        self,
        slices: SliceTable,
        dol: DolBinary,
        disaser: Disassembler,
        symbols: SymbolsList,
        dol_asm_dir: Path,
        pack_dir: Path,
        regen_asm: bool,
    ):
        self.slices = slices
        self.slices.set_sections(DOL_SECTIONS)
        self.dol = dol
        self.disaser = disaser
        self.symbols = symbols
        self.dol_asm_dir = dol_asm_dir
        self.pack_dir = pack_dir
        self.regen_asm = regen_asm
        self.dol_asm_sources = set()
        self.dol_decomp_sources = set()

    # Delete stale ASM files.
    def __prune_asm(self):
        for path in self.dol_asm_dir.iterdir():
            if path.suffix != ".s":
                continue
            if path.stem not in self.dol_asm_sources:
                os.remove(path)

    def __stem_for_asm_slice(self, _slice):
        if _slice.has_name():
            return Path(Path(_slice.name).name)

        return get_asm_path(Path("dol"), _slice)

    def __outpath_of_asm_slice(self, _slice):
        # Wrong term maybe
        stem = self.__stem_for_asm_slice(_slice)
        out_path = Path("out") / stem.with_suffix(".o")
        return str(out_path)

    # Iterator of all non-empty sections
    def __slice_sections(self):
        for _slice in self.slices:
            if _slice.section is None:
                continue

            yield _slice

    # Give all ASM slices a name. This makes the slice table unusable.
    def __name_asm_slices(self):
        for _slice in self.__slice_sections():
            _slice.name = self.__outpath_of_asm_slice(_slice)

    # Write list of objects for linker.
    def __write_objlist(self):
        # Drop slices smaller than 4 bytes.
        objects = self.slices.object_slices().objects
        for object in list(objects.keys()):
            # Drop slice.
            slices = objects[object]
            for i, slice in reversed(list(enumerate(slices))):
                if len(slice) < 4:
                    slices.pop(i)
            # Drop entire object if all slices have been removed.
            if len(slices) == 0:
                del objects[object]
        object_names = objects.keys()
        with open(self.pack_dir / "dol_objects.txt", "w") as file:
            for name in object_names:
                print(PurePosixPath(Path(name)), file=file)

    def run(self):
        """Runs ASM generation for main.dol."""
        for section in DOL_SECTIONS:
            self.__process_section(section)

        self.__prune_asm()
        self.__name_asm_slices()
        self.__write_objlist()

    def __process_section(self, section: Section):
        """Processes a program section and all its slices."""
        subtable = self.slices.slice(section.start, section.stop)
        # print(f".{section.name} ({section.type}): {subtable.count()} slices")
        for _slice in subtable:
            self.__process_slice(section, _slice)

    # If the slice should be output as a .s file
    def __slice_dest_asm(self, _slice):
        return not _slice.has_name()

    # If the slice should be output as a .c file
    def __slice_dest_c(self, _slice):
        return _slice.has_name()

    def __process_slice(self, section: Section, _slice: Slice):
        """Process a slice in slices.csv or a gap."""
        # print(f"  {_slice}")

        if self.__slice_dest_asm(_slice):
            self.__gen_asm(section, _slice)
            return

        # TODO Ideally this would work on the notion of objects instead of slices.
        if self.__slice_dest_c(_slice):
            source_path = Path(_slice.name)
            if source_path.stem not in self.dol_decomp_sources:
                self.dol_decomp_sources.add(source_path.stem)
            if section.type == "code":
                self.__gen_c(_slice)

    def __gen_c(self, _slice: Slice):
        """Generates a C file with inline assembly if not exists."""
        # Generate C inline assembly.
        c_path = Path(_slice.name)
        h_path = c_path.with_suffix(".h" if str(c_path).endswith(".c") else ".hpp")
        if c_path.exists() or h_path.exists():
            return

        c_path.parent.mkdir(parents=True, exist_ok=True)
        # print(f"    => {_slice.name}")
        data = self.dol.virtual_read(_slice.start, len(_slice))
        with open(h_path, "w") as h_file, open(c_path, "w") as c_file:
            gen = CAsmGenerator(
                data,
                self.disaser,
                _slice,
                self.symbols,
                h_file,
                c_file,
                not str(c_path).endswith(".c"),
            )
            gen.dump_slice()

    def __gen_asm(self, section: Section, _slice: Slice):
        """Generates an ASM file."""
        # Relocatable ASM unsupported for DOL
        """
        asm_path = get_asm_path(self.dol_asm_dir, _slice)
        self.dol_asm_sources.add(asm_path.stem)
        if not self.regen_asm and asm_path.exists():
            return
        # print(f"    => {asm_path}")
        self.disaser.output_slice(asm_path, _slice.start, _slice.start+len(_slice))
        """
        asm_path = get_asm_path(self.dol_asm_dir, _slice)
        self.dol_asm_sources.add(asm_path.stem)
        if not self.regen_asm and asm_path.exists():
            return
        # print(f"    => {asm_path}")
        with open(asm_path, "w") as asm_file:
            data = (
                self.dol.virtual_read(_slice.start, len(_slice))
                if section.type != "bss"
                else None
            )
            gen = AsmGenerator(data, _slice, self.symbols, asm_file)
            gen.dump_section()


INLINE_ASM_RE = r'#include "asm\/([0-9a-f]{8})\.s"'
class RELSrcGenerator:
    """Generates assembly from REL."""

    def __init__(
        self,
        slices: SliceTable,
        rel: Rel,
        disaser: Disassembler,
        symbols: SymbolsList,
        rel_asm_dir: Path,
        rel_bin_dir: Path,
        source_dir: Path,
        pack_dir: Path,
        regen_asm: bool,
    ):
        self.slices = slices
        self.slices.set_sections(REL_SECTIONS)
        self.rel = rel
        self.disaser = disaser
        self.symbols = symbols
        self.rel_asm_dir = rel_asm_dir
        self.rel_bin_dir = rel_bin_dir
        self.source_dir = source_dir
        self.pack_dir = pack_dir
        self.regen_asm = regen_asm
        self.rel_asm_sources = set()
        self.inline_asm_pattern = re.compile(INLINE_ASM_RE)

    def run(self):
        """Runs ASM generation for StaticR.rel"""
        source_asm_dir = self.source_dir / "asm"
        for c_source_name, sections in self.slices.object_slices():
            self.__gen_c(c_source_name, sections)
            self.__gen_includes(c_source_name, source_asm_dir)
        for _slice in self.slices:
            if _slice.section is None:
                # ignore slices not belonging to sections
                continue
            if self.__slice_dest_asm(_slice):
               self. __gen_asm(_slice)
        # Delete stale ASM files.
        for path in self.rel_asm_dir.iterdir():
            if path.suffix != ".s":
                continue
            if path.stem not in self.rel_asm_sources:
                os.remove(path)
        # Give all ASM slices a name. This makes the slice table unusable.
        for _slice in self.slices:
            if _slice.section is None:
                continue
            out_path = None
            if not _slice.has_name():
                out_path = get_asm_path(Path("rel"), _slice)
            else:
                out_path = Path(Path(_slice.name).name)
            out_path = Path("out") / out_path.with_suffix(".o")
            _slice.name = str(out_path)
        # Write list of objects for linker.
        object_names = self.slices.object_slices().objects.keys()
        with open(self.pack_dir / "rel_objects.txt", "w") as file:
            for name in object_names:
                print(PurePosixPath(Path(name)), file=file)

    def __process_section(self, section: Section):
        """Processes a library section and all its slices."""
        subtable = self.slices.slice(section.start, section.stop)
        print(f".{section.name} ({section.type}): {subtable.count()} slices")
        for _slice in subtable:
            self.__process_slice(section, _slice)

    # If the slice should be output as a .s file
    def __slice_dest_asm(self, _slice):
        return not _slice.has_name()

    # If the slice should be output as a .c file
    def __slice_dest_c(self, _slice):
        return _slice.has_name()


    def __gen_c(self, c_source_name: str, _slices: list[Slice]):
        c_path = Path(c_source_name)
        h_path = c_path.with_suffix(".h" if str(c_path).endswith(".c") else ".hpp")
        if not (c_path.exists() or h_path.exists()):
            c_path.parent.mkdir(parents=True, exist_ok=True)
            with open(h_path, "w") as h_file, open(c_path, "w") as c_file:
                gen = CAsmGenerator(
                    self.disaser,
                    _slices,
                    self.symbols,
                    h_file,
                    c_file,
                    not str(c_path).endswith(".c"),
                )
                gen.dump_source()

    def __gen_asm(self, _slice: Slice):
        """Generates an ASM file."""
        asm_path = get_asm_path(self.rel_asm_dir, _slice)
        self.rel_asm_sources.add(asm_path.stem)
        if not self.regen_asm and asm_path.exists():
            return
        # print(f"    => {asm_path}")
        self.disaser.output_slice(asm_path, _slice.start, _slice.start+len(_slice))

    def __gen_includes(self, c_source_name: str, out_path: Path):
        c_path = Path(c_source_name)
        assert c_path.exists(), f"C source {c_source_name} not found"
        with open(c_path, "r") as c_file:
            c_text = c_file.read()
            for addr_str in re.findall(self.inline_asm_pattern, c_text):
                addr = int(addr_str, 16)
                inline_asm = self.disaser.function_to_text(addr, inline=True, extra=False,
                                                           hashable=False, declare_mangled=False)
                out_file = out_path / f"{addr:x}.s"
                with open(out_file, "w") as asm_file:
                    asm_file.write(inline_asm)


def gen_asm(regen_asm=False):
    asm_dir = Path("./asm")
    pack_dir = Path("./pack")
    source_dir = Path("./source")
    source_asm_dir = source_dir / "asm"
    binary_dir = Path("./artifacts/orig/pal")

    asm_dir.mkdir(exist_ok=True)
    shutil.rmtree(source_asm_dir, ignore_errors=True)
    source_asm_dir.mkdir()

    symbols = read_symbol_map(pack_dir / "symbols.yml")
    symbols.derive_sizes(0x81000000)

    dol = read_dol(binary_dir / "main.dol")
    dol_disaser = get_dol_disaser()
    dol_slices = read_enabled_slices(dol, pack_dir / "dol_slices.yml")

    # Disassemble DOL sections.
    dol_asm_dir = asm_dir / "dol"
    dol_asm_dir.mkdir(exist_ok=True)
    dol_gen = DOLSrcGenerator(
        dol_slices, dol, dol_disaser, symbols, dol_asm_dir, pack_dir, regen_asm
    )

    rel = read_rel(binary_dir / "StaticR.rel")
    rel_disaser = get_rel_disaser()
    # Dump StaticR.rel segments.
    rel_bin_dir = binary_dir / "rel"
    dump_staticr(rel, rel_bin_dir)
    # Map out slices in REL.
    rel_slices = load_rel_slices(sections=REL_SECTIONS).filter(SliceTable.ONLY_ENABLED)
    # Disassemble REL sections.
    rel_asm_dir = asm_dir / "rel"
    rel_asm_dir.mkdir(exist_ok=True)
    rel_gen = RELSrcGenerator(
        rel_slices, rel, rel_disaser, symbols, rel_asm_dir, rel_bin_dir, source_dir, pack_dir, regen_asm
    )
    dol_gen.run()
    rel_gen.run()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Generate ASM blobs and linker object lists."
    )
    parser.add_argument("--regen_asm", action="store_true", help="Regenerate all ASM files")
    args = parser.parse_args()
    gen_asm(args.regen_asm)
