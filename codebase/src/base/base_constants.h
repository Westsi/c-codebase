/* date = 26 Apr 2023 18:26 */

#ifndef BASE_CONSTANTS_H_
#define BASE_CONSTANTS_H_
#include "base_types.h"

// Basic Constants
#pragma region BASCONST
extern S8 min_S8;
extern S16 min_S16;
extern S32 min_S32;
extern S64 min_S64;

extern S8 max_S8;
extern S16 max_S16;
extern S32 max_S32;
extern S64 max_S64;

extern U8 max_U8;
extern U16 max_U16;
extern U32 max_U32;
extern U64 max_U64;

extern F32 machine_epsilon_F32;
extern F32 pi_F32;
extern F32 tau_F32;
extern F32 e_F32;
extern F32 gold_big_F32;
extern F32 gold_small_F32;

extern F64 machine_epsilon_F64;
extern F64 pi_F64;
extern F64 tau_F64;
extern F64 e_F64;
extern F64 gold_big_F64;
extern F64 gold_small_F64;

// float constant functions for infinity b/c no other way to do it
F32 inf_F32(void);
F32 neg_inf_F32(void);
F64 inf_F64(void);
F64 neg_inf_F64(void);

#pragma endregion BASCONST

// Symbolic Constants
#pragma region SYMCONST
typedef enum Axis {
    Axis_X,
    Axis_Y,
    Axis_Z,
    Axis_W,
} Axis;

typedef enum Side {
    Side_Min,
    Side_Max,
} Side;

typedef enum OperatingSystem {
    OperatingSystem_Null,
    OperatingSystem_Windows,
    OperatingSystem_Linux,
    OperatingSystem_Mac,
    OperatingSystem_COUNT,
} OperatingSystem;

// typedef enum Architecture {
//     Architecture_Null,
//     Architecture_X64,
//     Architecture_X86,
//     Architecture_ARM,
//     Architecture_AMR64,
//     Architecture_COUNT,
// } Architecture;

typedef enum Month {
    Month_Jan,
    Month_Feb,
    Month_Mar,
    Month_Apr,
    Month_May,
    Month_Jun,
    Month_Jul,
    Month_Aug,
    Month_Sep,
    Month_Oct,
    Month_Nov,
    Month_Dec,
} Month;

typedef enum DayOfWeek {
    DayOfWeek_Sunday,
    DayOfWeek_Monday,
    DayOfWeek_Tuesday,
    DayOfWeek_Wednesday,
    DayOfWeek_Thursday,
    DayOfWeek_Friday,
    DayOfWeek_Saturday,
} DayOfWeek;

#pragma endregion SYMCONST


#endif //BASE_CONSTANTS_H