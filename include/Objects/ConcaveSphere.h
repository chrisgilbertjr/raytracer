
#ifndef CONVEX_SPHERE_H
#define CONVEX_SPHERE_H

#include "Sphere.h"

/// @defgroup ConcaveSphere ConcaveSphere
/// @{

/// convex sphere used for skyboxes and environment lights
class ConcaveSphere : public Sphere
{
public:
    /// constructor
    ConcaveSphere();

    /// constructor
    ConcaveSphere(const Vector& center, real radius);

    /// copy constructor
    ConcaveSphere(const ConcaveSphere& sphere);

    /// destructor
    virtual ~ConcaveSphere();

    /// copy assignment operator
    ConcaveSphere& operator=(ConcaveSphere sphere);

    /// deep copy this object
    virtual Object* Clone() const;

    /// query this object for ray-intersections
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    /// query this object with shadow rays
    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    /// inverse area 
    virtual float pdf(const ShadeRecord& record) const;
};

/// @}

#endif