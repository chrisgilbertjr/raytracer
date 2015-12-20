
#ifndef PERFECT_SPECULAR_H
#define PERFECT_SPECULAR_H

#include "BRDF.h"

class PerfectSpecular : public BRDF
{
private:
    real  m_kr;
    Color m_cr;

    Color Hue() const;

public:
    PerfectSpecular();

    PerfectSpecular(const PerfectSpecular& brdf);

    virtual ~PerfectSpecular();

    PerfectSpecular& operator=(PerfectSpecular brdf);

    virtual BRDF* Clone() const;

    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color SampleF(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    inline void SetKr(const real kd)   { m_kr = kd; }

    inline void SetCr(const Color& cd) { m_cr = cd; }

    inline real  GetKr() { return m_kr; }

    inline Color GetCr() { return m_cr; }
};

#endif