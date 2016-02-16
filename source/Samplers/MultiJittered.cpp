
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

    /// init the samples with dummmy points
    for (int i = 0; i < m_sampleCount * m_setCount; ++i)
    {
        m_samples.Push(point);
    }

    /// initial points
    for (int c = 0; c < m_setCount; ++c)
    {
        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j < s; ++j)
            {
                real t = RandReal(0, subcellWidth);
                int i0 = i * s + j;
                int index = i0+ c * m_sampleCount;
                real jitter = i0 * subcellWidth;
                m_samples[index].Set(jitter + RandReal(0, subcellWidth), jitter + RandReal(0, subcellWidth), 0.f);
            }
        }
    }

    /// shuffle x coords
    for (int c = 0; c < m_setCount; ++c)
    {
        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j < s; ++j)
            {
                int k = RandInt(j, s-1);
                int ij = i * s + j + c * m_sampleCount;
                int ik = i * s + k + c * m_sampleCount;
                real t = m_samples[ij].x;
                m_samples[ij].x = m_samples[ik].x;
                m_samples[ik].x = t;
            }
        }
    }

    /// shuffle y coords
    for (int c = 0; c < m_setCount; ++c)
    {
        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j < s; ++j)
            {
                int k = RandInt(j, s-1);
                int ij = i * s + j + c * m_sampleCount;
                int ik = i * s + k + c * m_sampleCount;
                real t = m_samples[ij].y;
                m_samples[ij].y = m_samples[ik].y;
                m_samples[ik].y = t;
            }
        }
    }
}