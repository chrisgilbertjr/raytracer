
#ifndef TEXTURE_H
#define TEXTURE_H

#include "..\BRDFs\ShadeRecord.h"

/// @defgroup Texture Texture
/// @{

/// base class for textures
class Texture
{
protected:
    Color m_color; /// base color if texture is not used

public:
    /// constructor
    Texture();

    /// constructor
    Texture(const Color& color);

    /// constructor
    Texture(const real r, const real g, const real b, const real a = 1.f);

    /// copy constructor
    Texture(const Texture& texture);

    /// destructor
    virtual ~Texture();

    /// copy assignment operator
    Texture& operator=(Texture texture);

    /// deep copy of this object
    virtual Texture* Clone() const;

    /// get a texel given a shade record
    virtual Color GetTexel(const ShadeRecord& record) const;

    /// get the base color of the texture
    Color GetColor() const;

    /// set the base color of the texture
    void SetColor(const Color& color);

    /// clamp, scale, and offset the UV's
    void TransformUV(real xScale, real yScale, real xOffset, real yOffset, real& u, real &v) const;

    /// clamp UV's into [0, 1]
    void WrapUV(real& u,  real& v) const;

    /// scale the UV's
    void ScaleUV(real x, real y, real& u, real& v) const;

    /// offset the UV
    void OffsetUV(real x, real y, real& u, real& v) const;
};

/// @}

#endif