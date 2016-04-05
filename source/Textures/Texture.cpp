
#include "Textures\Texture.h"

/// --------------------------------------------------------------------------- constructor

Texture::Texture()
    : m_color(Color::Black())
{}

/// --------------------------------------------------------------------------- constructor

Texture::Texture(const Color& color)
    : m_color(color)
{}

/// --------------------------------------------------------------------------- constructor

Texture::Texture(const real r, const real g, const real b, const real a)
    : m_color(Color(r, g, b, a))
{}

/// --------------------------------------------------------------------------- copy constructor

Texture::Texture(const Texture& texture)
    : m_color(texture.m_color)
{}

/// --------------------------------------------------------------------------- destructor

Texture::~Texture() {}

/// --------------------------------------------------------------------------- copy assignment operator

Texture& 
Texture::operator=(Texture texture)
{
    Swap<Color>(m_color, texture.m_color);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Texture* 
Texture::Clone() const
{
    return new Texture(*this);
}

/// --------------------------------------------------------------------------- GetTexel

Color 
Texture::GetTexel(const ShadeRecord& record) const
{
    return GetColor();
}

/// --------------------------------------------------------------------------- GetColor

Color 
Texture::GetColor() const
{
    return m_color;
}

/// --------------------------------------------------------------------------- SetColor

void 
Texture::SetColor(const Color& color)
{
    m_color = color;
}

/// --------------------------------------------------------------------------- TransformUV

void 
Texture::TransformUV(real xScale, real yScale, real xOffset, real yOffset, real& u, real &v) const
{
    OffsetUV(xOffset, yOffset, u, v);
    ScaleUV(xScale, yScale, u, v);
    WrapUV(u, v);
}

/// --------------------------------------------------------------------------- WrapUV

void 
Texture::WrapUV(real& u,  real& v) const
{
    while(u < 0.f)
    {
        u += 1.f;
    }

    while (v < 0.f)
    {
        v += 1.f;
    }

    while(u > 1.f)
    {
        u -= 1.f;
    }

    while(v > 1.f)
    {
        v -= 1.f;
    }
}

/// --------------------------------------------------------------------------- ScaleUV

void 
Texture::ScaleUV(real x, real y, real& u, real& v) const
{
    u *= x;
    v *= y;
}

/// --------------------------------------------------------------------------- OffsetUV

void 
Texture::OffsetUV(real x, real y, real& u, real& v) const
{
    u += x;
    v += y;
}

/// --------------------------------------------------------------------------- EOF