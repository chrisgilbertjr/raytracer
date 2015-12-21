
#ifndef MULTI_JITTERED_H
#define MULTI_JITTERED_H

#include "Samplers\Sampler.h"

class MultiJittered : public Sampler
{
public:
    MultiJittered();

    MultiJittered(const int sampleCount);

    MultiJittered(const int sampleCount, const int setCount);

    MultiJittered(const MultiJittered& jittered);

    virtual ~MultiJittered();

    MultiJittered& operator=(MultiJittered jittered);

    virtual Sampler* Clone() const;

    virtual void GenerateSamples();
};

#endif