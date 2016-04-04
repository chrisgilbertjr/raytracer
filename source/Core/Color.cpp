
#include "Core\MathUtils.h"
#include "Core\Color.h"

/// --------------------------------------------------------------------------- constructor

Color::Color()
    : r(1.f)
    , g(1.f)
    , b(1.f)
    , a(1.f)
{}

/// --------------------------------------------------------------------------- copy constructor

Color::Color(const Color& color)
    : r(color.r)
    , g(color.g)
    , b(color.b)
    , a(color.a)
{}

/// --------------------------------------------------------------------------- constructor

Color::Color(real r, real g, real b)
    : r(r)
    , g(g)
    , b(b)
    , a(1.f)
{}

/// --------------------------------------------------------------------------- constructor

Color::Color(real r, real g, real b, real a)
    : r(r)
    , g(g)
    , b(b)
    , a(a)
{}

/// --------------------------------------------------------------------------- destructor

Color::~Color()
{}

/// --------------------------------------------------------------------------- copy assignment operator

Color& Color::operator=(Color color)
{
    Swap<real>(r, color.r);
    Swap<real>(g, color.g);
    Swap<real>(b, color.b);
    Swap<real>(a, color.a);
    return *this;
}

/// --------------------------------------------------------------------------- operator+=

Color& Color::operator+=(const Color& color)
{
    r += color.r;
    g += color.g;
    b += color.b;
    a += color.a;

    return *this;
}

/// --------------------------------------------------------------------------- operator*=

Color& Color::operator*=(const Color& color)
{
    r *= color.r;
    g *= color.g;
    b *= color.b;
    a *= color.a;

    return *this;
}

/// --------------------------------------------------------------------------- operator*=

Color& Color::operator*=(real scalar)
{
    r *= scalar;
    g *= scalar;
    b *= scalar;
    a *= scalar;

    return *this;
}

/// --------------------------------------------------------------------------- operator/=

Color& Color::operator/=(real scalar)
{
    r /= scalar;
    g /= scalar;
    b /= scalar;
    a /= scalar;

    return *this;
}

/// --------------------------------------------------------------------------- operator==

bool Color::operator==(const Color& color) const
{
    return Equal(r, color.r) && Equal(g, color.g) && Equal(b, color.b) && Equal(a, color.a);
}

/// --------------------------------------------------------------------------- operator!=

bool Color::operator!=(const Color& color) const
{
    return !Equal(r, color.r) || !Equal(g, color.g) || !Equal(b, color.b) || !Equal(a, color.a);
}

/// --------------------------------------------------------------------------- operator+

Color Color::operator+(const Color& color) const
{
    return Color(r+color.r, g+color.g, b+color.b, a+color.a);
}

/// --------------------------------------------------------------------------- operator*

Color Color::operator*(const Color& color) const
{
    return Color(r*color.r, g*color.g, b*color.b, a*color.a);
}

/// --------------------------------------------------------------------------- operator*

Color Color::operator*(real scalar) const
{
    return Color(r*scalar, g*scalar, b*scalar, a*scalar);
}

/// --------------------------------------------------------------------------- operator/

Color Color::operator/(real scalar) const
{
    return Color(r/scalar, g/scalar, b/scalar, a/scalar);
}

/// --------------------------------------------------------------------------- pow

Color Color::pow(real pow) const
{
    return Color(Pow(r, pow), Pow(g, pow), Pow(b, pow), a);
}

/// --------------------------------------------------------------------------- clamp

void Color::clamp(real min, real max)
{
    r = Clamp(r, min, max);
    g = Clamp(g, min, max);
    b = Clamp(b, min, max);
}

/// --------------------------------------------------------------------------- clamp01

void Color::clamp01()
{
    this->clamp(0.f, 1.0f);
}

/// --------------------------------------------------------------------------- Black

Color Color::Black(real alpha)
{
    return Color(0.f, 0.f, 0.f, alpha);
}

/// --------------------------------------------------------------------------- White

Color Color::White(real alpha)
{
    return Color(1.f, 1.f, 1.f, alpha);
}

/// --------------------------------------------------------------------------- Red

Color Color::Red(real alpha)
{
    return Color(1.f, 0.f, 0.f, alpha);
}

/// --------------------------------------------------------------------------- Green

Color Color::Green(real alpha)
{
    return Color(0.f, 1.f, 0.f, alpha);
}

/// --------------------------------------------------------------------------- Blue

Color Color::Blue(real alpha)
{
    return Color(0.f, 0.f, 1.f, alpha);
}

/// --------------------------------------------------------------------------- operator*

Color operator*(real scalar, const Color& color)
{
    return color * scalar;
}

/// --------------------------------------------------------------------------- Map255

static unsigned char
Map255(real x)
{
    return (unsigned char)(x * 255.f);
}

/// --------------------------------------------------------------------------- MapColor255

Color255 
MapColor255(const Color& color)
{
    Color255 color255;
    color255.r = Map255(color.r);
    color255.g = Map255(color.g);
    color255.b = Map255(color.b);
    color255.a = Map255(color.a);
    return color255;
}

/// --------------------------------------------------------------------------- EOF