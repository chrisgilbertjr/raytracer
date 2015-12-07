
#ifndef CORE_H
#define CORE_H

#include <assert.h>
#include <stdio.h>
#include <memory>

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

#endif