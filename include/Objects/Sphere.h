
#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

/// a 3D sphere
class Sphere : public Object
{
private:
    real   m_radius; /// radius of the sphere from the center

    /// compute quadtradic coeff
    void Quadratic(const Ray& ray, real& a, real& b, real& c, real& d) const;

public:
    /// default constructor. center = (0,0,0) and radius = 0
    Sphere();

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

    /// virtual function for raycast queries
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    virtual bool ShadowHit(const Ray& ray, float& tmin) const;
};

#endif