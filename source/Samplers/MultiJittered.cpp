
#include "Samplers\MultiJittered.h"
#include <vector>
#include <iostream>

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

static int _RandInt()
{
    return rand();
}

static real
_RandReal()
{
    return ((real)_RandInt()) / RAND_MAX;
}

static real
_RandReal(int l, float h)
{
    return (_RandReal() * (h - l) + l);
}

static int
_RandInt(int l, int h)
{
    return ((int) (_RandReal(0, h - l + 1) + 1));
}


void
MultiJittered::GenerateSamples()
{
    // num_samples needs to be a perfect square
    int num_samples = m_sampleCount;
    int num_sets = m_setCount;

    int n = (int)sqrt((float)num_samples);
    float subcell_width = 1.0 / ((float)num_samples);

    std::vector<Vector> samples;

    Vector fill_point;
    for (int j = 0; j < num_samples * num_sets; j++)
        samples.push_back(fill_point);

    // distribute points in the initial patterns

    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                samples[i * n + j + p * num_samples].x = (i * n + j) * subcell_width + _RandReal(0, subcell_width);
                samples[i * n + j + p * num_samples].y = (j * n + i) * subcell_width + _RandReal(0, subcell_width);
            }

    // shuffle x coordinates

    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int k = _RandInt(j, n - 1);
                float t = samples[i * n + j + p * num_samples].x;
                samples[i * n + j + p * num_samples].x = samples[i * n + k + p * num_samples].x;
                samples[i * n + k + p * num_samples].x = t;
            }

    // shuffle y coordinates

    for (int p = 0; p < num_sets; p++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int k = _RandInt(j, n - 1);
                float t = samples[j * n + i + p * num_samples].y;
                samples[j * n + i + p * num_samples].y = samples[k * n + i + p * num_samples].y;
                samples[k * n + i + p * num_samples].y = t;
            }

    for (int i = 0; i < samples.size(); ++i)
    {
        m_samples.Push(samples[i]);
    }
}

Vector 
MultiJittered::SampleUnitSquare()
{
    m_count++;
	if (m_count % m_sampleCount == 0)
        m_count = 0;

	return m_samples[m_count];
}

Vector 
MultiJittered::SampleHemisphere()
{
    if ((m_count % m_sampleCount) == 0)
    {
        /// compute random jump offset
        m_jump = (RandInt() % m_setCount) * m_sampleCount;
    }

    /// get the shuffled index
    int shuffle = m_shuffledIndices[m_jump + m_count++ % m_sampleCount];

    /// return the jump offset shuffled index
    return m_hemiSamples[m_jump + shuffle];
}