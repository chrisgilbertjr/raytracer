
#ifndef PLANE_H
#define PLANE_H

#include "Object.h"

/// a 3D plane 
class Plane : public Object
{
private:
    Vector m_normal;
    Vector m_point; 

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

    /// virtual function for ray plane raycast queries
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    virtual bool ShadowHit(const Ray& ray, float& tmin) const;
};

#endif