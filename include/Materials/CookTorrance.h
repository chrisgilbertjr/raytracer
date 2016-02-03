
#ifndef COOK_TORRANCE_H
#define COOK_TORRANCE_H

#include "Material.h"
#include "..\BRDFs\Lambertian.h"
#include "..\BRDFs\CookTorranceSpecular.h"

class CookTorrance : public Material
{
private:
    Lambertian m_ambient;
    Lambertian m_diffuse;
    CookTorranceSpecular m_specular;

public:
    CookTorrance();

    CookTorrance(const CookTorrance& ct);

    virtual ~CookTorrance();

    CookTorrance& operator=(CookTorrance ct);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;

    void SetAmbient(const Color& color, const real intensity = 1.0f);

    void SetDiffuse(const Color& color, const real intensity = 1.0f);

    void SetSpecular(const Color& color);

    void SetRoughness(float roughness);

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

#endif