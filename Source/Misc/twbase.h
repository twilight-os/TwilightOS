/*
 *	Twilight OS
 *	(c) 2025, Jel9
 */
#pragma once

#include <simpleboot.h>

#ifndef NULL
#define NULL 0
#endif

#ifndef va_arg
#define va_arg __crt_va_arg
#endif

#ifndef va_start
#define va_start __crt_va_start
#endif

#ifndef va_end
#define va_end __crt_va_end
#endif

typedef unsigned long long      TWSTATUS, *PTWSTATUS;

typedef signed char             CHAR, *PCHAR, *PSTR;
typedef signed short            SHORT, *PSHORT;
typedef signed int              INT, *PINT;
typedef signed long             LONG, *PLONG;
typedef signed long             LONG32, *PLONG32;
typedef signed long long        LONG64, *PLONG64;

typedef unsigned char           UCHAR, *PUCHAR;
typedef unsigned short          USHORT, *PUSHORT;
typedef unsigned int            UINT, *PUINT;
typedef unsigned long           ULONG, *PULONG;
typedef unsigned long           ULONG32, *PULONG32;
typedef unsigned long long      ULONG64, *PULONG64;

typedef unsigned char           BOOLEAN, *PBOOLEAN;
typedef long long               HANDLE, *PHANDLE;
typedef unsigned long long      SIZE_T, *PSIZE_T;
typedef unsigned long long      UCHAR_PTR, USHORT_PTR, ULONG_PTR, ULONG32_PTR, ULONG64_PTR;

typedef void                    *PVOID;
typedef const void              *PCVOID;

typedef unsigned char           BYTE, *PBYTE;
typedef unsigned short          WCHAR, *PWCHAR, *PWSTR;
typedef const char              *PCCHAR, *PCSTR;

typedef float                   FLOAT;
typedef double                  DOUBLE;
typedef char*                   VA_LIST;

#define CONST                   const
#define CONSTANT                const

#define EXTERN                  extern
#define STATIC                  static
#define VOLATILE                volatile
#define FORCEINLINE             __forceinline
#define UNALIGNED               __unaligned
#define DLLIMPORT               __declspec(dllimport)
#define DLLEXPORT               __declspec(dllexport)
#define NORETURN                __declspec(noreturn)
#define OPTIONAL

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

#define VOID                    void
#define TRUE                    1
#define FALSE                   0

#define TW_ASSERT( expression )  static_assert( expression, #expression );


INT
StrCompare(
    PCCHAR str1,
    PCCHAR str2
);

SIZE_T
StrLenght(
    PCSTR str
);