
#ifndef JITTERED_H
#define JITTERED_H

#include "Samplers\Sampler.h"

/// @defgroup Jittered Jitted
/// @{

/// Jittered sampling
class Jittered : public Sampler
{
public:
    /// constructor
    Jittered();

    /// constructor
    Jittered(const int sampleCount);

    /// constructor
    Jittered(const int sampleCount, const int setCount);

    /// copy constructor
    Jittered(const Jittered& jittered);

    /// destructor
    virtual ~Jittered();

    /// copy assignment operator
    Jittered& operator=(Jittered jittered);

    /// deep copy of this object
    virtual Sampler* Clone() const;

    /// generate the samples
    virtual void GenerateSamples();
};

/// @}

#endif