
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
Sphere::Query(const Ray& ray) const
{
    Raycast result;
    result.hit = false;
    result.tmin = result.t = 0.0f;
    result.normal = result.localPoint = Vector(0.0f);

    Vector tmp = ray.o - m_center;
    real a = Dot(ray.d, ray.d);
    real b = 2.0f * Dot(tmp, ray.d);
    real c = Dot(tmp, tmp) - m_radius * m_radius;
    real discriminant = b * b - 4.0f * a * c;

    if (discriminant >= 0.0f)
    {
        for (real i = -1.0f; i != 1.0f; i = 1.0f)
        {
            real sDiscriminant = Sqrt(discriminant);
            real denominator = 2.0f * a;
            real quadtratic = (-b + sDiscriminant * i) / denominator;

            if (quadtratic > EPSILON)
            {
                Vector mag = ray.d * quadtratic;
                result.tmin = result.t = quadtratic;
                result.normal = (tmp + mag) *  (1.0f/m_radius);
                result.localPoint = ray.o + mag;
                result.hit = true;
            }
        }
    }
    /// no hits, return false
    return result;
}