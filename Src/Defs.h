#ifndef COLLBR_DEFS_H_
#define COLLBR_DEFS_H_

#include "Ctx.h"
typedef long long unsigned tU64;
#define tU64_Max 18446744073709551615LLU
#define tU64_Min 0LLU

typedef long long signed tS64;
#define tS64_Max 9223372036854775807LL
#define tS64_Min -9223372036854775808LL

typedef int unsigned tU32;
#define tU32_Max 4294967295U
#define tU32_Min 0U

typedef int signed tS32;
#define tU32_Max 2147483647
#define tU32_Min -2147483648

typedef short unsigned tU16;
#define tU16_Max 65535U
#define tU16_Min 0U

typedef short signed tS16;
#define tS16_Max 32767
#define tS16_Min -32768

typedef char unsigned tU8;
#define tU8_Max 255U
#define tU8_Min 0U

typedef char signed tS8;
#define tS8_Max 127
#define tS8_Min -128

typedef _Bool tBln;
#define True (tBln)1U
#define False (tBln)0U

typedef char tChr;

typedef void *tPtr;
#define Null (tPtr)0U

#if COLLBR_Bit == 32U
typedef tU32 tUSz;
#define tUSz_Max tU32_Max
#define tUSz_Min tU32_Min
typedef tS32 tSSz;
#define tSSz_Max tS32_Max
#define tSSz_Min tS32_Min
#elif COLLBR_Bit == 64U
typedef tU64 tUSz;
#define tUSz_Max tU64_Max
#define tUSz_Min tU64_Min
typedef tS64 tSSz;
#define tSSz_Max tS64_Max
#define tSSz_Min tS64_Min
#else
#error "Err: Unreachable."
#endif

#endif//COLLBR_DEFS_H_