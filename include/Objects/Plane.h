
#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

/// @defgroup Plane Plane
/// @{

/// a 3D plane 
class Plane : public Object
{
private:
    Vector m_normal; /// normal of the plane

    /// compute the quadratic coeffs
    real Quadtratic(const Ray& ray, const Vector& normal) const;

public:
    /// default constructor. point = (0,0,0) and normal (0,1,0)
    Plane();

    /// constructor
    Plane(const Plane& plane);

    /// constructor given a point and normal
    Plane(const Vector& point, const Vector& normal);

    /// constructor given a normal and offset 
    Plane(const Vector& normal, real offset);

    /// virtual destructor
    virtual ~Plane();

    /// assignment operator
    Plane& operator=(Plane plane);

    /// query this object for ray-intersections
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    /// query this object with shadow rays
    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    /// compute the UV's of an object
    virtual void ComputeUV(ShadeRecord& record) const;
};

/// @}

#endif