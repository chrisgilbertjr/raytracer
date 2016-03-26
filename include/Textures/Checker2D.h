
#ifndef CHECKER2D_H
#define CHECKER2D_H

#include "Texture.h"

/// @defgroup Checker2D Checker2D
/// @{

/// 2D checkerboard texture
class Checker2D : public Texture
{
protected:
    Color m_a;      /// color a
    Color m_b;      /// color b
    real m_xScale;  /// x texture scale
    real m_yScale;  /// y texture scale
    real m_xOffset; /// x texture offset
    real m_yOffset; /// y texture offset

public:
    /// constructor
    Checker2D();

    /// constructor
    Checker2D(real xScale, real yScale, real xOffset = 0.f, real yOffset = 0.f);

    /// copy constructor
    Checker2D(const Checker2D& checker);

    /// destructor
    virtual ~Checker2D();

    /// copy assignment operator
    Checker2D& operator=(Checker2D checker);

    /// deep copy of this object
    virtual Texture* Clone() const;

    /// get a texel given a shade record
    virtual Color GetTexel(const ShadeRecord& record) const;

    /// set the texture scale
    void SetScale(real x, real y);

    /// set the texture offsets
    void SetOffset(real x, real y);

    /// set the checkerboard colors
    void SetColors(const Color& a, const Color& b);
};

/// @}

#endif