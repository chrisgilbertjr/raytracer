
#ifndef PERFECT_SPECULAR_H
#define PERFECT_SPECULAR_H

#include "BRDF.h"

/// @defgroup PerfectSpecular PerfectSpecular
/// @{

/// perfect specular brdf
class PerfectSpecular : public BRDF
{
private:
    real  m_intensity; /// color intensity
    Color m_color;     /// specular color

    /// compute the perfect specular color
    Color Hue() const;

public:
    /// constructor
    PerfectSpecular();

    /// copy constructor
    PerfectSpecular(const PerfectSpecular& brdf);

    /// destructor
    virtual ~PerfectSpecular();

    /// copy assignment operator
    PerfectSpecular& operator=(PerfectSpecular brdf);

    /// deep copy the object
    virtual BRDF* Clone() const;

    /// evaluate f given an incoming and eye vector 
    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    /// sample f given an eye vector 
    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo) const;

    /// sample f given an eye vector for area lights
    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const;

    /// evaluate rho given an eye vector 
    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    /// set the intensity
    inline void SetKr(const real kd)   { m_intensity = kd; }

    /// set the color
    inline void SetCr(const Color& cd) { m_color = cd; }

    /// get the intensity
    inline real  GetKr() { return m_intensity; }

    /// get the color
    inline Color GetCr() { return m_color; }
};

/// @}

#endif