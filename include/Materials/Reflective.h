
#ifndef REFLECTIVE_H
#define REFLECTIVE_H

#include "CookTorrance.h"
#include "..\BRDFs\PerfectSpecular.h"

class Reflective : public CookTorrance
{
private:
    PerfectSpecular m_reflective;

public:
    Reflective();

    Reflective(const Reflective& material);

    virtual ~Reflective();

    Reflective& operator=(Reflective material);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;

    void SetReflective(const Color& color, real intensity);
};

/// --------------------------------------------------------------------------- SetReflective

inline void 
Reflective::SetReflective(const Color& color, real intensity = 1.f) 
{
    m_reflective.SetCr(color);
    m_reflective.SetKr(intensity);
}

/// --------------------------------------------------------------------------- EOF

#endif