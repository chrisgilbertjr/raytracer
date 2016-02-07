
#ifndef MATTE_H
#define MATTE_H

#include "Material.h"
#include "..\BRDFs\Lambertian.h"

class Matte : public Material
{
private:
    Lambertian m_ambient;
    Lambertian m_diffuse;

public:
    Matte();

    Matte(const Matte& matte);

    virtual ~Matte();

    Material& operator=(Matte matte);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;

    virtual Color AreaLightShade(ShadeRecord& record) const;

    void SetAmbient(const Color& color, const real intensity = 1.0f);

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

#endif