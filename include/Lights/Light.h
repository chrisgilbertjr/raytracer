
#ifndef LIGHT_H
#define LIGHT_H

#include "..\Core\MathUtils.h"
#include "..\Core\Color.h"

/// @defgroup Light Light
/// @{

/// forward declaration
struct ShadeRecord;

/// base class for all lights
class Light
{
protected:
    /// default constructor
    Light();

    bool m_shadows; /// can this light cast shadows

public:
    /// destructor
    virtual ~Light();

    /// clone a light object
    virtual Light* Clone() const = 0;

    /// get the direction of the light source
    virtual Vector GetDirection(ShadeRecord& record) = 0;

    /// compute the radiance of the light
    virtual Color Radiance(ShadeRecord& record) = 0;

    /// check if the light casts a shadow
    virtual bool CastsShadow() const = 0;

    /// test a ray to see if the hit point is in a shadow
    virtual bool InShadow(const Ray& ray, ShadeRecord& record) const = 0;

    ///
    virtual real G(const ShadeRecord& record) const;

    ///
    virtual real pdf(const ShadeRecord& record) const;

    /// set if the light can cast shadows
    void CastShadows(bool shadows);
};

/// --------------------------------------------------------------------------- CastShadows

inline void 
Light::CastShadows(bool shadows)
{
    m_shadows = shadows;
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif