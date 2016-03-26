
#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

/// @defgroup Sphere Sphere
/// @{

/// a 3D sphere
class Sphere : public Object
{
protected:
    /// compute quadtradic coeff
    void Quadratic(const Ray& ray, real& a, real& b, real& c, real& d) const;

public:
    /// default constructor. center = (0,0,0) and radius = 0
    Sphere();

    /// copy constructor
    Sphere(const Sphere& sphere);

    /// constructor given a sphere center and a radius
    Sphere(const Vector& center, real radius);

    /// set the center of the sphere
    void SetCenter(const Vector& center);

    /// set the radius of the circle
    void SetRadius(float radius);

    /// get the center of the sphere
    Vector GetCenter() const;

    /// get the radius of the sphere
    real GetRadius() const;

    /// virtual destructor
    virtual ~Sphere();

    /// copy assignment operator
    Sphere& operator=(Sphere sphere);

    /// clone this object, deep copy
    virtual Object* Clone() const;

    /// query this object for ray-intersections
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    /// query this object with shadow rays
    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    /// inverse area of the object
    virtual float pdf(const ShadeRecord& record) const;

    /// compute the UV's of an object
    virtual void ComputeUV(ShadeRecord& record) const;
};

/// @}

#endif