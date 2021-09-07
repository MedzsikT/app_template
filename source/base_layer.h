/* date = September 5th 2021 10:54 am */

#ifndef BASE_LAYER_H
#define BASE_LAYER_H

//~ Includes
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//~ Defines
#define global   static
#define local    static
#define internal static

#ifdef _MSC_VER
# define FUNCTION_NAME __FUNCSIG__
#else 
# define FUNCTION_NAME __PRETTY_FUNCTION__
#endif

#define StringifyImpl(A) #A
#define Stringify(A) StringifyImpl(A)
#define ConnectImpl(A, B) A##B
#define Connect(A, B) ConnectImpl(A, B)
#define F32ToGLColor(F) F / 255.0f
#define V4ToGLColor(vec) v4(F32ToGLColor(vec.x), F32ToGLColor(vec.y), F32ToGLColor(vec.z), F32ToGLColor(vec.w));
#define ArrayCount(a) (sizeof(a) / sizeof((a)[0]))
#define Bytes(n)      (n)
#define Kilobytes(n)  (Bytes(n)*1024)
#define Megabytes(n)  (Kilobytes(n)*1024)
#define MemoryCopy                 memcpy
#define MemorySet                  memset
#define MemoryMove                 memmove

/* Math */
#define SinF                       sinf
#define CosF                       cosf
#define TanF                       tanf
#define ArcTan2F                   atan2f
#define PowF                       powf
#define FModF                      fmodf
#define AbsoluteValue              fabsf
#define AbsoluteValueI             abs
#define SquareRoot                 sqrtf
#define PI 3.1415926535897f
#define ONE_OVER_SQUARE_ROOT_OF_TWO_PI 0.3989422804
#define ONE_OVER_SQUARE_ROOT_OF_TWO_PIf 0.3989422804f
#define EULERS_NUMBER 2.7182818284590452353602874713527
#define EULERS_NUMBERf 2.7182818284590452353602874713527f
#define ToRadians(degrees) (float)(degrees * (PI / 180.0f))
#define ToDegrees(radians) (float)(radians * (180.0f / PI))

#ifdef _WIN32
# define OS Windows
#elif macintosh
# define OS Macintosh
#elif __linux__
# define OS Linux
#else
# define OS NULL
# warning "Couldn't detect OS!"
#endif

#define AssertBreak() *(int*)0 = 0;
#define Assert(expression, message) if(!expression) { printf("Assertion failed: in %s at line %d: %s\n", FUNCTION_NAME, __LINE__, message); AssertBreak(); }
#define DebugLog(message) printf("DebugLog: %s\n", message);
#define ThrowNotImplementedFunction() printf("%s function is not implemented yet!\n", FUNCTION_NAME); AssertBreak();

//~ Typedefs
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t  u8;
typedef int64_t  i64;
typedef int32_t  i32;
typedef int16_t  i16;
typedef int8_t   i8;
typedef int64_t  b64;
typedef int32_t  b32;
typedef int16_t  b16;
typedef int8_t   b8;
typedef double   f64;
typedef float    f32;

//~ Random
internal void SeedRandom();
internal f32 RandomF32(f32 min, f32 max);

//~ Custom String class
typedef struct String String;
struct String
{
    u8* str;
    u64 size;
};

typedef enum MatchType MatchType;
enum MatchType
{
    MatchType_None,
    MatchType_NoCaseCheck
};

internal char CharToUpper(char c);
internal char CharToLower(char c);
internal b32 CharIsAlpha(char c);
internal b32 CharIsDigit(char c);
internal b32 CharIsSymbol(char c);
internal String StringInit(char* cstr);
#define String(...) StringInit(__VA_ARGS__)
internal void PrintString(String* str);
internal b32 MatchString(String a, String b, MatchType flags);

#define CStringLength (u32)strlen
#define CharIsSpace(c) ((c) <= 32)
#define StringCopy                 strcpy
#define StringCopyN                strncpy
#define CalculateCStringLength(s)  ((u32)strlen(s))
#define CStringToI32(s)            ((i32)atoi(s))
#define CStringToI16(s)            ((i16)atoi(s))
#define CStringToF32(s)            ((f32)atof(s))

#endif //BASE_LAYER_H
