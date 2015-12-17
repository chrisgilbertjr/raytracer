
#ifndef RANDOM_H
#define RANDOM_H

#include "Samplers\Sampler.h"

class PureRandom : public Sampler
{
    virtual void GenerateSamples();
};

#endif