
#ifndef RAND_H
#define RAND_H

#include "Core\Core.h"
#include <stdlib.h>
#include <time.h>

/// rand seed intialized flag
bool g_seeded = false;

/// --------------------------------------------------------------------------- InitializeRandomSeed

void 
InitializeRandomSeed()
{
    srand(time(NULL));
}

/// --------------------------------------------------------------------------- RandInt

int 
RandInt()
{
    return rand();
}

/// --------------------------------------------------------------------------- RandInt

int 
RandInt(int max)
{
    return RandInt(0, max);
}

/// --------------------------------------------------------------------------- RandInt

int 
RandInt(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

/// --------------------------------------------------------------------------- RandReal

real 
RandReal()
{
    return (real)(RandInt() * (1.0f/RAND_MAX));
}

/// --------------------------------------------------------------------------- RandReal

real 
RandReal(real min, real max)
{
    real r = RandReal();
    real d = max - min;
    real num = r * d;
    return min + num;
}

/// --------------------------------------------------------------------------- EOF

#endif