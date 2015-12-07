
#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

/// a 3D plane 
class Plane
{
private:
    /// a plane represented by a point in world space and a normal
    Vector m_point, m_normal;

public:
    /// default constructor. point = (0,0,0) and normal (0,1,0)
    Plane();

    /// constructor
    Plane(const Plane& plane);

    /// constructor given a point and normal
    Plane(const Vector& point, const Vector& normal);

    /// constructor given a normal and offset (d value)
    Plane(const Vector& normal, real offset);

    /// virtual destructor
    virtual ~Plane();

    /// assignment operator
    Plane& operator=(const Plane& plane);

    /// virtual function for ray plane raycast queries
    virtual Raycast Query(const Ray& ray) const;
};

#endif