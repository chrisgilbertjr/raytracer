
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "BRDF.h"

class Lambertian : public BRDF
{
private:
    real  m_scale;
    Color m_color;

    /// compute Rho without extram params
    Color Hue() const;

public:
    Lambertian();

    Lambertian(const Lambertian& brdf);

    virtual ~Lambertian();

    Lambertian& operator=(Lambertian brdf);

    virtual BRDF* Clone() const;

    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color SampleF(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    inline void SetScale(const real scale)   { m_scale = scale; }

    inline void SetColor(const Color& color) { m_color = color; }

    inline real  GetScale() { return m_scale; }

    inline Color GetColor() { return m_color; }
};

#endif