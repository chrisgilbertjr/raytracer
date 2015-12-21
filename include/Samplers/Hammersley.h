
#ifndef HAMMERSLEY_H
#define HAMMERSLEY_H

#include "Samplers\Sampler.h"

class Hammersley : public Sampler
{
public:
    Hammersley();

    Hammersley(const int sampleCount);

    Hammersley(const int sampleCount, const int setCount);

    Hammersley(const Hammersley& hammersley);

    virtual ~Hammersley();

    Hammersley& operator=(Hammersley hammersley);

    virtual Sampler* Clone() const;

    virtual void GenerateSamples();
};
#endif