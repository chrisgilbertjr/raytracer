
#ifndef COLORBUFFER_H
#define COLORBUFFER_H

#include "Core\Color.h"

/// @defgroup ColorBuffer ColorBuffer
/// @{

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

    /// copy constructor
    ColorBuffer(const ColorBuffer& buffer);

    /// constructor
    ColorBuffer(int width, int height);

    /// constructor
    ColorBuffer(int width, int height, const Color& color);

    /// destructor
    ~ColorBuffer();

    /// copy assignment operator
    ColorBuffer& operator=(ColorBuffer buffer);

    /// set a pixel in the color buffer
    void SetColor(int x, int y, const Color& color);

    /// set the background of the color buffer
    void SetBackground(const Color& color);

    /// get a color at (x, y) of the color buffer
    Color GetColor(int x, int y) const;

    /// get the height of the color buffer
    unsigned GetHeight() const;

    /// get the width of the color buffer
    unsigned GetWidth() const;
};

/// --------------------------------------------------------------------------- GetHeight

inline unsigned 
ColorBuffer::GetHeight() const 
{ 
    return m_height; 
}

/// --------------------------------------------------------------------------- GetWidth

inline unsigned 
ColorBuffer::GetWidth() const  
{ 
    return m_width; 
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif