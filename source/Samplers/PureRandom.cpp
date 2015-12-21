
#include "Samplers\PureRandom.h"

PureRandom::PureRandom()
    : Sampler()
{
    GenerateSamples();
}

PureRandom::PureRandom(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}

PureRandom::PureRandom(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}

PureRandom::PureRandom(const PureRandom& random)
    : Sampler(random)
{}

PureRandom::~PureRandom() {}

PureRandom&
PureRandom::operator=(PureRandom random)
{
    Sampler::operator=(random);
    return *this;
}

Sampler*
PureRandom::Clone() const
{
    return static_cast<Sampler*>(new PureRandom(*this));
}

void
PureRandom::GenerateSamples()
{
    for (int i = 0; i < m_setCount; ++i)
    {
        for (int j = 0; j < m_sampleCount; ++j)
        {
            m_samples.Push(Vector(RandReal(), RandReal(), 0.f));
        }
    }
}