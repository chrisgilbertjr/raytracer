
#ifndef COLOR_H
#define COLOR_H

#include "Core.h"

/// mapped color to unsigned bytes [0, 255] for BMP images
struct Color255
{
    unsigned char r, g, b, a;
};

/// an RGBA color scheme
struct Color
{
    real r, g, b, a;

    /// constructor. r, g, b = 0,  a = 1
    Color();

    /// constructor, copy
    Color(const Color& color);

    /// constructor given ints in range [0, 255]
    //Color(int r, int g, int b);

    /// constructor given red, green, and blue values
    Color(real r, real g, real b);

    /// constructor given red, green, blue, and alpha values
    Color(real r, real g, real b, real a);

    /// destructor
    ~Color();

    /// equality operator
    Color& operator=(Color color);

    /// mix two colors via addition, modify this color
    Color& operator+=(const Color& color);

    /// mix two colors via multiplication, modify this color
    Color& operator*=(const Color& color);

    /// mix a color via scaling, modify this color
    Color& operator*=(real scalar);

    /// mix a color via division, modify this color
    Color& operator/=(real scalar);

    /// check if two colors are almost the same
    bool operator==(const Color& color) const;

    /// check if two colors are not the same
    bool operator!=(const Color& color) const;

    /// mix two colors via addition, return a copy
    Color operator+(const Color& color) const;

    /// mix two colors via multiplication, return a copy
    Color operator*(const Color& color) const;

    /// mix a color via scaling, return a copy
    Color operator*(real scalar) const;

    /// mix a color via division, return a copy
    Color operator/(real scalar) const;

    /// exp each RGB component, return a copy
    Color pow(real pow) const;

    /// black (1,1,1,1)
    static Color Black(real alpha = 1.0f);

    /// white (0,0,0,1)
    static Color White(real alpha = 1.0f);

    /// red (1,0,0,1)
    static Color Red(real alpha = 1.0f);

    /// green (0,1,0,1)
    static Color Green(real alpha = 1.0f);

    /// blue (0,0,1,1)
    static Color Blue(real alpha = 1.0f);
};

/// mix a color and scalar, return a copy
Color operator*(real scalar, const Color& color);

/// map a Color to a Color255 for image formats
Color255 MapColor255(const Color& color);

#endif