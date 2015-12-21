
#include "Samplers\Jittered.h"

Jittered::Jittered()
    : Sampler()
{
    GenerateSamples();
}


Jittered::Jittered(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}


Jittered::Jittered(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}


Jittered::Jittered(const Jittered& jittered)
    : Sampler(jittered)
{}


Jittered::~Jittered() {}


Jittered&
Jittered::operator=(Jittered jittered)
{
    Sampler::operator=(jittered);
    return *this;
}



Sampler*
Jittered::Clone() const
{
    return static_cast<Sampler*>(new Jittered(*this));
}


void
Jittered::GenerateSamples()
{
    int n = (int)Sqrt((real)m_sampleCount);

    for (int k = 0; k < m_setCount; ++k)
    {
        for (int i = 0; i < n; ++i)
    	{
            for (int j = 0; j < n; ++j)
    		{
                Vector sample((j+RandReal())/n, (i+RandReal())/n, 0.f);
                m_samples.Push(sample);
    		}
    	}
    }
}