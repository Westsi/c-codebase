/* date = 27 Apr 2023 19:37 */

#include "memory.h"
#include <stdlib.h>

// Malloc Base Implementation of M_BaseMemory

void* m_malloc_reserve(void *ctx, U64 size) {
    return malloc(size);
}

void* m_malloc_release(void *ctx, void *ptr, U64 size) {
    free(ptr);
}

M_BaseMemory* m_malloc_base_memory(void) {
    static M_BaseMemory memory = {};
    if (memory.reserve == 0) {
        memory.reserve = m_malloc_reserve;
        memory.commit = m_change_memory_noop;
        memory.decommit = m_change_memory_noop;
        memory.release = m_malloc_release;
    }

    return &memory;
}