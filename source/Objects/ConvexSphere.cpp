
#include "Objects\ConcaveSphere.h"

ConcaveSphere::ConcaveSphere()
    : Sphere()
{}

ConcaveSphere::ConcaveSphere(const Vector& center, real radius)
    : Sphere(center, radius)
{
}

ConcaveSphere::ConcaveSphere(const ConcaveSphere& sphere)
    : Sphere(sphere)
{}

ConcaveSphere::~ConcaveSphere() {}

ConcaveSphere& 
ConcaveSphere::operator=(ConcaveSphere sphere)
{
    Sphere::operator=(sphere);
    return *this;
}

Object* 
ConcaveSphere::Clone() const
{
    return static_cast<Object*>(new ConcaveSphere(*this));
}

Raycast 
ConcaveSphere::Query(const Ray& ray, ShadeRecord& record) const
{
    Ray r = m_transform.TransformRaycast(ray);
    Raycast result = Object::InitRaycastRecord(ray, record);

    real a, b, c, d;
    Sphere::Quadratic(r, a, b, c, d);

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

    //Raycast raycast = Sphere::Query(ray, record);
    //record.normal = -record.normal;
    //return raycast;
}

bool 
ConcaveSphere::ShadowHit(const Ray& ray, float& tmin) const
{
    return false;
}

float 
ConcaveSphere::pdf(const ShadeRecord& record) const
{
    return Sphere::pdf(record);
}