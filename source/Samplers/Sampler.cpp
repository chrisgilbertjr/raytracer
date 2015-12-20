
#include "Samplers\Sampler.h"

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
Sampler::ShuffleSamples()
{
}

void Sampler::
ShuffleCoordsX()
{
}

void 
Sampler::ShuffleCoordsY()
{
}

void 
Sampler::SetupShuffledIndices()
{
}

void 
Sampler::MapSamplesToUnitDisk()
{
}

void 
Sampler::MapSamplesToHemisphere()
{
}

void 
Sampler::MapSamplesToSphere()
{
}

Vector 
Sampler::SampleUnitSquare()
{
}

Vector 
Sampler::SampleUnitDisk()
{
}

Vector 
Sampler::SampleHemisphere()
{
}

Vector 
Sampler::SampleSphere()
{
}