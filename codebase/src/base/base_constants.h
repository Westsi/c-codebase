/* date = 26 Apr 2023 18:26 */

#ifndef BASE_CONSTANTS_H_
#define BASE_CONSTANTS_H_

// Basic Constants
#pragma region BASCONST

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