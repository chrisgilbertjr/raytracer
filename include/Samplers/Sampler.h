
#ifndef SAMPLER_H
#define SAMPLER_H

#include "Core\MathUtils.h"
#include "Core\Array.h"

class Sampler
{
protected:
    Array<Vector> m_samples;
    Array<int> m_shuffledIndices;
    unsigned long m_count;
    int m_sampleCount;
    int m_setCount;
    int m_jump;

    Sampler();

    Sampler(int sampleCount);

public:
    virtual ~Sampler();

    virtual void GenerateSamples() = 0;

    void SetupShuffledIndices();

    void ShuffleSamples();
    
    Vector SampleUnitSquare();
};

#endif