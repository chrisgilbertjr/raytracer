
#include "Samplers\Simple.h"

/// --------------------------------------------------------------------------- constructor

Simple::Simple()
    : Sampler()
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- constructor

Simple::Simple(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- constructor

Simple::Simple(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- copy constructor

Simple::Simple(const Simple& simple)
    : Sampler(simple)
{}

/// --------------------------------------------------------------------------- destructor

Simple::~Simple() {}

/// --------------------------------------------------------------------------- copy assignment operator

Simple& 
Simple::operator=(Simple simple)
{
    /// copy and swap
    Sampler::operator=(simple);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Sampler* 
Simple::Clone() const
{
    return static_cast<Sampler*>(new Simple(*this));
}

/// --------------------------------------------------------------------------- GenerateSamples

void
Simple::GenerateSamples()
{
    int n = (int)Sqrt((real)m_sampleCount);

    for (int k = 0; k < m_setCount; ++k)
    {
        for (int i = 0; i < n; ++i)
    	{
            for (int j = 0; j < n; ++j)
            {
                m_samples.Push(Vector((j + 0.5f)/n, (i + 0.5f) / n, 0.f));
            }
    	}
    }
}

/// --------------------------------------------------------------------------- EOF