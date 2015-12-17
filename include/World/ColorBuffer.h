
#ifndef COLORBUFFER_H
#define COLORBUFFER_H

#include "Core\Color.h"

class ColorBuffer
{
private:
    Color** m_buffer;
    unsigned m_width, m_height;

public:
    ColorBuffer();

    ColorBuffer(int width, int height);

    ~ColorBuffer();

    void operator=(const ColorBuffer& buffer);

    void SetColor(int x, int y, const Color& color);
};

#endif