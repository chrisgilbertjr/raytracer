
#include "Samplers\PureRandom.h"

/// --------------------------------------------------------------------------- constructor

PureRandom::PureRandom()
    : Sampler()
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- constructor

PureRandom::PureRandom(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- constructor

PureRandom::PureRandom(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- copy assignment operator

PureRandom::PureRandom(const PureRandom& random)
    : Sampler(random)
{}

/// --------------------------------------------------------------------------- destructor

PureRandom::~PureRandom() {}

/// --------------------------------------------------------------------------- copy assignment operator

PureRandom&
PureRandom::operator=(PureRandom random)
{
    Sampler::operator=(random);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Sampler*
PureRandom::Clone() const
{
    return static_cast<Sampler*>(new PureRandom(*this));
}

/// --------------------------------------------------------------------------- GenerateSamples

void
PureRandom::GenerateSamples()
{
    for (int i = 0; i < m_setCount; ++i)
    {
        for (int j = 0; j < m_sampleCount; ++j)
        {
            m_samples.Push(Vector(RandReal(0, 1.f), RandReal(0, 1.f), 0.f));
        }
    }
}

/// --------------------------------------------------------------------------- EOF