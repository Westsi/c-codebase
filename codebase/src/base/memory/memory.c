/* date = 27 Apr 2023 20:03 */

#include "memory.h"
#include "../base_macros.h"
#include <stdlib.h>

void* m_change_memory_noop(void *ctx, void *ptr, U64 size) {}


// Arena Functions

M_Arena m_make_arena_reserve(M_BaseMemory *base, U64 reserve_size) {
    M_Arena result = {};
    result.base = base;
    result.memory = base->reserve(base->ctx, reserve_size);
    result.cap = reserve_size;
    return result;
}

M_Arena m_make_arena(M_BaseMemory *base) {
    M_Arena result = m_make_arena_reserve(base, M_DEFAULT_RESERVE_SIZE);
    return result;
}

void m_arena_release(M_Arena *arena) {
    M_BaseMemory *base = arena->base;
    base->release(base->ctx, arena->memory, arena->cap);
}


void* m_arena_push(M_Arena *arena, U64 size) {
    void *result = 0;
    if (arena->pos + size <= arena->cap) {
        result = arena->memory + arena->pos;
        arena->pos += size;

        U64 p = arena->pos;
        U64 commit_p = arena->commit_pos;
        if (p > commit_p) {
            U64 pos_aligned = AlignUpPow2(p, M_COMMIT_BLOCK_SIZE);
            U64 next_commit_pos_clamped = ClampTop(pos_aligned, arena->cap);
            U64 commit_size = next_commit_pos_clamped - commit_p;

            M_BaseMemory *base = arena->base;
            base->commit(base->ctx, arena->memory + commit_p, commit_size);

            arena->commit_pos = next_commit_pos_clamped;
        }
    }
    return result;
}

void* m_arena_pop_to(M_Arena *arena, U64 pos) {
    if (pos < arena->pos) {
        arena->pos = pos;

        U64 p = arena->pos;
        U64 p_aligned = AlignUpPow2(p, M_COMMIT_BLOCK_SIZE);
        U64 next_commit_p = ClampTop(p_aligned, arena->cap);
        U64 commit_p = arena->commit_pos;
        if (next_commit_p < commit_p) {
            U64 decommit_size = commit_p - next_commit_p;
            M_BaseMemory *base = arena->base;
            base->decommit(base->ctx, arena->memory + next_commit_p, decommit_size);
            arena->commit_pos = next_commit_p;
        }
    }
}


void* m_arena_align(M_Arena *arena, U64 pow2_align) {
    U64 p = arena->pos;
    U64 p_aligned = AlignUpPow2(p, pow2_align);
    U64 z = p_aligned - p;
    if (z > 0) {
        m_arena_push(arena, z);
    }
}


M_Temp m_begin_temp(M_Arena *arena) {
    M_Temp temp = {arena, arena->pos};
    return temp;
}

void m_end_temp(M_Temp temp) {
    m_arena_pop_to(temp.arena, temp.pos);
}

