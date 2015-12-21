
#ifndef RAND_H
#define RAND_H

#include "Core\Core.h"
#include <stdlib.h>
#include <time.h>

bool g_seeded = false;

void 
InitializeRandomSeed()
{
    srand(time(NULL));
}

int 
RandInt()
{
    return rand();
}

int 
RandInt(int max)
{
    return RandInt(0, max);
}

int 
RandInt(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

real 
RandReal()
{
    return (real)(RandInt() * (1.0f/RAND_MAX));
}

#endif