
#include "Textures\Checker2D.h"

/// --------------------------------------------------------------------------- constructor

Checker2D::Checker2D()
    : Texture()
    , m_a(Color::White())
    , m_b(Color::Black())
    , m_xScale(1.f)
    , m_yScale(1.f)
    , m_xOffset(0.f)
    , m_yOffset(0.f)
{
}

/// --------------------------------------------------------------------------- constructor

Checker2D::Checker2D(real xScale, real yScale, real xOffset, real yOffset)
    : Texture()
    , m_a(Color::White())
    , m_b(Color::Black())
    , m_xScale(xScale)
    , m_yScale(yScale)
    , m_xOffset(xOffset)
    , m_yOffset(yOffset)
{
}

/// --------------------------------------------------------------------------- copy assignment operator

Checker2D::Checker2D(const Checker2D& checker)
    : Texture(checker)
    , m_a(checker.m_a)
    , m_b(checker.m_b)
    , m_xScale(checker.m_xScale)
    , m_yScale(checker.m_yScale)
    , m_xOffset(checker.m_xOffset)
    , m_yOffset(checker.m_yOffset)
{
}

/// --------------------------------------------------------------------------- destructor

Checker2D::~Checker2D() {}
 
/// --------------------------------------------------------------------------- copy assignment operator

Checker2D& 
Checker2D::operator=(Checker2D checker)
{
    Texture::operator=(checker);
    Swap<Color>(m_a, checker.m_a);
    Swap<Color>(m_b, checker.m_b);
    Swap<real>(m_xScale, checker.m_xScale);
    Swap<real>(m_yScale, checker.m_yScale);
    Swap<real>(m_xOffset, checker.m_xOffset);
    Swap<real>(m_yOffset, checker.m_yOffset);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Texture* 
Checker2D::Clone() const
{
    return static_cast<Texture*>(new Checker2D(*this));
}

/// --------------------------------------------------------------------------- GetTexel

Color 
Checker2D::GetTexel(const ShadeRecord& record) const
{
    real u = record.u;
    real v = record.v;

    TransformUV(m_xScale, m_yScale, m_xOffset, m_yOffset, u, v);

    return ((u < 0.5f)  ?  ((v < 0.5f) ? m_a : m_b)  :  ((v < 0.5f) ? m_b : m_a));
}

/// --------------------------------------------------------------------------- SetScale

void 
Checker2D::SetScale(real x, real y)
{
    m_xScale = x;
    m_yScale = y;
}

/// --------------------------------------------------------------------------- SetOffset

void 
Checker2D::SetOffset(real x, real y)
{
    m_xOffset = x;
    m_yOffset = y;
}

/// --------------------------------------------------------------------------- SetColors

void 
Checker2D::SetColors(const Color& a, const Color& b)
{
    m_a = a;
    m_b = b;
}
 
/// --------------------------------------------------------------------------- EOF