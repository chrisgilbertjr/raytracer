
#include "Samplers\MultiJittered.h"

MultiJittered::MultiJittered()
    : Sampler()
{
    GenerateSamples();
}


MultiJittered::MultiJittered(const int sampleCount)
    : Sampler(sampleCount)
{
    GenerateSamples();
}


MultiJittered::MultiJittered(const int sampleCount, const int setCount)
    : Sampler(sampleCount, setCount)
{
    GenerateSamples();
}


MultiJittered::MultiJittered(const MultiJittered& jittered)
    : Sampler(jittered)
{}


MultiJittered::~MultiJittered() {}


MultiJittered&
MultiJittered::operator=(MultiJittered jittered)
{
    Sampler::operator=(jittered);
    return *this;
}



Sampler*
MultiJittered::Clone() const
{
    return static_cast<Sampler*>(new MultiJittered(*this));
}


void
MultiJittered::GenerateSamples()
{
    int s = (int)sqrtf((float)m_sampleCount);
    float subcellWidth = 1.f / ((float)m_sampleCount);

    Vector point(0.f);

    for (int i = 0; i < m_sampleCount * m_setCount; ++i)
    {
        m_samples.Push(point);
    }

    for (int c = 0; c < m_setCount; ++c)
    {
        for (int i = 0; i < s; ++i)
        {
        }
    }
}