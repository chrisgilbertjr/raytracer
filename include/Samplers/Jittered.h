
#ifndef JITTERED_H
#define JITTERED_H

#include "Samplers\Sampler.h"

class Jittered : public Sampler
{
public:
    Jittered();

    Jittered(const int sampleCount);

    Jittered(const int sampleCount, const int setCount);

    Jittered(const Jittered& jittered);

    virtual ~Jittered();

    Jittered& operator=(Jittered jittered);

    virtual Sampler* Clone() const;

    virtual void GenerateSamples();
};

#endif