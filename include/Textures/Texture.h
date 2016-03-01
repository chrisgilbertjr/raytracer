
#ifndef TEXTURE_H
#define TEXTURE_H

#include "..\BRDFs\ShadeRecord.h"

class Texture
{
protected:
    Color m_color;

public:
    Texture();

    Texture(const Color& color);

    Texture(const real r, const real g, const real b, const real a = 1.f);

    Texture(const Texture& texture);

    virtual ~Texture();

    Texture& operator=(Texture texture);

    virtual Texture* Clone() const;

    virtual Color GetTexel(const ShadeRecord& record) const;

    Color GetColor() const;

    void SetColor(const Color& color);

    void SphereMap(const Vector& localPoint, real& u, real& v) const;

    void RectMap(const Vector& localPoint, real& u, real& v) const;

    void CylinderMap(const Vector& localPoint, real& u, real& v) const;

    void TransformUV(real xScale, real yScale, real xOffset, real yOffset, real& u, real &v) const;

    void WrapUV(real& u,  real& v) const;

    void ScaleUV(real x, real y, real& u, real& v) const;

    void OffsetUV(real x, real y, real& u, real& v) const;
};

#endif