
#include "Samplers\Hammersley.h"


Hammersley::Hammersley()
    : Sampler()
{
    GenerateSamples();
}


Hammersley::Hammersley(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}


Hammersley::Hammersley(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}


Hammersley::Hammersley(const Hammersley& hammersley)
    : Sampler(hammersley)
{}


Hammersley::~Hammersley() {}


Hammersley&
Hammersley::operator=(Hammersley hammersley)
{
    Sampler::operator=(hammersley);
    return *this;
}



Sampler*
Hammersley::Clone() const
{
    return static_cast<Sampler*>(new Hammersley(*this));
}


/// compute Phi, = SUM(j=0, n) a_j*(i)*2^(-j-1)
/// exp... a0(i)(1/2) + a1(i)(1/4) + a2(i)(1/8)... etc
static real
Phi(int i)
{
    real x = 0.0f;
    real f = 0.5f;

    while (i)
    {
        x += f * (real) (i % 2);
        i /= 2;
        f *= 0.5f;
    }

    return x;
}


void
Hammersley::GenerateSamples()
{
    for (int i = 0; i < m_setCount; ++i)
    {
        for (int j = 0; j < m_sampleCount; ++j)
        {
            Vector sample((real)j/(real)m_sampleCount, Phi(j), 0.f);
            m_samples.Push(sample);
        }
    }
}