
#ifndef NROOKS_H
#define NROOKS_H

#include "Samplers\Sampler.h"

/// @defgroup NRooks Nrooks
/// @{

/// NRooks sampling
class NRooks : public Sampler
{
public:
    /// constructor
    NRooks();

    /// constructor
    NRooks(const int sampleCount);

    /// constructor
    NRooks(const int sampleCount, const int setCount);

    /// copy constructor
    NRooks(const NRooks& nrooks);

    /// destructor
    virtual ~NRooks();

    /// copy assignment operator
    NRooks& operator=(NRooks nrooks);

    /// deep copy this object
    virtual Sampler* Clone() const;

    /// generate the samples
    virtual void GenerateSamples();
};

/// @}

#endif