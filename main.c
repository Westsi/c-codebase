#include <stdio.h>
#include "codebase/src/stdbase.h"

int main(void) {
    M_BaseMemory *base_memory = m_malloc_base_memory();
    M_Arena arena = m_make_arena(base_memory);

    U64 count = 1000;
    V2S32 *vecs = (V2S32*)m_arena_push(&arena, sizeof(V2S32)*count);
    for (U64 i = 0; i < count; i += 1) {
        printf("starting writing vec number %d to arena\n", i);
        vecs[i].x = i;
        printf("completed writing vec number %d to arena\n", i);
    }

    return 0;
}