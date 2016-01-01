
#ifndef LIGHT_H
#define LIGHT_H

#include "..\Core\MathUtils.h"
#include "..\Core\Color.h"

/// forward declaration
class ShadeRecord;

/// base class for all lights
class Light
{
protected:
    /// default constructor
    Light();

public:
    /// destructor
    virtual ~Light();

    /// clone a light object
    virtual Light* Clone() const = 0;

    /// get the direction of the light source
    virtual Vector GetDirection(ShadeRecord& record) = 0;

    /// compute the radiance of the light
    virtual Color Radiance(ShadeRecord& record) = 0;
};

#endif