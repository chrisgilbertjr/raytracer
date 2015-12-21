
#ifndef NROOKS_H
#define NROOKS_H

#include "Samplers\Sampler.h"

class NRooks : public Sampler
{
public:
    NRooks();

    NRooks(const int sampleCount);

    NRooks(const int sampleCount, const int setCount);

    NRooks(const NRooks& nrooks);

    virtual ~NRooks();

    NRooks& operator=(NRooks nrooks);

    virtual Sampler* Clone() const;

    virtual void GenerateSamples();
};

#endif