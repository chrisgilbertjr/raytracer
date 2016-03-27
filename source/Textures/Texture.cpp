
#include "Textures\Texture.h"

Texture::Texture()
    : m_color(Color::Black())
{}

Texture::Texture(const Color& color)
    : m_color(color)
{}

Texture::Texture(const real r, const real g, const real b, const real a)
    : m_color(Color(r, g, b, a))
{}

Texture::Texture(const Texture& texture)
    : m_color(texture.m_color)
{}

Texture::~Texture() {}

Texture& 
Texture::operator=(Texture texture)
{
    Swap<Color>(m_color, texture.m_color);
    return *this;
}

Texture* 
Texture::Clone() const
{
    return new Texture(*this);
}

Color 
Texture::GetTexel(const ShadeRecord& record) const
{
    return GetColor();
}

Color 
Texture::GetColor() const
{
    return m_color;
}

void 
Texture::SetColor(const Color& color)
{
    m_color = color;
}

void 
Texture::TransformUV(real xScale, real yScale, real xOffset, real yOffset, real& u, real &v) const
{
    OffsetUV(xOffset, yOffset, u, v);
    ScaleUV(xScale, yScale, u, v);
    WrapUV(u, v);
}

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

void 
Texture::ScaleUV(real x, real y, real& u, real& v) const
{
    u *= x;
    v *= y;
}

void 
Texture::OffsetUV(real x, real y, real& u, real& v) const
{
    u += x;
    v += y;
}