
#include "Textures\Grid.h"

/// --------------------------------------------------------------------------- constructor

Grid::Grid()
    : Texture()
    , m_a(Color::White())
    , m_b(Color::White())
    , m_lines(Color::Black())
    , m_linePercentage(0.1f)
    , m_xScale(1.f)
    , m_yScale(1.f)
    , m_xOffset(0.f)
    , m_yOffset(0.f)
{
}

/// --------------------------------------------------------------------------- constructor

Grid::Grid(real xScale, real yScale, const Color& a, const Color& b, const Color& lines, real xOffset, real yOffset)
    : Texture()
    , m_a(a)
    , m_b(b)
    , m_lines(lines)
    , m_linePercentage(0.1f)
    , m_xScale(xScale)
    , m_yScale(yScale)
    , m_xOffset(xOffset)
    , m_yOffset(yOffset)
{
}

/// --------------------------------------------------------------------------- copy constructor

Grid::Grid(const Grid& checker)
    : Texture(checker)
    , m_a(checker.m_a)
    , m_b(checker.m_b)
    , m_lines(checker.m_lines)
    , m_linePercentage(checker.m_linePercentage)
    , m_xScale(checker.m_xScale)
    , m_yScale(checker.m_yScale)
    , m_xOffset(checker.m_xOffset)
    , m_yOffset(checker.m_yOffset)
{
}

/// --------------------------------------------------------------------------- destructor

Grid::~Grid() {}

/// --------------------------------------------------------------------------- copy assignment operator

Grid& 
Grid::operator=(Grid checker)
{
    Texture::operator=(checker);
    Swap<Color>(m_a, checker.m_a);
    Swap<Color>(m_b, checker.m_b);
    Swap<Color>(m_lines, checker.m_lines);
    Swap<real>(m_linePercentage, checker.m_linePercentage);
    Swap<real>(m_xScale, checker.m_xScale);
    Swap<real>(m_yScale, checker.m_yScale);
    Swap<real>(m_xOffset, checker.m_xOffset);
    Swap<real>(m_yOffset, checker.m_yOffset);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Texture* 
Grid::Clone() const
{
    return static_cast<Texture*>(new Grid(*this));
}

/// --------------------------------------------------------------------------- GetTexel

Color 
Grid::GetTexel(const ShadeRecord& record) const
{
    real l0 = m_linePercentage * 0.5f;
    real l1 = .5f - l0;
    real l2 = .5f + l0;
    real l3 = 1.f - l0;

    real u = record.u;
    real v = record.v;

    TransformUV(m_xScale, m_yScale, m_xOffset, m_yOffset, u, v);

    if (u > l0 && u < l1)
    {
        if (v > l0 && v < l1)
        {
            return m_a;
        }
        if (v > l2 && v < l3)
        {
            return m_b;
        }
    }

    if (u > l2 && u < l3)
    {
        if (v > l0 && v < l1)
        {
            return m_b;
        }
        if (v > l2 && v < l3)
        {
            return m_a;
        }
    }

    return m_lines;
}

/// --------------------------------------------------------------------------- SetScale

void 
Grid::SetScale(real x, real y)
{
    m_xScale = x;
    m_yScale = y;
}

/// --------------------------------------------------------------------------- SetOffset

void 
Grid::SetOffset(real x, real y)
{
    m_xOffset = x;
    m_yOffset = y;
}

/// --------------------------------------------------------------------------- SetColors

void 
Grid::SetColors(const Color& a, const Color& b, const Color& lines)
{
    m_a = a;
    m_b = b;
    m_lines = lines;
}

/// --------------------------------------------------------------------------- SetLinePercentage

void 
Grid::SetLinePercentage(real percentage)
{
    m_linePercentage = percentage;
}

/// --------------------------------------------------------------------------- EOF
