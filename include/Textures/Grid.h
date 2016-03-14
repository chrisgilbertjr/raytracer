
#ifndef GRID_H
#define GRID_H

#include "Texture.h"

class Grid : public Texture
{
protected:
    Color m_a;
    Color m_b;
    Color m_lines;
    real m_linePercentage;
    real m_xScale;
    real m_yScale;
    real m_xOffset;
    real m_yOffset;

public:
    Grid();

    Grid(real xScale, real yScale, const Color& a, const Color& b, const Color& lines, real xOffset = 0.f, real yOffset = 0.f);

    Grid(const Grid& checker);

    virtual ~Grid();

    Grid& operator=(Grid checker);

    virtual Texture* Clone() const;

    virtual Color GetTexel(const ShadeRecord& record) const;

    void SetScale(real x, real y);

    void SetOffset(real x, real y);

    void SetColors(const Color& a, const Color& b, const Color& lines);

    void SetLinePercentage(real percentage);
};

#endif