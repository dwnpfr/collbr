#ifndef COLLBR_DEFS_H_
#define COLLBR_DEFS_H_
#include "Ctx.h"
//https://www.ibm.com/docs/en/zos/2.4.0?topic=options-lp64-ilp32
//https://www.ibm.com/docs/en/ent-metalc-zos/3.1.0?topic=environments-ilp32-lp64-data-models-data-type-sizes

typedef long long int unsigned tU64;
#define tU64_Max 18446744073709551615LLU
#define tU64_Min 0LLU

typedef long long int signed tS64;
#define tS64_Max 9223372036854775807LL
#define tS64_Min -9223372036854775808LL

typedef int unsigned tU32;
#define tU32_Max 4294967295U
#define tU32_Min 0U

typedef int signed tS32;
#define tS32_Max 2147483647
#define tS32_Min -2147483648

typedef short int unsigned tU16;
#define tU16_Max 65535U
#define tU16_Min 0U

typedef short int signed tS16;
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

typedef char tAChr;
typedef tU16 tWChr;
#ifdef Col_Uni
typedef tWChr tChr;
#else
typedef tAChr tChr;
#endif

typedef int tInt;
typedef void *tPtr;
#define Null (tPtr)0U
#define pass Null

#if Col_Bit == 32U
typedef tU32 tUSz;
#define tUSz_Max tU32_Max
#define tUSz_Min tU32_Min
typedef tS32 tSSz;
#define tSSz_Max tS32_Max
#define tSSz_Min tS32_Min

#elif Col_Bit == 64U
typedef tU64 tUSz;
#define tUSz_Max tU64_Max
#define tUSz_Min tU64_Min
typedef tS64 tSSz;
#define tSSz_Max tS64_Max
#define tSSz_Min tS64_Min

typedef float tF32;
typedef double tF64;

#else
#error 'Err: Unreachable.'
#endif

#endif//COLLBR_DEFS_H_