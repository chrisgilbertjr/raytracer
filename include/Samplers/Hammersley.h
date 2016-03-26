
#ifndef HAMMERSLEY_H
#define HAMMERSLEY_H

#include "Samplers\Sampler.h"

/// @defgroup Hammersley Hammersley
/// @{

/// hammersley sampling
class Hammersley : public Sampler
{
public:
    /// constructor
    Hammersley();

    /// constructor
    Hammersley(const int sampleCount);

    /// constructor
    Hammersley(const int sampleCount, const int setCount);

    /// copy constructor
    Hammersley(const Hammersley& hammersley);

    /// destructor
    virtual ~Hammersley();

    /// copy assignment operator
    Hammersley& operator=(Hammersley hammersley);

    /// deep copy of this object
    virtual Sampler* Clone() const;

    /// generate the samples
    virtual void GenerateSamples();
};

/// @}

#endif