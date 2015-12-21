
#ifndef RANDOM_H
#define RANDOM_H

#include "Samplers\Sampler.h"

class PureRandom : public Sampler
{
public:
    PureRandom();

    PureRandom(const int sampleCount);

    PureRandom(const int sampleCount, const int setCount);

    PureRandom(const PureRandom& random);

    virtual ~PureRandom();

    PureRandom& operator=(PureRandom random);

    virtual Sampler* Clone() const;

    virtual void GenerateSamples();
};

#endif