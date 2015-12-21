
#include "Samplers\Simple.h"

Simple::Simple()
    : Sampler()
{
    GenerateSamples();
}

Simple::Simple(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}

Simple::Simple(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}

Simple::Simple(const Simple& simple)
    : Sampler(simple)
{}

Simple::~Simple() {}

Simple& 
Simple::operator=(Simple simple)
{
    Sampler::operator=(simple);
    return *this;
}

Sampler* 
Simple::Clone() const
{
    return static_cast<Sampler*>(new Simple(*this));
}

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