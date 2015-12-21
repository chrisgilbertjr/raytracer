
#include "Samplers\NRooks.h"


NRooks::NRooks()
    : Sampler()
{
    GenerateSamples();
}


NRooks::NRooks(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}


NRooks::NRooks(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}


NRooks::NRooks(const NRooks& nrooks)
    : Sampler(nrooks)
{}


NRooks::~NRooks() {}


NRooks& 
NRooks::operator=(NRooks nrooks)
{
    Sampler::operator=(nrooks);
    return *this;
}



Sampler* 
NRooks::Clone() const
{
    return static_cast<Sampler*>(new NRooks(*this));
}


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