
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "BRDF.h"

class Lambertian : public BRDF
{
private:
    real  m_kd;
    Color m_cd;

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

    inline void SetKd(const real kd)   { m_kd = kd; }

    inline void SetCd(const Color& cd) { m_cd = cd; }

    inline real  GetKd() { return m_kd; }

    inline Color GetCd() { return m_cd; }
};

#endif