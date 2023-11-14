#pragma once

#include <code/tcpgecko.h>

#include <malloc.h>

#define MEMORY_ARENA_1          0
#define MEMORY_ARENA_2          1
#define MEMORY_ARENA_3          2
#define MEMORY_ARENA_4          3
#define MEMORY_ARENA_5          4
#define MEMORY_ARENA_6          5
#define MEMORY_ARENA_7          6
#define MEMORY_ARENA_8          7
#define MEMORY_ARENA_FG_BUCKET  8

EXPORT_VAR(unsigned int*, pMEMAllocFromDefaultHeapEx);
EXPORT_VAR(unsigned int*, pMEMAllocFromDefaultHeap);
EXPORT_VAR(unsigned int*, pMEMFreeToDefaultHeap);

EXPORT_DECL(int, MEMGetBaseHeapHandle, int mem_arena);
EXPORT_DECL(unsigned int, MEMGetAllocatableSizeForFrmHeapEx, int heap, int align);
EXPORT_DECL(void *, MEMAllocFromFrmHeapEx, int heap, unsigned int size, int align);
EXPORT_DECL(void, MEMFreeToFrmHeap, int heap, int mode);
EXPORT_DECL(void *, MEMAllocFromExpHeapEx, int heap, unsigned int size, int align);
EXPORT_DECL(int, MEMCreateExpHeapEx, void *address, unsigned int size, unsigned short flags);
EXPORT_DECL(void *, MEMDestroyExpHeap, int heap);
EXPORT_DECL(void, MEMFreeToExpHeap, int heap, void *ptr);

static int mem1_heap = -1;
static int bucket_heap = -1;

void InitMemoryFunctionPointers() {
    uint32_t coreinit_handle;
    uint32_t* funcPointer = 0;
    OSDynLoad_Acquire("coreinit.rpl", &coreinit_handle);
    OSDynLoad_FindExport(coreinit_handle, 1, "MEMAllocFromDefaultHeapEx", &pMEMAllocFromDefaultHeapEx);
	OSDynLoad_FindExport(coreinit_handle, 1, "MEMAllocFromDefaultHeap", &pMEMAllocFromDefaultHeap);
	OSDynLoad_FindExport(coreinit_handle, 1, "MEMFreeToDefaultHeap", &pMEMFreeToDefaultHeap);

	OS_FIND_EXPORT(coreinit_handle, MEMGetBaseHeapHandle);
	OS_FIND_EXPORT(coreinit_handle, MEMGetAllocatableSizeForFrmHeapEx);
	OS_FIND_EXPORT(coreinit_handle, MEMAllocFromFrmHeapEx);
	OS_FIND_EXPORT(coreinit_handle, MEMFreeToFrmHeap);
	OS_FIND_EXPORT(coreinit_handle, MEMAllocFromExpHeapEx);
	OS_FIND_EXPORT(coreinit_handle, MEMCreateExpHeapEx);
	OS_FIND_EXPORT(coreinit_handle, MEMDestroyExpHeap);
	OS_FIND_EXPORT(coreinit_handle, MEMFreeToExpHeap);

}

void memoryInitialize(void) {
    int mem1_heap_handle = MEMGetBaseHeapHandle(MEMORY_ARENA_1);
    unsigned int mem1_allocatable_size = MEMGetAllocatableSizeForFrmHeapEx(mem1_heap_handle, 4);
    void *mem1_memory = MEMAllocFromFrmHeapEx(mem1_heap_handle, mem1_allocatable_size, 4);
    if(mem1_memory)
        mem1_heap = MEMCreateExpHeapEx(mem1_memory, mem1_allocatable_size, 0);

    int bucket_heap_handle = MEMGetBaseHeapHandle(MEMORY_ARENA_FG_BUCKET);
    unsigned int bucket_allocatable_size = MEMGetAllocatableSizeForFrmHeapEx(bucket_heap_handle, 4);
    void *bucket_memory = MEMAllocFromFrmHeapEx(bucket_heap_handle, bucket_allocatable_size, 4);
    if(bucket_memory)
        bucket_heap = MEMCreateExpHeapEx(bucket_memory, bucket_allocatable_size, 0);
}

void memoryRelease(void) {
    MEMDestroyExpHeap(mem1_heap);
    MEMFreeToFrmHeap(MEMGetBaseHeapHandle(MEMORY_ARENA_1), 3);
    mem1_heap = -1;

    MEMDestroyExpHeap(bucket_heap);
    MEMFreeToFrmHeap(MEMGetBaseHeapHandle(MEMORY_ARENA_FG_BUCKET), 3);
    bucket_heap = -1;
}

void *__wrap_malloc(size_t size)
{
    // pointer to a function resolve
	return ((void * (*)(size_t))(*pMEMAllocFromDefaultHeap))(size);
}

void *__wrap_memalign(size_t align, size_t size)
{
    if (align < 4)
        align = 4;

    // pointer to a function resolve
    return ((void * (*)(size_t, size_t))(*pMEMAllocFromDefaultHeapEx))(size, align);
}

void __wrap_free(void *p)
{
    // pointer to a function resolve
    if(p != 0)
        ((void (*)(void *))(*pMEMFreeToDefaultHeap))(p);
}

void *__wrap_calloc(size_t n, size_t size)
{
    void *p = __wrap_malloc(n * size);
	if (p != 0) {
		memset(p, 0, n * size);
	}
	return p;
}

size_t __wrap_malloc_usable_size(void *p)
{
    //! TODO: this is totally wrong and needs to be addressed
	return 0x7FFFFFFF;
}

void *__wrap_realloc(void *p, size_t size)
{
    void *new_ptr = __wrap_malloc(size);
	if (new_ptr != 0)
	{
		memcpy(new_ptr, p, __wrap_malloc_usable_size(p) < size ? __wrap_malloc_usable_size(p) : size);
		__wrap_free(p);
	}
	return new_ptr;
}

//!-------------------------------------------------------------------------------------------
//! reent versions
//!-------------------------------------------------------------------------------------------
void *__wrap__malloc_r(struct _reent *r, size_t size)
{
	return __wrap_malloc(size);
}

void *__wrap__calloc_r(struct _reent *r, size_t n, size_t size)
{
    return __wrap_calloc(n, size);
}

void *__wrap__memalign_r(struct _reent *r, size_t align, size_t size)
{
    return __wrap_memalign(align, size);
}

void __wrap__free_r(struct _reent *r, void *p)
{
    __wrap_free(p);
}

size_t __wrap__malloc_usable_size_r(struct _reent *r, void *p)
{
    return __wrap_malloc_usable_size(p);
}

void *__wrap__realloc_r(struct _reent *r, void *p, size_t size)
{
    return __wrap_realloc(p, size);
}

//!-------------------------------------------------------------------------------------------
//! some wrappers
//!-------------------------------------------------------------------------------------------
void * MEM2_alloc(unsigned int size, unsigned int align)
{
    return __wrap_memalign(align, size);
}

void MEM2_free(void *ptr)
{
    __wrap_free(ptr);
}

void * MEM1_alloc(unsigned int size, unsigned int align)
{
    if (align < 4)
        align = 4;
    return MEMAllocFromExpHeapEx(mem1_heap, size, align);
}

void MEM1_free(void *ptr)
{
    MEMFreeToExpHeap(mem1_heap, ptr);
}

void * MEMBucket_alloc(unsigned int size, unsigned int align)
{
    if (align < 4)
        align = 4;
    return MEMAllocFromExpHeapEx(bucket_heap, size, align);
}

void MEMBucket_free(void *ptr)
{
    MEMFreeToExpHeap(bucket_heap, ptr);
}