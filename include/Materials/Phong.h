
#ifndef PHONG_H
#define PHONG_H

#include "Material.h"
#include "..\BRDFs\Lambertian.h"
#include "..\BRDFs\GlossySpecular.h"

class Phong : public Material
{
private:
    Lambertian m_ambient;
    Lambertian m_diffuse;
    GlossySpecular m_specular;

public:
    Phong();

    Phong(const Phong& phong);

    virtual ~Phong();

    Phong& operator=(Phong phong);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;

    virtual Color AreaLightShade(ShadeRecord& record) const;

    void SetAmbient(const Color& color, const real intensity = 1.0f);

    void SetDiffuse(const Color& color, const real intensity = 1.0f);

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

#endif