#ifndef COLLBR_CTX_H_
#define COLLBR_CTX_H_

#if defined(WIN64) || defined(_WIN64) || defined(__WIN64) || defined(__MINGW64__)
#define COLLBR_Os_Windows

#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(__MINGW32__)
#define COLLBR_Os_Windows

#elif defined(__APPLE__) || defined(__MACH__) || defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
#define COLLBR_Os_Darwin

#elif defined(__linux__) || defined(__linux) || defined(linux)
#define COLLBR_Os_Linux

#elif defined(__FreeBSD__)
#define COLLBR_Os_FreeBsd

#elif defined(__NetBSD__)
#define COLLBR_Os_NetBsd

#elif defined(__OpenBSD__)
#define COLLBR_Os_OpenBsd

#elif defined(__DragonFly__)
#define COLLBR_Os_DragonFlyBsd

#elif defined(__sun__) || defined(__SVR4) || defined(__solaris__)
#define COLLBR_Os_Solaris

#elif defined(_AIX) || defined(__AIX__)
#define COLLBR_Os_Aix

#elif defined(__hpux)
#define COLLBR_Os_Hpux

#elif defined(__QNX__) || defined(__QNXNTO__)
#define COLLBR_Os_Qnx

#elif defined(__unix__) || defined(unix)
#define COLLBR_Os_Unix

#else
#error "Err: Unknown operating system."
#endif//Os

#if defined(_M_IX86) || defined(__i386__)
#define COLLBR_Arch_i386
#define COLLBR_Bit 32U

#elif defined(_M_AMD64) || defined(_M_X64) || defined(__x86_64__)
#define COLLBR_Arch_Amd64
#define COLLBR_Bit 64U

#elif defined(__arm__)
#define COLLBR_Arch_Arm
#define COLLBR_Bit 32U

#elif defined(__arm64__) || defined(__aarch64__)
#define COLLBR_Arch_Arm
#define COLLBR_Bit 64U

#elif defined(_M_ARM)
#define COLLBR_Arch_Arm

#else
#error "Err: Unknown architecture."
#endif//Arch

#ifndef COLLBR_Bit
#if sizeof(void*) == 4U
#define COLLBR_Bit 32U
#elif sizeof(void*) == 8U
#define COLLBR_Bit 64U
#else
#error "Err: Unknown bitness."
#endif
#endif//COLLBR_Bit

#if defined(_MSC_VER) || defined(_MSVC_LANG)
#define COLLBR_Comp_Msvc

#elif defined(__GNUC__) || defined(__GNUC_MINOR__)
#define COLLBR_Comp_Gnu

#elif defined(__clang__) || defined(__clang_major__)
#define COLLBR_Comp_Clang

#elif defined(__INTEL_COMPILER) || defined(__ICC)
#define COLLBR_Comp_Intel

#elif defined(__BORLANDC__)
#define COLLBR_Comp_Borland

#else
#error "Err: Unknown compiler."
#endif//COMP

#if defined(_DEBUG) || defined(DEBUG)
#define COLLBR_Dbg
#endif//Dbg

#endif//COLLBR_CTX_H_