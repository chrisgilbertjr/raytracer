
#ifndef GRID_H
#define GRID_H

#include "Texture.h"

/// @defgroup Grid Grid
/// @{

/// checkerboard texture with a grid between cells
class Grid : public Texture
{
protected:
    Color m_a;             /// color a
    Color m_b;             /// color b
    Color m_lines;         /// grid line color
    real m_linePercentage; /// grid line percentage
    real m_xScale;         /// texture x scale
    real m_yScale;         /// texture y scale
    real m_xOffset;        /// texture x offset
    real m_yOffset;        /// texture y offset

public:
    /// constructor
    Grid();

    /// constructor
    Grid(real xScale, real yScale, const Color& a, const Color& b, const Color& lines, real xOffset = 0.f, real yOffset = 0.f);

    /// copy constructor
    Grid(const Grid& checker);

    /// destructor
    virtual ~Grid();

    /// copy assignment operator
    Grid& operator=(Grid checker);

    /// deep copy of this object
    virtual Texture* Clone() const;

    /// get a texel given a shade record
    virtual Color GetTexel(const ShadeRecord& record) const;

    /// set the texture scale
    void SetScale(real x, real y);

    /// set the texture offset
    void SetOffset(real x, real y);

    /// set the grids colors
    void SetColors(const Color& a, const Color& b, const Color& lines);

    /// set the grids line percentage
    void SetLinePercentage(real percentage);
};

/// @}

#endif