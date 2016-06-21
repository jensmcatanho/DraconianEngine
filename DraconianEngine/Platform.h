#pragma once

namespace Draconian {

// CPU configuration.
#define DRACO_CPU_X86     0
#define DRACO_CPU_ARM     1
#define DRACO_CPU_MIPS    3
#define DRACO_CPU_UNKNOWN 4

// Architecture configuration.
#define DRACO_ARCHITECTURE_32 0
#define DRACO_ARCHITECTURE_64 1

// Endianness configuration.
#define DRACO_LITTLE_ENDIAN 0
#define DRACO_BIG_ENDIAN    1

// Operating system configuration.
#define DRACO_PLATFORM_WIN32   0
#define DRACO_PLATFORM_LINUX   1
#define DRACO_PLATFORM_ANDROID 2

// Compiler configuration.
#define DRACO_COMPILER_MSVC 0
#define DRACO_COMPILER_GNUC 1

// C++ version configuration.
#define DRACO_CPP_VER_UNDEFINED      0L
#define DRACO_CPP_VER_98        199711L
#define DRACO_CPP_VER_11        201103L
#define DRACO_CPP_VER_14        201402L

// Sets DRACO_CPU to the current CPU type.
#if (defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))) || (defined(__GNUC__) && (defined(__i386) || defined(__x86_64__)))
	#define DRACO_CPU DRACO_CPU_X86
#elif defined(__arm__) || defined(_M_ARM) || defined(__arm64__) || defined(__aarch64__)
	#define DRACO_CPU DRACO_CPU_ARM
#elif defined(__mips64) || defined(__mips64_)
	#define DRACO_CPU DRACO_CPU_MIPS
#else
	#define DRACO_CPU DRACO_CPU_UNKNOWN
#endif

// Sets DRACO_ARCH_TYPE to the current architecture type.
#if defined(__x86_64__) || defined(_M_X64)
	#define DRACO_ARCHITECTURE_TYPE DRACO_ARCHITECTURE_64
#else
	#define DRACO_ARCHITECTURE_TYPE DRACO_ARCHITECTURE_32
#endif

// Sets DRACO_ENDIANNES to little-endian configuration by default unless DRACO_CONFIG_BIG_ENDIAN is defined.
#ifdef DRACO_CONFIG_BIG_ENDIAN
#define DRACO_ENDIANNES DRACO_BIG_ENDIAN
#else
#define DRACO_ENDIANNES DRACO_LITTLE_ENDIAN
#endif

// Sets DRACO_PLATFORM to the current operational system.
#if defined(_WIN32)
	#define DRACO_PLATFORM DRACO_PLATFORM_WIN32
#elif defined(__ANDROID__)
	#define DRACO_PLATFORM DRACO_PLATFORM_ANDROID
#else
	#define DRACO_PLATFORM DRACO_PLATFORM_LINUX
#endif

// Sets DRACO_COMPILER to the current compiler.
#if defined(_MSC_VER)
	#define DRACO_COMPILER DRACO_COMPILER_MSVC
	#define DRACO_COMPILER_VER _MSC_VER
#elif defined(__GNUC__) || defined(__GNUG__)
	#define DRACO_COMPILER DRACO_COMPILER_GNUC
	#define DRACO_COMPILER_VER (__GNUC__ * 100) + (__GNUC_MINOR__ * 10) + __GNUC_PATCHLEVEL__
#else
	#pragma error "Unknown compiler!"
#endif

// Sets DRACO_CPP_VER to the current C++ version.
#if defined(__cplusplus)
	#if __cplusplus >= DRACO_CPP_VER_14
		#define DRACO_CPP_VER DRACO_CPP_VER14
	#elif __cplusplus >= DRACO_CPP_VER_11
		#define DRACO_CPP_VER DRACO_CPP_VER_11
	#elif __cplusplus >= DRACO_CPP_VER_98
		#define DRACO_CPP_VER DRACO_CPP_VER_98
	#else
		#define DRACO_CPP_VER DRACO_CPP_VER_UNDEFINED
	#endif
#endif

// ----------------------------------------------------------------------------------------------------
// Windows settings.
#if DRACO_PLATFORM == DRACO_PLATFORM_WIN32
	// windows.h is not included here because it conflicts with many STL libraries.
	#if defined(_DEBUG) || defined(DEBUG)
		#define DRACO_DEBUG 1
	#else
		#define DRACO_DEBUG 0
	#endif
#endif

// Linux/Android settings.
#if DRACO_PLATFORM == DRACO_PLATFORM_LINUX || DRACO_PLATFORM == DRACO_PLATFORM_ANDROID
	#if defined(DEBUG)
		#define DRACO_DEBUG 1
	#else
		#define DRACO_DEBUG 0
	#endif
#endif
/*
#include <cstdint>

// Sized integer types
typedef std::int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;
*/

// Shorthand unsigned notations 
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

}
