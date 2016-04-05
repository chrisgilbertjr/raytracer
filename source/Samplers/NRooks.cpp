
#include "Samplers\NRooks.h"

/// --------------------------------------------------------------------------- constructor

NRooks::NRooks()
    : Sampler()
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- constructor

NRooks::NRooks(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- constructor

NRooks::NRooks(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- copy constructor

NRooks::NRooks(const NRooks& nrooks)
    : Sampler(nrooks)
{}

/// --------------------------------------------------------------------------- destructor

NRooks::~NRooks() {}

/// --------------------------------------------------------------------------- copy assignment operator

NRooks& 
NRooks::operator=(NRooks nrooks)
{
    Sampler::operator=(nrooks);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Sampler* 
NRooks::Clone() const
{
    return static_cast<Sampler*>(new NRooks(*this));
}

/// --------------------------------------------------------------------------- GenerateSamples

void
NRooks::GenerateSamples()
{
    for (int i = 0; i < m_setCount; ++i)
    {
        for (int j = 0; j < m_sampleCount; ++j)
        {
            Vector sample((j+RandReal())/m_sampleCount, (j+RandReal())/m_sampleCount, 0.f);
            m_samples.Push(sample);
        }
    }

    this->ShuffleCoordsX();
    this->ShuffleCoordsY();
}

/// --------------------------------------------------------------------------- EOF