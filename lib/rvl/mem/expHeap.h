#pragma once

#include "memAllocator.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// MEMiExpHeapMBlockHead is the heap block header.
typedef struct MEMiExpHeapMBlockHead MEMiExpHeapMBlockHead;
struct MEMiExpHeapMBlockHead {
  u16 signature; // 0x00
  union {
    u16 val; // 0x02
    struct {
      u16 dir : 1; // 0x02
      u16 alignment : 7;
      u16 groupID : 8; // 0x03
    } fields;
  } attribute;
  u32 blockSize;               // 0x04
  MEMiExpHeapMBlockHead* prev; // 0x08
  MEMiExpHeapMBlockHead* next; // 0x0C
};

// MEMiExpMBlockList is the header of the free/used blocks double-linked list.
typedef struct MEMiExpMBlockList MEMiExpMBlockList;
struct MEMiExpMBlockList {
  MEMiExpHeapMBlockHead* head;
  MEMiExpHeapMBlockHead* tail;
};

// MEMiExpHeapHead is the extended heap header.
typedef struct MEMiExpHeapHead MEMiExpHeapHead;
struct MEMiExpHeapHead {
  MEMiExpMBlockList freeList;
  MEMiExpMBlockList usedList;
  u16 groupID;
  union {
    u16 val;
    struct {
      u16 _unk0_15 : 15;
      u16 allocMode : 1;
    } fields;
  } feature;
};

typedef struct MEM_Extent {
  void* start;
  void* end;
} MEM_Extent;

typedef void (*MEMExpHeapVisitor)(void* block, MEMHeapHandle heap,
                                  u32 user_data);

void* MEM_ExpAllocFromHead(MEMiHeapHead*, u32, int);
void* MEM_ExpAllocFromTail(MEMiHeapHead*, u32, int);
u32 MEM_ExpRecycleRegion(MEMiExpHeapHead*, const MEM_Extent*);
MEMHeapHandle MEMCreateExpHeapEx(void* begin, u32 size, u16 flags);
void* MEMDestroyExpHeap(MEMHeapHandle);
void* MEMAllocFromExpHeapEx(MEMHeapHandle heap, u32 size, int align);
u32 MEMResizeForMBlockExpHeap(MEMHeapHandle heap, void* block, u32 size);
void MEMFreeToExpHeap(MEMHeapHandle heap, void* block);
u32 MEMGetTotalFreeSizeForExpHeap(MEMHeapHandle heap);
u32 MEMGetAllocatableSizeForExpHeapEx(MEMHeapHandle heap, s32 align);
u16 MEMSetGroupIDForExpHeap(MEMHeapHandle heap, u16 group_id);
void MEMVisitAllocatedForExpHeap(MEMHeapHandle heap, MEMExpHeapVisitor visitor,
                                 u32 user_data);
u32 MEMGetSizeForMBlockExpHeap(const void*);
u16 MEMGetGroupIDForMBlockExpHeap(const void*);
u32 MEMAdjustExpHeap(MEMHeapHandle heap);

void MEMInitAllocatorForExpHeap(MEMAllocator* allocator, MEMHeapHandle heap,
                                int align);

#ifdef __cplusplus
}
#endif // __cplusplus
