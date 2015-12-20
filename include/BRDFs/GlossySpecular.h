
#ifndef GLOSSY_SPECULAR_H
#define GLOSSY_SPECULAR_H

#include "BRDF.h"

class GlossySpecular : public BRDF
{
private:
    real  m_exp;
    real  m_ks;
    Color m_cs;

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

    inline void SetKs(const real kd)   { m_ks = kd; }

    inline void SetCs(const Color& cd) { m_cs = cd; }

    inline real GetExp(const real exp) { return m_exp; }

    inline real  GetKs() { return m_ks; }

    inline Color GetCs() { return m_cs; }
};

#endif