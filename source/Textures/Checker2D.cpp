
#include "Textures\Checker2D.h"

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

Checker2D::~Checker2D() {}

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

Texture* 
Checker2D::Clone() const
{
    return static_cast<Texture*>(new Checker2D(*this));
}

Color 
Checker2D::GetTexel(const ShadeRecord& record) const
{
    real u = record.u;
    real v = record.v;

    TransformUV(m_xScale, m_yScale, m_xOffset, m_yOffset, u, v);
    //fprintf(stdout, "%.4f, %.4f\n", u, v);

    return ((u < 0.5f)  ?  ((v < 0.5f) ? m_a : m_b)  :  ((v < 0.5f) ? m_b : m_a));
}

void 
Checker2D::SetScale(real x, real y)
{
    m_xScale = x;
    m_yScale = y;
}

void 
Checker2D::SetOffset(real x, real y)
{
    m_xOffset = x;
    m_yOffset = y;
}

void 
Checker2D::SetColors(const Color& a, const Color& b)
{
    m_a = a;
    m_b = b;
}
