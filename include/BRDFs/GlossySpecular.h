
#ifndef GLOSSY_SPECULAR_H
#define GLOSSY_SPECULAR_H

#include "BRDF.h"

/// @defgroup GlossySpecular GlosstSpecular
/// @{

/// glossy specular brdf
class GlossySpecular : public BRDF
{
private:
    real  m_exp;       /// hemisphere exp
    real  m_intensity; /// specular intensity
    Color m_color;     /// specular color

    Color Hue() const; /// compute the lights color

public:
    /// constructor
    GlossySpecular();

    /// copy constructor
    GlossySpecular(const GlossySpecular& brdf);

    /// destructor
    virtual ~GlossySpecular();

    // copy assignment operator
    GlossySpecular& operator=(GlossySpecular brdf);

    /// deep copy  of the object
    virtual BRDF* Clone() const;

    /// evaluate f given an incoming and eye vector 
    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    /// sample f given an eye vector 
    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, real& pdf) const;

    /// evaluate rho given an eye vector 
    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    /// set the hemisphere exponent
    inline void SetExp(const real exp) { m_exp = exp; }

    /// set the intensity
    inline void SetIntensity(const real kd)   { m_intensity = kd; }

    /// set the color
    inline void SetColor(const Color& cd) { m_color = cd; }

    /// get the gemisphere exponent
    inline real GetExp(const real exp) { return m_exp; }

    /// get the intensity
    inline real  GetIntensity() { return m_intensity; }

    /// get the color
    inline Color GetColor() { return m_color; }
};

/// @}

#endif