
#ifndef SIMPLE_H
#define SIMPLE_H

#include "Samplers\Sampler.h"

class Simple : public Sampler
{
public:
    Simple();

    Simple(const int sampleCount);

    Simple(const int sampleCount, const int setCount);

    Simple(const Simple& simple);

    virtual ~Simple();

    Simple& operator=(Simple simple);

    virtual Sampler* Clone() const;

    virtual void GenerateSamples();
};

#endif