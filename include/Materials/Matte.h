
#ifndef MATTE_H
#define MATTE_H

#include "Material.h"
#include "..\BRDFs\Lambertian.h"
#include "..\Textures\Texture.h"

/// @defgroup Matte Matte
/// @{

/// matte material with an ambient and diffuse component
class Matte : public Material
{
private:
    Lambertian m_ambient; /// lambertian ambient component
    Lambertian m_diffuse; /// lambertian diffuse component
    bool m_customTexture; /// does this material use a texture?

public:
    /// constructor
    Matte();

    /// constructor
    Matte(Texture* texture);

    /// copy constructor
    Matte(const Matte& matte);

    /// destructor
    virtual ~Matte();

    /// copy assignment operator
    Material& operator=(Matte matte);

    /// deep copy of the object
    virtual Material* Clone() const;

    /// compute the color given a shade record
    virtual Color Shade(ShadeRecord& record) const;

    /// compute the color given a shade record for area lighting
    virtual Color AreaLightShade(ShadeRecord& record) const;

    /// compute the color given a shade record for path shading
    virtual Color PathShade(ShadeRecord& record) const;

    /// set the materials ambient properties
    void SetAmbient(const Color& color, const real intensity = 1.0f);

    /// set the materials diffuse properties
    void SetDiffuse(const Color& color, const real intensity = 1.0f);
};

/// --------------------------------------------------------------------------- SetAmbient

inline void 
Matte::SetAmbient(const Color& color, const real intensity)
{
    m_ambient.SetColor(color);
    m_ambient.SetIntensity(intensity);
}

/// --------------------------------------------------------------------------- SetDiffuse

inline void 
Matte::SetDiffuse(const Color& color, const real intensity)
{
    m_diffuse.SetColor(color);
    m_diffuse.SetIntensity(intensity);
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif