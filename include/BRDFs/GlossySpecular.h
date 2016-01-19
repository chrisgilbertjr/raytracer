
#ifndef GLOSSY_SPECULAR_H
#define GLOSSY_SPECULAR_H

#include "BRDF.h"

class GlossySpecular : public BRDF
{
private:
    real  m_exp;
    real  m_intensity;
    Color m_color;

    Color Hue() const;

public:
    GlossySpecular();

    GlossySpecular(const GlossySpecular& brdf);

    virtual ~GlossySpecular();

    GlossySpecular& operator=(GlossySpecular brdf);

    virtual BRDF* Clone() const;

    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color SampleF(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    inline void SetExp(const real exp) { m_exp = exp; }

    inline void SetIntensity(const real kd)   { m_intensity = kd; }

    inline void SetColor(const Color& cd) { m_color = cd; }

    inline real GetExp(const real exp) { return m_exp; }

    inline real  GetIntensity() { return m_intensity; }

    inline Color GetColor() { return m_color; }
};

#endif