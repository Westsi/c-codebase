/* date = 26 Apr 2023 18:26 */

#include "base_constants.h"
#include "base_types.h"

F32 inf_F32(void) {
    union{ F32 f; U32 u; } r;
    r.u = 0x7f800000;
    return r.f;
}

F32 neg_inf_F32(void) {
    union{ F32 f; U32 u; } r;
    r.u = 0xff800000;
    return r.f;
}

F64 inf_F64(void) {
    union{ F64 f; U64 u; } r;
    r.u = 0x7ff0000000000000;
    return r.f;
}

F64 neg_inf_F64(void) {
    union{ F64 f; U64 u; } r;
    r.u = 0xfff0000000000000;
    return r.f;
}

S8 min_S8 = (S8) 0x80;
S16 min_S16 = (S16) 0x8000;
S32 min_S32 = (S32) 0x80000000;
S64 min_S64 = (S64) 0x8000000000000000LL;

S8 max_S8 = (S8) 0x7f;
S16 max_S16 = (S16) 0x7fff;
S32 max_S32 = (S32) 0x7fffffff;
S64 max_S64 = (S64) 0x7fffffffffffffffLL ;

U8 max_U8 = 0xff;
U16 max_U16 = 0xffff;
U32 max_U32 = 0xffffffff;
U64 max_U64 = 0xffffffffffffffffllu;

F32 machine_epsilon_F32 = 1.1920929e-7f;
F32 pi_F32 = 3.14159265359f;
F32 tau_F32 = 6.28318530718f;
F32 e_F32 = 2.71828182846f;
F32 gold_big_F32 = 1.61803398875f;
F32 gold_small_F32 = 0.61803398875f;

F64 machine_epsilon_F64 = 2.220446e-16;
F64 pi_F64 = 3.14159265359;
F64 tau_F64 = 6.28318530718;
F64 e_F64 = 2.71828182846;
F64 gold_big_F64 = 1.61803398875;
F64 gold_small_F64 = 0.61803398875;