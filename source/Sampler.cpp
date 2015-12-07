
#include "Samplers\Sampler.h"

Sampler::Sampler()
    : m_samples()
    , m_shuffledIndices()
    , m_count(0)
    , m_sampleCount(1)
    , m_setCount(0)
    , m_jump(0)
{
}

Sampler::Sampler(int sampleCount)
    : m_samples()
    , m_shuffledIndices()
    , m_count(0)
    , m_sampleCount(sampleCount)
    , m_setCount(0)
    , m_jump(0)
{
}

Sampler::~Sampler()
{
}

void 
Sampler::SetupShuffledIndices()
{
}

void 
Sampler::ShuffleSamples()
{
}

Vector 
Sampler::SampleUnitSquare()
{
    return Vector(0);
}
