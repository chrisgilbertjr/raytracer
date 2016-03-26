
#ifndef RANDOM_H
#define RANDOM_H

#include "Samplers\Sampler.h"

/// @defgroup PureRandom PureRandom
/// @{

/// pure random sampling
class PureRandom : public Sampler
{
public:
    /// constructor
    PureRandom();

    /// constructor
    PureRandom(const int sampleCount);

    /// constructor
    PureRandom(const int sampleCount, const int setCount);

    /// copy constructor
    PureRandom(const PureRandom& random);

    /// destructor
    virtual ~PureRandom();

    /// copy assignment operator
    PureRandom& operator=(PureRandom random);

    /// deep copy of this object
    virtual Sampler* Clone() const;

    /// generate the samples
    virtual void GenerateSamples();
};

/// @}

#endif