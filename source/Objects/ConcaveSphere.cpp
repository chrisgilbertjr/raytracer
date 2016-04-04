
#include "Objects\ConcaveSphere.h"

/// --------------------------------------------------------------------------- constructor

ConcaveSphere::ConcaveSphere()
    : Sphere()
{}

/// --------------------------------------------------------------------------- constructor

ConcaveSphere::ConcaveSphere(const Vector& center, real radius)
    : Sphere(center, radius)
{
}

/// --------------------------------------------------------------------------- copy constructor

ConcaveSphere::ConcaveSphere(const ConcaveSphere& sphere)
    : Sphere(sphere)
{}

/// --------------------------------------------------------------------------- destructor

ConcaveSphere::~ConcaveSphere() {}

/// --------------------------------------------------------------------------- copy assignment operator

ConcaveSphere& 
ConcaveSphere::operator=(ConcaveSphere sphere)
{
    Sphere::operator=(sphere);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Object* 
ConcaveSphere::Clone() const
{
    return static_cast<Object*>(new ConcaveSphere(*this));
}

/// --------------------------------------------------------------------------- Query

Raycast 
ConcaveSphere::Query(const Ray& ray, ShadeRecord& record) const
{
    Ray r = m_transform.TransformRaycast(ray);
    Raycast result = Object::InitRaycastRecord(ray, record);

    /// quad coeffs
    real a, b, c, d;
    Sphere::Quadratic(r, a, b, c, d);

    /// check for intersections
    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / 2.0f * a;
        real t = (-b - sDisc) * iDenom;

        if (t >= EPSILON)
        {
            Vector p = ray.direction * t; /// local hit point
            Vector n = -1 * (r.origin + p) * (1.f / GetRadius()); /// world normal
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
            return result;
        }

        t = (-b + sDisc) * iDenom;

        if (t >= EPSILON)
        {
            Vector p = ray.direction * t; /// local hit point
            Vector n = -1 * (r.origin + p) * (1.f / GetRadius()); /// world normal
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
            return result;
        }
    }

    /// no hits, return false
    return result;

}

/// --------------------------------------------------------------------------- ShadowHit

bool 
ConcaveSphere::ShadowHit(const Ray& ray, float& tmin) const
{
    return false;
}

/// --------------------------------------------------------------------------- pdf

float 
ConcaveSphere::pdf(const ShadeRecord& record) const
{
    return Sphere::pdf(record);
}

/// --------------------------------------------------------------------------- EOF