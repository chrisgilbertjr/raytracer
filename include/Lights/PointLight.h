
#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "Light.h"


/// @defgroup PointLight PointLight
/// @{

/// point light source
class PointLight : public Light
{
private:
    Vector m_position; /// position of the light
    Color m_color;     /// color of the light
    real m_intensity;  /// intensity of the light
    real m_radius;     /// radius of the light

    real Attenuation(real distance) const;

public:
    /// constructor
    PointLight();

    /// constructor
    PointLight(const Vector& position);

    /// constructor
    PointLight(const Color& color, const real intensity = 1.f);

    /// constructor
    PointLight(const Vector& position, const Color& color, real radius, real intensity = 1.f);

    /// copy assignment operator
    PointLight(const PointLight& light);

    /// destructor
    virtual ~PointLight();

    /// copy assignment operator
    PointLight& operator=(PointLight light);

    /// clone the direction of the light
    virtual Light* Clone() const;

    /// get the direction of the light
    virtual Vector GetDirection(ShadeRecord& record);

    /// compute the radiance of the light
    virtual Color Radiance(ShadeRecord& record);
};

/// @}

#endif