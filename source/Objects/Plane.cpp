
#include "Objects\Plane.h"

real
Plane::Quadtratic(const Ray& ray, const Vector& normal) const
{
    return Dot((m_transform.GetPosition() - ray.origin), normal) / Dot(ray.direction, normal);
}

Plane::Plane()
    : Object()
    , m_normal(0.0f, 1.f, 0.f)
{}

Plane::Plane(const Plane& plane)
    : Object(plane)
    , m_normal(plane.m_normal)
{}

Plane::Plane(const Vector& point, const Vector& normal)
    : Object(point, Vector(0.f), 0.0f, 1.0f)
    , m_normal(Normalize(normal))
{
}

Plane::Plane(const Vector& normal, real offset)
{
    Assert(false);
    /// @TODO:
}

Plane::~Plane() {}

Plane& 
Plane::operator=(Plane plane)
{
    Object::operator=(plane);
    Swap<Vector>(m_normal, m_normal);

    return *this;
}

Raycast 
Plane::Query(const Ray& ray, ShadeRecord& record) const
{
    Raycast result = Object::InitRaycastRecord(ray, record);

    real t = Quadtratic(ray, m_normal);

    if (t >= EPSILON)
    {
        AssignRaycastRecord(result, record, m_normal, ray.origin + ray.direction * t, t);
    }

    return result;
}

bool 
Plane::ShadowHit(const Ray& ray, float& tmin) const
{
    real t = Quadtratic(ray, m_normal);

    if (t > shadowEpsilon)
    {
        tmin = t;
        return true;
    }

    return false;
}
