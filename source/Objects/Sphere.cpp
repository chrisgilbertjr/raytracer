
#include "Objects\Sphere.h"

void 
Sphere::Quadratic(const Ray& ray, real& a, real& b, real& c, real& d) const
{
    a = Dot(ray.direction, ray.direction);
    b = 2.0f * Dot(ray.origin, ray.direction);
    c = Dot(ray.origin, ray.origin) - GetRadius() * GetRadius();
    d = b * b - 4.0f * a * c;
}

Sphere::Sphere()
    : Object(Vector(0.0f), Vector(0.f), 0.0f, 1.0f)
{}

Sphere::Sphere(const Sphere& sphere)
    : Object(sphere.GetCenter(), Vector(0.f), 0.0f, sphere.GetRadius())
{}

Sphere::Sphere(const Vector& center, real radius)
    : Object(center, Vector(0.f), 0.0f, radius) 
{}

Sphere::~Sphere() {}

Sphere& 
Sphere::operator=(Sphere sphere)
{
    Object::operator=(sphere);

    return *this;
}

Object* 
Sphere::Clone() const
{
    return static_cast<Object*>(new Sphere(*this));
}

void
Sphere::SetCenter(const Vector& center)
{
    m_transform.SetPosition(center);
}

void
Sphere::SetRadius(float radius)
{
    m_transform.m[ 0] = radius;
    m_transform.m[ 5] = radius;
    m_transform.m[10] = radius;
}

Vector
Sphere::GetCenter() const
{
    return m_transform.GetPosition();
}

real
Sphere::GetRadius() const
{
    return m_transform.m[0];
}

Raycast
Sphere::Query(const Ray& ray, ShadeRecord& record) const
{
    Ray r = m_transform.TransformRaycast(ray);
    Raycast result = Object::InitRaycastRecord(ray, record);

    real a, b, c, d;
    Quadratic(r, a, b, c, d);

    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / 2.0f * a;
        real t = (-b - sDisc) * iDenom;

        if (t >= EPSILON)
        {
            Vector p = ray.direction * t; /// local hit point
            Vector n = (r.origin + p) * (1.f / GetRadius()); /// world normal
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
            ComputeUV(record);
            return result;
        }

        t = (-b + sDisc) * iDenom;

        if (t >= EPSILON)
        {
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

bool 
Sphere::ShadowHit(const Ray& ray, float& tmin) const
{
    Ray r = m_transform.TransformRaycast(ray);

    real a, b, c, d;
    Quadratic(r, a, b, c, d);

    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / 2.0f * a;
        real t = (-b - sDisc) * iDenom;

        if (t >= shadowEpsilon)
        {
            tmin = t;
            return true;
        }

        t = (-b + sDisc) * iDenom;

        if (t >= shadowEpsilon)
        {
            tmin = t;
            return true;
        }
    }

    return false;
}

float 
Sphere::pdf(const ShadeRecord& record) const
{
    return 1.f / (Pi * GetRadius() * GetRadius());
}

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