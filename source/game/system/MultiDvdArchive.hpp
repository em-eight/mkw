#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggHeap.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8052a098..0x8052a1c8
UNKNOWN_FUNCTION(MultiDvdArchive_create);
// PAL: 0x8052a1c8..0x8052a21c
UNKNOWN_FUNCTION(unk_8052a1c8);
// PAL: 0x8052a21c..0x8052a2a8
UNKNOWN_FUNCTION(CourseMultiDvdArchive_init);
// PAL: 0x8052a2a8..0x8052a2fc
UNKNOWN_FUNCTION(unk_8052a2a8);
// PAL: 0x8052a2fc..0x8052a36c
UNKNOWN_FUNCTION(unk_8052a2fc);
// PAL: 0x8052a36c..0x8052a3c0
UNKNOWN_FUNCTION(unk_8052a36c);
// PAL: 0x8052a3c0..0x8052a430
UNKNOWN_FUNCTION(unk_8052a3c0);
// PAL: 0x8052a430..0x8052a488
UNKNOWN_FUNCTION(unk_8052a430);
// PAL: 0x8052a488..0x8052a4e0
UNKNOWN_FUNCTION(unk_8052a488);
// PAL: 0x8052a4e0..0x8052a538
UNKNOWN_FUNCTION(unk_8052a4e0);
// PAL: 0x8052a538..0x8052a648
UNKNOWN_FUNCTION(MultiDvdArchive_ct);
// PAL: 0x8052a6dc..0x8052a760
UNKNOWN_FUNCTION(MultiDvdArchive_dt);
// PAL: 0x8052a760..0x8052a800
UNKNOWN_FUNCTION(MultiDvdArchive_getFile);
// PAL: 0x8052a800..0x8052a864
UNKNOWN_FUNCTION(unk_8052a800);
// PAL: 0x8052a864..0x8052a954
UNKNOWN_FUNCTION(MultiDvdArchive_exists);
// PAL: 0x8052a954..0x8052aa88
UNKNOWN_FUNCTION(MultiDvdArchive_load);
// PAL: 0x8052ab6c..0x8052ac40
UNKNOWN_FUNCTION(unk_8052ab6c);
// PAL: 0x8052ac40..0x8052aca0
UNKNOWN_FUNCTION(unk_8052ac40);
// PAL: 0x8052aca0..0x8052ad08
UNKNOWN_FUNCTION(unk_8052aca0);
// PAL: 0x8052ad08..0x8052ad80
UNKNOWN_FUNCTION(unk_8052ad08);
// PAL: 0x8052ad80..0x8052ae08
UNKNOWN_FUNCTION(unk_8052ad80);
// PAL: 0x8052ae08..0x8052ae5c
UNKNOWN_FUNCTION(unk_8052ae08);

#ifdef __cplusplus
}
#endif

// TODO: remove after declaring DvdArchive
typedef enum {
    DVD_ARCHIVE_STATE_CLEARED = 0,
    DVD_ARCHIVE_STATE_RIPPED = 2,
    DVD_ARCHIVE_STATE_DECOMPRESSED = 3,
    DVD_ARCHIVE_STATE_MOUNTED = 4
} ArchiveState;

class DvdArchive {
public:
    DvdArchive();
    void clearArchive();
    void unmount();
    void loadOther(DvdArchive* other, EGG::Heap* heap);
    virtual ~DvdArchive();
private:
    void *mArchive;                     // this pointer is not void, but does not matter in the scope of this function
    void *mArchiveStart;
    u32 mArchiveSize;
    EGG::Heap *mArchiveHeap;
    void *mFileStart;
    u32 mFileSize;
    EGG::Heap *mFileHeap;
    volatile ArchiveState mStatus;
};

class MultiDvdArchive {
public:
    MultiDvdArchive();
    void init();
    void unmount();
    void loadOther(MultiDvdArchive* other, EGG::Heap* heap);
    virtual ~MultiDvdArchive();
private:
    DvdArchive *archives;
    u16 archiveCount;
    u8 _0a[0x10 - 0x0a];
    char **suffixes;
    u8 _14[0x18 - 0x14];
    u32 *kinds;
};
