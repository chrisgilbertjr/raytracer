
#include "Core\MathUtils.h"
#include "Core\Color.h"

Color::Color()
    : r(1.f)
    , g(1.f)
    , b(1.f)
    , a(1.f)
{
}

Color::Color(const Color& color)
    : r(color.r)
    , g(color.g)
    , b(color.b)
    , a(color.a)
{
}

Color::Color(real r, real g, real b)
    : r(r)
    , g(g)
    , b(b)
    , a(1.f)
{
}

Color::Color(real r, real g, real b, real a)
    : r(r)
    , g(g)
    , b(b)
    , a(a)
{
}

Color::~Color()
{
}

Color& Color::operator=(const Color& color)
{
    r = color.r;
    g = color.g;
    b = color.b;
    a = color.a;

    return *this;
}

Color& Color::operator+=(const Color& color)
{
    r += color.r;
    g += color.g;
    b += color.b;
    a += color.a;

    return *this;
}

Color& Color::operator*=(const Color& color)
{
    r *= color.r;
    g *= color.g;
    b *= color.b;
    a *= color.a;

    return *this;
}

Color& Color::operator*=(real scalar)
{
    r *= scalar;
    g *= scalar;
    b *= scalar;
    a *= scalar;

    return *this;
}

Color& Color::operator/=(real scalar)
{
    r /= scalar;
    g /= scalar;
    b /= scalar;
    a /= scalar;

    return *this;
}

bool Color::operator==(const Color& color) const
{
    return Equal(r, color.r) && Equal(g, color.g) && Equal(b, color.b) && Equal(a, color.a);
}

bool Color::operator!=(const Color& color) const
{
    return !Equal(r, color.r) || !Equal(g, color.g) || !Equal(b, color.b) || !Equal(a, color.a);
}

Color Color::operator+(const Color& color) const
{
    return Color(r+color.r, g+color.g, b+color.b, a+color.a);
}

Color Color::operator*(const Color& color) const
{
    return Color(r*color.r, g*color.g, b*color.b, a*color.a);
}

Color Color::operator*(real scalar) const
{
    return Color(r*scalar, g*scalar, b*scalar, a*scalar);
}

Color Color::operator/(real scalar) const
{
    return Color(r/scalar, g/scalar, b/scalar, a/scalar);
}

Color Color::pow(real pow) const
{
    return Color(Pow(r, pow), Pow(g, pow), Pow(b, pow), a);
}

Color Color::Black(real alpha)
{
    return Color(0.f, 0.f, 0.f, alpha);
}

Color Color::White(real alpha)
{
    return Color(1.f, 1.f, 1.f, alpha);
}

Color Color::Red(real alpha)
{
    return Color(1.f, 0.f, 0.f, alpha);
}

Color Color::Green(real alpha)
{
    return Color(0.f, 1.f, 0.f, alpha);
}

Color Color::Blue(real alpha)
{
    return Color(0.f, 0.f, 1.f, alpha);
}

Color operator*(real scalar, const Color& color)
{
    return color * scalar;
}