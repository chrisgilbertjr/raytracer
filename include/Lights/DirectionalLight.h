
#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "Light.h"


/// @defgroup DirectionLight DirectionalLight
/// @{

/// directional light source
class DirectionalLight : public Light
{
private:
    Vector m_direction; /// direction of the light
    Color m_color;      /// color of the light
    real m_intensity;   /// intensity of the light

public:
    /// constructor
    DirectionalLight();

    /// constructor
    DirectionalLight(const Vector& direction);

    /// constructor
    DirectionalLight(const Color& color, const real intensity = 1.f);

    /// constructor
    DirectionalLight(const Vector& direction, const Color& color, const real intensity = 1.f);

    /// copy assignment operator
    DirectionalLight(const DirectionalLight& light);

    /// destructor
    virtual ~DirectionalLight();

    /// copy assignment operator
    DirectionalLight& operator=(DirectionalLight light);

    /// clone the direction of the light
    virtual Light* Clone() const;

    /// get the direction of the light
    virtual Vector GetDirection(ShadeRecord& record);

    /// compute the radiance of the light
    virtual Color Radiance(ShadeRecord& record);
};

/// @}

#endif