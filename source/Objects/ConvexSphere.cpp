
#include "Objects\ConvexSphere.h"

ConvexSphere::ConvexSphere()
    : Sphere()
{}

ConvexSphere::ConvexSphere(const Vector& center, real radius)
    : Sphere(center, radius)
{
}

ConvexSphere::ConvexSphere(const ConvexSphere& sphere)
    : Sphere(sphere)
{}

ConvexSphere::~ConvexSphere() {}

ConvexSphere& 
ConvexSphere::operator=(ConvexSphere sphere)
{
    Sphere::operator=(sphere);
    return *this;
}

Object* 
ConvexSphere::Clone() const
{
    return static_cast<Object*>(new ConvexSphere(*this));
}

Raycast 
ConvexSphere::Query(const Ray& ray, ShadeRecord& record) const
{
    Raycast raycast = Sphere::Query(ray, record);
    record.normal = -record.normal;
    return raycast;
}

bool 
ConvexSphere::ShadowHit(const Ray& ray, float& tmin) const
{
    return Sphere::ShadowHit(ray, tmin);
}

float 
ConvexSphere::pdf(const ShadeRecord& record) const
{
    return Sphere::pdf(record);
}