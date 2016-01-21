
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

    void SetDiffuse(const Color& color);

    void SetSpecular(const Color& color);

    void SetRoughness(float roughness);

    void SetIncidence(float incidence);
};

/// --------------------------------------------------------------------------- SetAmbient

inline void 
CookTorrance::SetAmbient(const Color& color, const real intensity = 1.0f)
{
}

/// --------------------------------------------------------------------------- SetDiffuse

inline void 
CookTorrance::SetDiffuse(const Color& color)
{
}

/// --------------------------------------------------------------------------- SetSpecular

inline void 
CookTorrance::SetSpecular(const Color& color)
{
}

/// --------------------------------------------------------------------------- SetRoughness

inline void 
CookTorrance::SetRoughness(float roughness)
{
}

/// --------------------------------------------------------------------------- SetIncidence

inline void 
CookTorrance::SetIncidence(float incidence)
{
}

/// --------------------------------------------------------------------------- EOF

#endif