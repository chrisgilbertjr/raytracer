
#ifndef SIMPLE_H
#define SIMPLE_H

#include "Samplers\Sampler.h"

/// @defgroup Simple Simple
/// @{

/// simple sampler
class Simple : public Sampler
{
public:
    /// constructor
    Simple();

    /// constructor
    Simple(const int sampleCount);

    /// constructor
    Simple(const int sampleCount, const int setCount);

    /// copy constructor
    Simple(const Simple& simple);

    /// destructor
    virtual ~Simple();

    /// copy assignment operator
    Simple& operator=(Simple simple);

    /// deep copy of the object
    virtual Sampler* Clone() const;

    /// generate samples
    virtual void GenerateSamples();
};

/// @}

#endif