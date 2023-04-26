/* date = 17 Apr 2023 11:46 */

#include "base_macros.h"
#include "base_types.h"
#include "base_constants.h"
#include <stdio.h>
#include <stdlib.h>

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