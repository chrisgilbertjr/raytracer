
#ifndef LIGHT_H
#define LIGHT_H

#include "..\Core\MathUtils.h"
#include "..\Core\Color.h"

/// forward declaration
class ShadeRecord;

/// base class for all lights
class Light
{
public:
    /// default constructor
    Light();

    /// copy constructor
    Light(const Light& light);

    /// destructor
    virtual ~Light();

    /// nothing to copy, I dont not need to use copy and swap
    /// so i can use pure virtual functions here.
    Light& operator=(const Light& light);

    /// clone a light onject
    virtual Light* Clone() const = 0;

    /// get the direction of the light source
    virtual Vector GetDirection(ShadeRecord& record) = 0;

    /// compute the radiance of the light
    virtual Color L(ShadeRecord& record) = 0;
};

#endif