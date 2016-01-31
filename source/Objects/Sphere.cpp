
#include "Objects\Sphere.h"

void 
Sphere::Quadratic(const Ray& ray, real& a, real& b, real& c, real& d) const
{
    a = Dot(ray.direction, ray.direction);
    b = 2.0f * Dot(ray.origin, ray.direction);
    c = Dot(ray.origin, ray.origin) - m_radius * m_radius;
    d = b * b - 4.0f * a * c;
}

Sphere::Sphere()
    : Object()
    , m_radius(1.0f)
{}

Sphere::Sphere(const Vector& center, real radius)
    : Object(center, Vector(0.f), 0.0f, 1.0f)
    , m_radius(radius)
{}

Sphere::~Sphere() {}

Sphere& 
Sphere::operator=(Sphere sphere)
{
    Object::operator=(sphere);
    Swap<real>(m_radius, sphere.m_radius);

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
    m_radius = radius;
}

Vector
Sphere::GetCenter() const
{
    return m_transform.GetPosition();
}

real
Sphere::GetRadius() const
{
    return m_radius;
}

Raycast
Sphere::Query(const Ray& ray, ShadeRecord& record) const
{
    Raycast result = Object::InitRaycastRecord(ray, record);
    Ray r = m_transform.TransformRaycast(ray);

    real a, b, c, d;
    Quadratic(r, a, b, c, d);

    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / 2.0f * a;
        real t = (-b - sDisc) * iDenom;

        if (t >= EPSILON)
        {
            Vector p = r.direction * t; /// world hit point
            Vector n = (r.origin + p) * (1.f / m_radius); /// world normal
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
            return result;
        }

        t = (-b + sDisc) * iDenom;

        if (t >= EPSILON)
        {
            Vector p = r.direction * t; /// world hit point
            Vector n = (r.origin + p) * (1.f / m_radius); /// world normal
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
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
    Sphere::Quadratic(r, a, b, c, d);

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