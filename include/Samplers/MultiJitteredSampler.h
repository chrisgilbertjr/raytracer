
#ifndef MULTI_JITTERED_SAMPLER_H
#define MULTI_JITTERED_SAMPLER_H

#include "Samplers\Sampler.h"

class MultiJitteredSampler : public Sampler
{
    virtual void GenerateSamples();
};

#endif