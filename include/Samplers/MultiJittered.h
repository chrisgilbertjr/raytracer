
#ifndef MULTI_JITTERED_H
#define MULTI_JITTERED_H

#include "Samplers\Sampler.h"

class MultiJittered : public Sampler
{
    virtual void GenerateSamples();
};

#endif