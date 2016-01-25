
#include "Objects\Plane.h"

Plane::Plane()
    : m_normal(0.0f, 1.f, 0.f)
    , m_point(0.f)
{}

Plane::Plane(const Plane& plane)
    : m_normal(plane.m_normal)
    , m_point(plane.m_point)
{}

Plane::Plane(const Vector& point, const Vector& normal)
    : m_normal(Normalize(normal))
    , m_point(point)
{
}

Plane::Plane(const Vector& normal, real offset)
{
    Assert(false);
    /// @TODO:
}

Plane::~Plane()
{}

Plane& 
Plane::operator=(Plane plane)
{
    Object::operator=(plane);
    Swap<Vector>(m_normal, m_normal);
    Swap<Vector>(m_point, m_point);
    return *this;
}

Raycast 
Plane::Query(const Ray& ray, ShadeRecord& record) const
{
    Raycast result;
    result.ray = ray;
    result.hit = record.hit = false;
    result.t = record.t = 0.0f;
    record.normal = record.localPoint = m_normal;

    real quadtratic = Dot((m_point - ray.origin), m_normal) / Dot(ray.direction, m_normal);

    if (quadtratic >= EPSILON)
    {
        record.localPoint = ray.origin + ray.direction * quadtratic;
        result.t = record.t = quadtratic;
        result.hit = record.hit = true;
    }

    return result;
}
