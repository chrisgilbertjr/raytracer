
#ifndef CHECKER2D_H
#define CHECKER2D_H

#include "Texture.h"

class Checker2D : public Texture
{
protected:
    Color m_a;
    Color m_b;
    real m_xScale;
    real m_yScale;
    real m_xOffset;
    real m_yOffset;

public:
    Checker2D();

    Checker2D(real xScale, real yScale, real xOffset = 0.f, real yOffset = 0.f);

    Checker2D(const Checker2D& checker);

    virtual ~Checker2D();

    Checker2D& operator=(Checker2D checker);

    virtual Texture* Clone() const;

    virtual Color GetTexel(const ShadeRecord& record) const;

    void SetScale(real x, real y);

    void SetOffset(real x, real y);

    void SetColors(const Color& a, const Color& b);
};

#endif