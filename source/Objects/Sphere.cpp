
#include "Objects\Sphere.h"

Sphere::Sphere()
    : m_center(Vector(0.0f))
    , m_radius(1.0f)
{
}

Sphere::Sphere(const Vector& center, real radius)
    : m_center(center)
    , m_radius(radius)
{
}

Sphere::~Sphere() {}

void
Sphere::SetCenter(const Vector& center)
{
    m_center = center;
}

void
Sphere::SetRadius(float radius)
{
    m_radius = radius;
}

Vector
Sphere::GetCenter() const
{
    return m_center;
}

real
Sphere::GetRadius() const
{
    return m_radius;
}

Raycast
Sphere::Query(const Ray& ray, ShadeRecord& record) const
{
    Raycast result;
    result.ray = ray;
    result.hit = record.hit = false;
    result.t = record.t = 0.0f;
    record.normal = record.localPoint = Vector(0.0f);

    Vector tmp = ray.origin - m_center;
    real a = Dot(ray.direction, ray.direction);
    real b = 2.0f * Dot(tmp, ray.direction);
    real c = Dot(tmp, tmp) - m_radius * m_radius;
    real discriminant = b * b - 4.0f * a * c;

    if (discriminant >= 0.0f)
    {
        real sDiscriminant = Sqrt(discriminant);
        real invDenominator = 1.0f / 2.0f * a;
        for (real i = -1.0f; i < 2.0f; i += 2.0f)
        {
            real quadtratic = (-b + sDiscriminant * i) * invDenominator;

            if (quadtratic >= EPSILON)
            {
                Vector mag = ray.direction * quadtratic;
                record.normal = (tmp + mag) * (1.0f/m_radius);
                record.localPoint = ray.origin + mag;
                result.t = record.t = quadtratic;
                result.hit = record.hit = true;
                return result;
            }
        }
    }
    /// no hits, return false
    return result;
}