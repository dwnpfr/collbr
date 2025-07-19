#ifndef COLLBR_CTX_H_
#define COLLBR_CTX_H_

//Os https://sourceforge.net/p/predef/wiki/OperatingSystems/
#if defined(_WIN16)
#define Col_Os_Windows

#elif defined(_WIN64) || defined(__WIN64) || defined(__MINGW64__)
#define Col_Os_Windows

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(__MINGW32__)
#define Col_Os_Windows

#elif defined(__APPLE__) || defined(__MACH__) || defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
#define Col_Os_Osx

#elif defined(__linux__) || defined(__linux) || defined(linux)
#define Col_Os_Linux

#elif defined(__unix__) || defined(unix)
#define Col_Os_Unix

#else
#error 'Err: Unknown operative system.'
#endif//Os

//Arch https://sourceforge.net/p/predef/wiki/Architectures/
#if defined(_M_IX86) || defined(__i386__) || defined(__i386) || defined(i386) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
#define Col_Arch_i386
#define Col_Bit 32U

#elif defined(_M_AMD64) || defined(_M_X64) || defined(__x86_64__) || defined (__amd64) || defined(__x86_64) || defined (__amd64__)
#define Col_Arch_Amd64
#define Col_Bit 64U

#elif defined(__arm__)
#define Col_Arch_Arm
#define Col_Bit 32U

#elif defined(__arm64__) || defined(__aarch64__)
#define Col_Arch_Arm
#define Col_Bit 64U

#elif defined(_M_ARM)
#define Col_Arch_Arm

#elif defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
#define Col_Arch_Mips

#else
#error 'Err: Unknown architecture.'
#endif//Arch

#ifndef Col_Bit
#if sizeof(void*) == 4U
#define Col_Bit 32U
#elif sizeof(void*) == 8U
#define Col_Bit 64U
#else
#error 'Err: Unknown bitness.'
#endif
#endif//Col_Bit

//Comp https://sourceforge.net/p/predef/wiki/Compilers/
#if defined(_MSC_VER) || defined(_MSVC_LANG)
#define Col_Comp_Msvc

#elif defined(__clang__)
#define Col_Comp_Cl

#elif defined(__GNUC__)
#define Col_Comp_Gnu

#elif defined(__INTEL_COMPILER) || defined(__ICC) || defined(__ECC) || defined(__ICL)
#define Col_Comp_Icc

#elif defined(__BORLANDC__)
#define Col_Comp_Bc

#elif defined(__DMC__)
#define Col_Comp_Dmc

#else
#error 'Err: Unknown compiler.'
#endif//Comp

#if defined(_DEBUG) || defined(DEBUG)
#define Col_Dbg 1
#else
#define Col_Dbg 0
#endif//Dbg

#ifdef Col_Os_Windows
#if defined(_UNICODE) || defined(UNICODE)
#define Col_Uni
#endif
#endif

#endif//COLLBR_CTX_H_