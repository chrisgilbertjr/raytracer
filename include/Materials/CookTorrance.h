
#ifndef COOK_TORRANCE_H
#define COOK_TORRANCE_H

#include "Material.h"
#include "..\BRDFs\Lambertian.h"
#include "..\BRDFs\CookTorranceSpecular.h"

/// @defgroup CookTorrance CookTorrance
/// @{

/// Cook-Torrance microfacted lighting model
class CookTorrance : public Material
{
private:
    Lambertian m_ambient;            /// lambertian ambient component
    Lambertian m_diffuse;            /// lambertian diffuse component
    CookTorranceSpecular m_specular; /// Cook-Torrance specular component

public:
    /// constructor
    CookTorrance();

    /// copy constructor
    CookTorrance(const CookTorrance& ct);

    /// destructor
    virtual ~CookTorrance();

    /// copy assignment operator
    CookTorrance& operator=(CookTorrance ct);

    /// deep copy an object
    virtual Material* Clone() const;

    /// compute the color given a shade record
    virtual Color Shade(ShadeRecord& record) const;

    /// compute the color given a shade record for area lights
    virtual Color AreaLightShade(ShadeRecord& record) const;

    /// set the ambient properties of the material
    void SetAmbient(const Color& color, const real intensity = 1.0f);

    /// set the diffuse properties of the material
    void SetDiffuse(const Color& color, const real intensity = 1.0f);

    /// set the specular properties of the material
    void SetSpecular(const Color& color);

    /// set the roughness of the material
    void SetRoughness(float roughness);

    /// set the IOR of the material (not recommended)
    void SetIncidence(float incidence);
};

/// --------------------------------------------------------------------------- SetAmbient

inline void 
CookTorrance::SetAmbient(const Color& color, const real intensity)
{
    m_ambient.SetIntensity(intensity);
    m_ambient.SetColor(color);
}

/// --------------------------------------------------------------------------- SetDiffuse

inline void 
CookTorrance::SetDiffuse(const Color& color, const real intensity)
{
    m_diffuse.SetIntensity(intensity);
    m_diffuse.SetColor(color);
}

/// --------------------------------------------------------------------------- SetSpecular

inline void 
CookTorrance::SetSpecular(const Color& color)
{
    m_specular.SetColor(color);
}

/// --------------------------------------------------------------------------- SetRoughness

inline void 
CookTorrance::SetRoughness(float roughness)
{
    m_specular.SetRoughness(roughness);
}

/// --------------------------------------------------------------------------- SetIncidence

inline void 
CookTorrance::SetIncidence(float incidence)
{
    m_specular.SetIncidence(incidence);
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif