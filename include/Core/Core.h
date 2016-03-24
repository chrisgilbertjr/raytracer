
#ifndef CORE_H
#define CORE_H

#include <assert.h>
#include <stdio.h>
#include <memory>

/// @defgroup Core Core
/// @{

/// lets use single precision floating points for now...
#define SINGLE_PRECISION
#define RELEASE

/// real are typedef floating point values
#ifdef SINGLE_PRECISION
    typedef float real; /// use floats
#elif DOUBLE_PRECISION
    typedef double real; /// use doubles
#endif

/// magic numbers...
#define EPSILON 1e-5f

/// random seed flag
extern bool g_seeded;

/// shadow epsilon
extern real shadowEpsilon;

/// init random seed
void InitializeRandomSeed();

/// random int betweem [0, RAND_MAX]
int RandInt();

/// random int betweem [0, max]
int RandInt(int max);

/// random int between [start, end]
int RandInt(int start, int end);

/// random real between [0, RAND_MAX]
real RandReal();

/// random real between [min, max]
real RandReal(real min, real max);

/// default swap
template <typename T>
inline void
Swap(T& lhs, T& rhs)
{
    T tmp(lhs);
    lhs = rhs;
    rhs = tmp;
}

/// default clone
template <typename T>
inline T*
Clone(const T& obj)
{
    return new T(obj);
}

/// some debug macros to make things easier
#ifdef RELEASE
    #define Log(...)
    #define LogString(string)
    #define LogFloat(value)
    #define LogInt(value)
    #define Error(...)
    #define Assert(condition)
#elif
    #define Log(...) fprintf(stdout, ...)
    #define LogString(string) Log("%s\n", string)
    #define LogFloat(value) Log("%.7f\n", value)
    #define LogInt(value) Log("%d\n", value)
    #define Error(...) fprintf(sterr, ...); assert(false)
    #define Assert(condition) if (!condition) { fprintf(stderr, "file: %s (%s)\n", __FILE__, __LINE__); assert(false); }
#endif

/// @}

#endif