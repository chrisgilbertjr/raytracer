
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "BRDF.h"

class Lambertian : public BRDF
{
private:
    Color m_color;
    real  m_intensity;

    /// compute Rho without extram params
    Color Hue() const;

public:
    Lambertian();

    Lambertian(const Lambertian& brdf);

    virtual ~Lambertian();

    Lambertian& operator=(Lambertian brdf);

    virtual BRDF* Clone() const;

    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const;

    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    inline void SetIntensity(const real intensity)   { m_intensity = intensity; }

    inline void SetColor(const Color& color) { m_color = color; }

    inline real  GetIntensity() { return m_intensity; }

    inline Color GetColor() { return m_color; }
};

#endif