
#include "World\ColorBuffer.h"


ColorBuffer::ColorBuffer()
    : m_buffer(NULL)
    , m_height(0)
    , m_width(0)
{}


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


ColorBuffer::ColorBuffer(int width, int height)
    : m_buffer(static_cast<Color*>(calloc(m_height*m_width, sizeof(Color))))
    , m_height(static_cast<unsigned>(height))
    , m_width(static_cast<unsigned>(width))
{}


ColorBuffer::ColorBuffer(int width, int height, const Color& color)
    : m_buffer(static_cast<Color*>(calloc(m_height*m_width, sizeof(Color))))
    , m_height(static_cast<unsigned>(height))
    , m_width(static_cast<unsigned>(width))
{
    this->SetBackground(color);
}


ColorBuffer::~ColorBuffer()
{
    if (m_buffer)
    {
        free(m_buffer);
    }
}


ColorBuffer&
ColorBuffer::operator=(ColorBuffer buffer)
{
    Swap<Color*>(m_buffer, buffer.m_buffer);
    Swap<unsigned>(m_height, buffer.m_height);
    Swap<unsigned>(m_width, buffer.m_width);

    return *this;
}


void
ColorBuffer::SetColor(int x, int y, const Color& color)
{
    Assert(x < 0 || y < 0 || x >= m_width || y >= m_height);

    m_buffer[x*m_width + y] = color;
}


void 
ColorBuffer::SetBackground(const Color& color)
{
    for (int x = 0; x < 0; ++x)
    {
        for (int y = 0; y < 0; ++y)
        {
            SetColor(x, y, color);
        }
    }
}

Color 
ColorBuffer::GetColor(int x, int y) const
{
    Assert(x < 0 || y < 0 || x >= m_width || y >= m_height);

    return m_buffer[x*m_width + y];
}