
#ifndef SPHERE_LIGHT_H
#define SPHERE_LIGHT_H

#include "LightObject.h"

/// @defgroup SphereLight SphereLight
/// @{

/// sphere used for area lighting
class SphereLight : LightObject
{
public:
    /// constructor
    SphereLight();

    /// constructor
    SphereLight(Object* object);

    /// constructor
    SphereLight(Object* object, Sampler* sampler);

    /// copy constructor
    SphereLight(const SphereLight& light);

    /// destructor
    virtual ~SphereLight();

    /// copy assignment operator
    SphereLight& operator=(SphereLight light);

    /// deep copy of this object
    virtual LightObject* Clone() const;

    /// get a sample point on the sphere
    virtual Vector Sample() const;

    /// get a normal on the sphere given a point
    virtual Vector GetNormal(const Vector& point) const;

    /// invert area of the sphere
    virtual real pdf(const ShadeRecord& record) const;
};

/// @}

#endif