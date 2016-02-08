
#ifndef EMMISIVE_H
#define EMMISIVE_H

#include "Material.h"

class Emmisive : public Material
{
private:
    Color m_color;
    real m_intensity;

public:
    Emmisive();

    Emmisive(const Emmisive& emmisive);

    virtual ~Emmisive();

    Emmisive& operator=(Emmisive emmisive);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;

    virtual Color AreaLightShade(ShadeRecord& record) const;

    virtual Color GetEmmisive() const;

    void SetEmmisive(const Color& color, const real intensity = 1.0f);
};

/// --------------------------------------------------------------------------- SetEmmisive

inline void 
Emmisive::SetEmmisive(const Color& color, const real intensity)
{
    m_color = color;
    m_intensity = intensity;
}

/// --------------------------------------------------------------------------- EOF

#endif