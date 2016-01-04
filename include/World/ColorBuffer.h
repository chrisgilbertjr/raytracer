
#ifndef COLORBUFFER_H
#define COLORBUFFER_H

#include "Core\Color.h"

/// color buffer used to create BMP images
class ColorBuffer
{
public:
    Color* m_buffer;   /// color buffer
    unsigned m_height; /// height of the buffer
    unsigned m_width;  /// width of the buffer

public:
    /// constructor
    ColorBuffer();

    ColorBuffer(const ColorBuffer& buffer);

    ColorBuffer(int width, int height);

    ColorBuffer(int width, int height, const Color& color);

    ~ColorBuffer();

    ColorBuffer& operator=(ColorBuffer buffer);

    void SetColor(int x, int y, const Color& color);

    void SetBackground(const Color& color);

    Color GetColor(int x, int y) const;

    unsigned GetHeight() const { return m_height; }

    unsigned GetWidth() const  { return m_width; }
};

#endif