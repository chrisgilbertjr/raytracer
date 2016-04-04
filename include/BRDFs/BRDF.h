
#ifndef BRDF_H
#define BRDF_H

#include "ShadeRecord.h"

/// @defgroup BRDF BRDF
/// @{

/// forward declaration
class Sampler;

/// global sampler for path tracing
extern Sampler* g_pathSampler;

/// bidirectional reflectance distruction functions
/// base class for all lighting equations
class BRDF
{
protected:
    Sampler* m_sampler; /// sampler used for area lights

public:
    /// constructor
    BRDF();

    /// copy constructor
    BRDF(const BRDF& brdf);

    /// destructor
    virtual ~BRDF();

    /// copy assignment operator
    BRDF& operator=(BRDF brdf);

    /// deep copy an object
    virtual BRDF* Clone() const;

    /// set the BRDF's sampler
    void SetSampler(Sampler* sampler);

    /// evaluate f given an incoming and eye vector 
    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    /// sample f given an eye vector 
    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo) const;

    /// evaluate rho given an eye vector 
    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    /// create and initialize a simple sampler if one hasnt been created
    void InitSampler();
};

/// @}

#endif