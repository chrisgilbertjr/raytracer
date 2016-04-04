
#include "Objects\Sphere.h"

/// --------------------------------------------------------------------------- Quadratic

void 
Sphere::Quadratic(const Ray& ray, real& a, real& b, real& c, real& d) const
{
    a = Dot(ray.direction, ray.direction);
    b = 2.0f * Dot(ray.origin, ray.direction);
    c = Dot(ray.origin, ray.origin) - GetRadius() * GetRadius();
    d = b * b - 4.0f * a * c;
}

/// --------------------------------------------------------------------------- constructor

Sphere::Sphere()
    : Object(Vector(0.0f), Vector(0.f), 0.0f, 1.0f)
{}

/// --------------------------------------------------------------------------- copy constructor

Sphere::Sphere(const Sphere& sphere)
    : Object(sphere.GetCenter(), Vector(0.f), 0.0f, sphere.GetRadius())
{}

/// --------------------------------------------------------------------------- constructor

Sphere::Sphere(const Vector& center, real radius)
    : Object(center, Vector(0.f), 0.0f, radius) 
{}

/// --------------------------------------------------------------------------- destructor

Sphere::~Sphere() {}

/// --------------------------------------------------------------------------- copy assignment operator

Sphere& 
Sphere::operator=(Sphere sphere)
{
    Object::operator=(sphere);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Object* 
Sphere::Clone() const
{
    return static_cast<Object*>(new Sphere(*this));
}

/// --------------------------------------------------------------------------- SetCenter

void
Sphere::SetCenter(const Vector& center)
{
    m_transform.SetPosition(center);
}

/// --------------------------------------------------------------------------- SetRadius

void
Sphere::SetRadius(float radius)
{
    m_transform.m[ 0] = radius;
    m_transform.m[ 5] = radius;
    m_transform.m[10] = radius;
}

/// --------------------------------------------------------------------------- GetCenter

Vector
Sphere::GetCenter() const
{
    return m_transform.GetPosition();
}

/// --------------------------------------------------------------------------- GetRadius

real
Sphere::GetRadius() const
{
    return m_transform.m[0];
}

/// --------------------------------------------------------------------------- Query

Raycast
Sphere::Query(const Ray& ray, ShadeRecord& record) const
{
    /// transform raycast
    Ray r = m_transform.TransformRaycast(ray);
    Raycast result = Object::InitRaycastRecord(ray, record);

    /// quad coeffs
    real a, b, c, d;
    Quadratic(r, a, b, c, d);

    /// check for collisions
    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / 2.0f * a;
        real t = (-b - sDisc) * iDenom;

        if (t >= EPSILON)
        {
            /// collision
            Vector p = ray.direction * t; /// local hit point
            Vector n = (r.origin + p) * (1.f / GetRadius()); /// world normal
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
            ComputeUV(record);
            return result;
        }

        t = (-b + sDisc) * iDenom;

        if (t >= EPSILON)
        {
            /// collision
            Vector p = ray.direction * t; /// local hit point
            Vector n = (r.origin + p) * (1.f / GetRadius()); /// world normal
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
            ComputeUV(record);
            return result;
        }
    }

    /// no hits, return false
    return result;
}

/// --------------------------------------------------------------------------- ShadowHit

bool 
Sphere::ShadowHit(const Ray& ray, float& tmin) const
{
    /// transform raycast
    Ray r = m_transform.TransformRaycast(ray);

    /// quad coeffs
    real a, b, c, d;
    Quadratic(r, a, b, c, d);

    /// check for collisions
    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / 2.0f * a;
        real t = (-b - sDisc) * iDenom;

        if (t >= shadowEpsilon)
        {
            /// collision
            tmin = t;
            return true;
        }

        t = (-b + sDisc) * iDenom;

        if (t >= shadowEpsilon)
        {
            /// collision
            tmin = t;
            return true;
        }
    }

    return false;
}

/// --------------------------------------------------------------------------- pdf

float 
Sphere::pdf(const ShadeRecord& record) const
{
    return 1.f / (Pi * GetRadius() * GetRadius());
}

/// --------------------------------------------------------------------------- ComputeUV

void 
Sphere::ComputeUV(ShadeRecord& record) const
{
    Vector p = Normalize(record.localPoint - GetCenter());

    real theta = Acos(p.y);
    real phi = atan2(p.x, p.z);

    if (phi <= 0.f)
    {
        phi += 2.f * Pi;
    }

    record.u = phi / (2.f * Pi);
    record.v = 1.f - theta * InvPi;
}

/// --------------------------------------------------------------------------- EOF