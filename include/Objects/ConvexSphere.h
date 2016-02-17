
#ifndef CONVEX_SPHERE_H
#define CONVEX_SPHERE_H

#include "Sphere.h"

class ConvexSphere : public Sphere
{
public:
    ConvexSphere();

    ConvexSphere(const Vector& center, real radius);

    ConvexSphere(const ConvexSphere& sphere);

    virtual ~ConvexSphere();

    ConvexSphere& operator=(ConvexSphere sphere);

    virtual Object* Clone() const;

    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    virtual float pdf(const ShadeRecord& record) const;
};

#endif