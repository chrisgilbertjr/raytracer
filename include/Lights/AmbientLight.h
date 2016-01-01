
#ifndef AMBIENT_LIGHT_H
#define AMBIENT_LIGHT_H

#include "Light.h"


/// @defgroup AmbientLight AmbientLight
/// @{

/// ambient light source
class AmbientLight : public Light
{
private:
    Color m_color;    /// color of the light
    real m_intensity; /// intensity of the light

public:
    /// constructor
    AmbientLight();

    /// constructor
    AmbientLight(const Color& color, const real intensity = 1.f);

    /// copy constructor
    AmbientLight(const AmbientLight& light);

    /// destructor
    virtual ~AmbientLight();

    /// copy assignment operator
    AmbientLight& operator=(AmbientLight light);

    /// clone an ambient light object
    virtual Light* Clone() const;

    /// get the direction of the light ray
    virtual Vector GetDirection(ShadeRecord& record);

    /// compute the radiance of the light
    virtual Color Radiance(ShadeRecord& record);
};

/// @}

#endif