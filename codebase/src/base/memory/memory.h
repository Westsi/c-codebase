/* date = 27 Apr 2023 19:37 */

#ifndef MEMORY_H_
#define MEMORY_H_
#include "../base_types.h"

// Base Memory V-Table
typedef void* M_ReserveFunc(void *ctx, U64 size);
typedef void* M_ChangeMemoryFunc(void *ctx, void *ptr, U64 size);

typedef struct M_BaseMemory {
    M_ReserveFunc *reserve;
    M_ChangeMemoryFunc *commit;
    M_ChangeMemoryFunc *decommit;
    M_ChangeMemoryFunc *release;
    void *ctx;
} M_BaseMemory;

// Base Memory Helper Functions

void* m_change_memory_noop(void *ctx, void *ptr, U64 size);

// Arena Types

typedef struct M_Arena {
    M_BaseMemory *base;
    U8 *memory;
    U64 cap;
    U64 pos;
    U64 commit_pos;
} M_Arena;

typedef struct M_Temp {
    M_Arena *arena;
    U64 pos;
} M_Temp;

// Arena Functions

#define M_DEFAULT_RESERVE_SIZE GB(1)
#define M_COMMIT_BLOCK_SIZE MB(64)

M_Arena m_make_arena_reserve(M_BaseMemory *base, U64 reserve_size);
M_Arena m_make_arena(M_BaseMemory *base);

void m_arena_release(M_Arena *arena);

void* m_arena_push(M_Arena *arena, U64 size);
void* m_arena_pop_to(M_Arena *arena, U64 pos);

void* m_arena_align(M_Arena *arena, U64 pow2_align);

void* m_malloc_reserve(void *ctx, U64 size);

void* m_malloc_release(void *ctx, void *ptr, U64 size);

M_BaseMemory* m_malloc_base_memory(void);

#define push_array(a,T,c) (T*)m_arena_push((a), sizeof(T)*(c))
#define push_array_zero(a,T,c) (T*)m_arena_push_zero((a), sizeof(T)*(c))

M_Temp m_begin_temp(M_Arena *arena);
void m_end_temp(M_Temp temp);

#endif //MEMORY_H