
#ifndef SAMPLER_H
#define SAMPLER_H

#include "Core\MathUtils.h"
#include "Core\Array.h"

class Sampler
{
private:
    Vector DoSample(const Array<Vector>& samples);

protected:
    Array<Vector> m_samples;
    Array<Vector> m_diskSamples;
    Array<Vector> m_hemiSamples;
    Array<Vector> m_sphereSamples;
    Array<int>    m_shuffledIndices;
    unsigned long m_count;
    int m_sampleCount;
    int m_setCount;
    int m_jump;

public:
    Sampler();

    Sampler(const int sampleCount);

    Sampler(const int sampleCount, const int setCount);

    Sampler(const Sampler& sampler);

    virtual ~Sampler();

    Sampler& operator=(Sampler sampler);

    virtual Sampler* Clone() const;

    virtual void GenerateSamples();

    void ShuffleSamples();

    void ShuffleCoordsX();

    void ShuffleCoordsY();

    void SetupShuffledIndices();

    void MapSamplesToUnitDisk();

    void MapSamplesToHemisphere();

    void MapSamplesToSphere();
    
    Vector SampleUnitSquare();

    Vector SampleUnitDisk();

    Vector SampleHemisphere();

    Vector SampleSphere();

    inline int GetSampleCount() const { return m_sampleCount; }
};

#endif