
#include "Samplers\Sampler.h"

int g_samples = 1;

Sampler::Sampler()
    : m_samples(83)
    , m_diskSamples(0)
    , m_hemiSamples(0)
    , m_sphereSamples(0)
    , m_shuffledIndices(0)
    , m_count(0)
    , m_sampleCount(1)
    , m_setCount(83)
    , m_jump(0)
{
    this->SetupShuffledIndices();
}

Sampler::Sampler(int sampleCount)
    : m_samples(sampleCount * 83)
    , m_diskSamples(0)
    , m_hemiSamples(0)
    , m_sphereSamples(0)
    , m_shuffledIndices(0)
    , m_count(0)
    , m_sampleCount(sampleCount)
    , m_setCount(83)
    , m_jump(0)
{
    this->SetupShuffledIndices();
}

Sampler::Sampler(const int sampleCount, const int setCount)
    : m_samples(sampleCount * setCount)
    , m_diskSamples(0)
    , m_hemiSamples(0)
    , m_sphereSamples(0)
    , m_shuffledIndices(0)
    , m_count(0)
    , m_sampleCount(sampleCount)
    , m_setCount(setCount)
    , m_jump(0)
{
    this->SetupShuffledIndices();
}

Sampler::Sampler(const Sampler& sampler)
    : m_samples(sampler.m_samples)
    , m_diskSamples(sampler.m_diskSamples)
    , m_hemiSamples(sampler.m_hemiSamples)
    , m_sphereSamples(sampler.m_sphereSamples)
    , m_shuffledIndices(sampler.m_shuffledIndices)
    , m_count(sampler.m_count)
    , m_sampleCount(sampler.m_sampleCount)
    , m_setCount(sampler.m_setCount)
    , m_jump(sampler.m_jump)
{}

Sampler::~Sampler() {}

Sampler& 
Sampler::operator=(Sampler sampler)
{
    Swap<Array<Vector> >(m_samples, sampler.m_samples);
    Swap<Array<Vector> >(m_diskSamples, sampler.m_diskSamples);
    Swap<Array<Vector> >(m_hemiSamples, sampler.m_hemiSamples);
    Swap<Array<Vector> >(m_sphereSamples, sampler.m_sphereSamples);
    Swap<Array<int> >(m_shuffledIndices, sampler.m_shuffledIndices);
    Swap<unsigned long>(m_count, sampler.m_count);
    Swap<int>(m_sampleCount, sampler.m_sampleCount);
    Swap<int>(m_setCount, sampler.m_setCount);
    Swap<int>(m_jump, sampler.m_jump);
    return *this;
}

Sampler* 
Sampler::Clone() const
{
    /// abstract class
    /// i am not using pure virtual functions so i can use the copy and swap idiom
    Assert(false);
    return NULL;
}

void 
Sampler::GenerateSamples()
{
    /// abstract class
    /// i am not using pure virtual functions so i can use the copy and swap idiom
    Assert(false);
}

void 
Sampler::ShuffleCoordsX()
{
    for (int i = 0; i < m_setCount; ++i)
    {
        for (int j = 0; j < m_setCount; ++j)
    	{
            int set = i * m_sampleCount;
            int index = RandInt() % m_sampleCount + set;
            real tmp = m_samples[j + set + 1].x;

            m_samples[i + set + 1].x = m_samples[index].x;
            m_samples[index].x = tmp;
    	}
    }
}

void 
Sampler::ShuffleCoordsY()
{
    for (int i = 0; i < m_setCount; ++i)
    {
        for (int j = 0; j < m_setCount; ++j)
    	{
            int set = i * m_sampleCount;
            int index = RandInt() % m_sampleCount + set;
            real tmp = m_samples[j + set + 1].y;

            m_samples[i + set + 1].y = m_samples[index].y;
            m_samples[index].y = tmp;
    	}
    }
}

void 
Sampler::SetupShuffledIndices()
{
    m_shuffledIndices.Resize(m_sampleCount * m_setCount);

    /// loop through the indices, populate then, and shuffle each set
    for (int i = 0; i < m_setCount; ++i)
    {
        for (int j = 0; j < m_sampleCount; ++j)
        {
            /// populate the indices
            m_shuffledIndices.Push(j);
        }
        
        /// get start and end indices of array to shuffle
        int start = i * m_sampleCount;
        int end   = start + m_sampleCount - 1;

        /// shuffle the array between [start, end]. shuffles one set at a time
        ShuffleArray(m_shuffledIndices, start, end);
    }
}

void 
Sampler::MapSamplesToUnitDisk()
{
    /// @TODO!
}

void 
Sampler::MapSamplesToHemisphere()
{
    int size = m_samples.GetSize();
    float EXP = 1.0f;

    for (int i = 0; i < size; ++i)
    {
        float cos_phi = cosf(2.f * Pi * m_samples[i].x);
        float sin_phi = sinf(2.f * Pi * m_samples[i].x);
        float cos_theta = pow((1.f - m_samples[i].y), 1.f / (EXP + 1.f));
        float sin_theta = sqrt(1.f - cos_theta * cos_theta);

        float pu = sin_theta * cos_phi;
        float pv = sin_theta * sin_phi;
        float pw = cos_theta;

        m_hemiSamples.Push(Vector(pu, pv, pw));
    }
}

void 
Sampler::MapSamplesToSphere()
{
    float r, r1, r2, x, y, z, phi;

    for (int i = 0; i < m_sampleCount * m_setCount; ++i)
    {
        r1 = m_samples[i].x;
        r2 = m_samples[i].y;
        z = 1.f - 2.f * r1;
        r = sqrtf(1.f - z * z);
        phi = Pi * 2.f * r2;
        x = r * cosf(phi);
        y = r * sinf(phi);

        m_sphereSamples.Push(Vector(x, y, z));
    }
}

Vector 
Sampler::DoSample(const Array<Vector>& samples)
{
    if ((m_count % m_sampleCount) == 0)
    {
        /// compute random jump offset
        m_jump = (RandInt() % m_setCount) * m_sampleCount;
    }

    /// get the shuffled index
    int shuffle = m_shuffledIndices[m_jump + m_count++ % m_sampleCount];

    /// return the jump offset shuffled index
    return samples[m_jump + shuffle];
}

Vector 
Sampler::SampleUnitSquare()
{
    return DoSample(m_samples);
}

Vector 
Sampler::SampleUnitDisk()
{
    return DoSample(m_diskSamples);
}

Vector 
Sampler::SampleHemisphere()
{
    return DoSample(m_hemiSamples);
}

Vector 
Sampler::SampleSphere()
{
    return DoSample(m_sphereSamples);
}