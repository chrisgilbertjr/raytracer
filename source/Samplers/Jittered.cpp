
#include "Samplers\Jittered.h"

/// --------------------------------------------------------------------------- constructor

Jittered::Jittered()
    : Sampler()
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- constructor

Jittered::Jittered(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- constructor

Jittered::Jittered(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}

/// --------------------------------------------------------------------------- copy constructor

Jittered::Jittered(const Jittered& jittered)
    : Sampler(jittered)
{}

/// --------------------------------------------------------------------------- destructor

Jittered::~Jittered() {}

/// --------------------------------------------------------------------------- copy assignment operator

Jittered&
Jittered::operator=(Jittered jittered)
{
    Sampler::operator=(jittered);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Sampler*
Jittered::Clone() const
{
    return static_cast<Sampler*>(new Jittered(*this));
}

/// --------------------------------------------------------------------------- GenerateSamples

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
                Vector sample(((real)j+RandReal())/(real)n, ((real)i+RandReal())/(real)n, 0.f);
                m_samples.Push(sample);
    		}
    	}
    }
}

/// --------------------------------------------------------------------------- EOF