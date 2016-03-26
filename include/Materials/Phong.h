
#ifndef PHONG_H
#define PHONG_H

#include "Material.h"
#include "..\BRDFs\Lambertian.h"
#include "..\BRDFs\GlossySpecular.h"

/// @defgroup Phong Phong
/// @{

class Phong : public Material
{
private:
    Lambertian m_ambient;      /// lambertian ambient component
    Lambertian m_diffuse;      /// lambertian diffuse component
    GlossySpecular m_specular; /// specular component

public:
    /// constructor
    Phong();

    /// copy constructor
    Phong(const Phong& phong);

    /// destructor
    virtual ~Phong();

    /// copy assignment operator
    Phong& operator=(Phong phong);

    /// deep copy of this object
    virtual Material* Clone() const;

    /// compute the color given a shade record
    virtual Color Shade(ShadeRecord& record) const;

    /// compute the color given a shade record for area lighting
    virtual Color AreaLightShade(ShadeRecord& record) const;

    /// set the ambient properties of this material
    void SetAmbient(const Color& color, const real intensity = 1.0f);

    /// set the diffuse properties of this material
    void SetDiffuse(const Color& color, const real intensity = 1.0f);

    /// set the specular properties of this material
    void SetSpecular(const Color& color, const real exp = 1.0f, const float intensity = 1.0f);
};

/// --------------------------------------------------------------------------- SetAmbient

inline void 
Phong::SetAmbient(const Color& color, const real intensity)
{
    m_ambient.SetColor(color);
    m_ambient.SetIntensity(intensity);
}

/// --------------------------------------------------------------------------- SetDiffuse

inline void 
Phong::SetDiffuse(const Color& color, const real intensity)
{
    m_diffuse.SetColor(color);
    m_diffuse.SetIntensity(intensity);
}

/// --------------------------------------------------------------------------- SetSpecular

inline void 
Phong::SetSpecular(const Color& color, const real exp, const float intensity)
{
    m_specular.SetExp(exp);
    m_specular.SetColor(color);
    m_specular.SetIntensity(intensity);
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif