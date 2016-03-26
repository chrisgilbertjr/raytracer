
#ifndef MULTI_JITTERED_H
#define MULTI_JITTERED_H

#include "Samplers\Sampler.h"

/// @defgroup MultiJittered MultiJittered
/// @{

/// multi-jittered sampling
class MultiJittered : public Sampler
{
public:
    /// constructor
    MultiJittered();

    /// constructor
    MultiJittered(const int sampleCount);

    /// constructor
    MultiJittered(const int sampleCount, const int setCount);

    /// copy constructor
    MultiJittered(const MultiJittered& jittered);

    /// destructor
    virtual ~MultiJittered();

    /// copy assignment operator
    MultiJittered& operator=(MultiJittered jittered);

    /// deep copy of this object
    virtual Sampler* Clone() const;

    /// generate the samples
    virtual void GenerateSamples();
};

/// @}

#endif