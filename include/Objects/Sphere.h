
#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

/// a 3D sphere
class Sphere
{
private:
    Vector m_center; /// center in world space
    real   m_radius; /// radius of the sphere from the center

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

    /// virtual function for raycast queries
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;
};

#endif