
#ifndef SAMPLER_H
#define SAMPLER_H

#include "Core\MathUtils.h"
#include "Core\Array.h"

/// @defgroup Sampler Sample
/// @{

extern int g_samples;

/// base class for all samplers
class Sampler
{
private:
    /// so the sample given an array of samples
    Vector DoSample(const Array<Vector>& samples);

protected:
    Array<Vector> m_samples;         /// unit square samples array
    Array<Vector> m_diskSamples;     /// samples on a disk
    Array<Vector> m_hemiSamples;     /// samples on a hemisphere
    Array<Vector> m_sphereSamples;   /// samples on a unit sphere
    Array<int>    m_shuffledIndices; /// shuffled indices array
    unsigned long m_count;           /// number of current sample
    int m_sampleCount;               /// number of samples
    int m_setCount;                  /// number of sample sets
    int m_jump;                      /// jump between sets

public:
    /// constructor
    Sampler();

    /// constructor
    Sampler(const int sampleCount);

    /// constructor
    Sampler(const int sampleCount, const int setCount);

    /// copy constructor
    Sampler(const Sampler& sampler);

    /// destructor
    virtual ~Sampler();

    /// copy assignment operator
    Sampler& operator=(Sampler sampler);

    /// deep copy this object
    virtual Sampler* Clone() const;

    /// generate the samples
    virtual void GenerateSamples();

    /// shuffle the samples
    void ShuffleSamples();

    /// shuffle the x samples
    void ShuffleCoordsX();

    /// shuffle the y samples
    void ShuffleCoordsY();

    /// setup the shuffled indices
    void SetupShuffledIndices();

    /// map the samples to a unit disk
    void MapSamplesToUnitDisk();

    /// map the samples to a unit hemisphere
    void MapSamplesToHemisphere();

    /// map the samples to a unit sphere
    void MapSamplesToSphere();
    
    /// samples the unit square 
    Vector SampleUnitSquare();

    /// samples the unit disk
    Vector SampleUnitDisk();

    /// samples the unit hemisphere
    Vector SampleHemisphere();

    /// samples the unit sphere
    Vector SampleSphere();

    /// get the sample count
    int GetSampleCount() const;
};

/// --------------------------------------------------------------------------- GetSampleCount

inline int 
Sampler::GetSampleCount() const
{
    return m_sampleCount;
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif