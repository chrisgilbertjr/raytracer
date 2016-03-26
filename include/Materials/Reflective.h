
#ifndef REFLECTIVE_H
#define REFLECTIVE_H

#include "CookTorrance.h"
#include "..\BRDFs\PerfectSpecular.h"

/// @defgroup Reflective Reflective
/// @{

/// reflective material
class Reflective : public CookTorrance
{
private:
    PerfectSpecular m_reflective; /// reflective component of the material

public:
    /// constructor
    Reflective();

    /// copy constructor
    Reflective(const Reflective& material);

    /// destructor
    virtual ~Reflective();

    /// copy assignment operator
    Reflective& operator=(Reflective material);

    /// deep copy of this object
    virtual Material* Clone() const;

    /// compute the color given a shade record
    virtual Color Shade(ShadeRecord& record) const;

    /// compute the color given a shade record for area lighting
    virtual Color AreaLightShade(ShadeRecord& record) const;
    
    /// compute the color given a shade record for path shading
    virtual Color PathShade(ShadeRecord& record) const;

    /// set the reflective properties of the material
    void SetReflective(const Color& color, real intensity);
};

/// --------------------------------------------------------------------------- SetReflective

inline void 
Reflective::SetReflective(const Color& color, real intensity = 1.f) 
{
    m_reflective.SetCr(color);
    m_reflective.SetKr(intensity);
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif