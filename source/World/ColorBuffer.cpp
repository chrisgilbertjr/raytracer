
#include "World\ColorBuffer.h"
 
/// --------------------------------------------------------------------------- constructor

ColorBuffer::ColorBuffer()
    : m_buffer(NULL)
    , m_height(0)
    , m_width(0)
{}

/// --------------------------------------------------------------------------- copy constructor

ColorBuffer::ColorBuffer(const ColorBuffer& buffer)
{
    m_height = buffer.m_height;
    m_width = buffer.m_width;

    if (m_buffer)
    {
        m_buffer = static_cast<Color*>(calloc(m_height*m_width, sizeof(Color)));

        memcpy(m_buffer, buffer.m_buffer, m_width * m_height * sizeof(Color));
    }
    else
    {
        m_buffer = NULL;
    }
}

/// --------------------------------------------------------------------------- constructor

ColorBuffer::ColorBuffer(int width, int height)
    : m_buffer(static_cast<Color*>(calloc(height*width, sizeof(Color))))
    , m_height(static_cast<unsigned>(height))
    , m_width(static_cast<unsigned>(width))
{
    this->SetBackground(Color::Black());
}

/// --------------------------------------------------------------------------- constructor

ColorBuffer::ColorBuffer(int width, int height, const Color& color)
    : m_buffer(static_cast<Color*>(calloc(height*width, sizeof(Color))))
    , m_height(static_cast<unsigned>(height))
    , m_width(static_cast<unsigned>(width))
{
    this->SetBackground(color);
}

/// --------------------------------------------------------------------------- destructor

ColorBuffer::~ColorBuffer()
{
    if (m_buffer)
    {
        free(m_buffer);
    }
}

/// --------------------------------------------------------------------------- copy assignment operator

ColorBuffer&
ColorBuffer::operator=(ColorBuffer buffer)
{
    /// copy and swap
    Swap<Color*>(m_buffer, buffer.m_buffer);
    Swap<unsigned>(m_height, buffer.m_height);
    Swap<unsigned>(m_width, buffer.m_width);

    return *this;
}

/// --------------------------------------------------------------------------- SetColor

void
ColorBuffer::SetColor(int x, int y, const Color& color)
{
    Assert(x < 0 || y < 0 || x >= m_width || y >= m_height);

    m_buffer[x*(int)m_height + y] = color;
}

/// --------------------------------------------------------------------------- SetBackground

void 
ColorBuffer::SetBackground(const Color& color)
{
    for (int y = 0; y < (int)m_height; ++y)
    {
        for (int x = 0; x < (int)m_width; ++x)
        {
            SetColor(x, y, color);
        }
    }
}

/// --------------------------------------------------------------------------- GetColor

Color 
ColorBuffer::GetColor(int x, int y) const
{
    Assert(x < 0 || y < 0 || x >= m_width || y >= m_height);

    return m_buffer[x*(int)m_height + y];
}

/// --------------------------------------------------------------------------- EOF