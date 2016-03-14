
#include "Objects\Cylinder.h"

void 
Cylinder::Quadratic(const Ray& r, real& a, real& b, real& c, real& d) const
{
    a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
    b = 2.f * (r.direction.x * r.origin.x + r.direction.z * r.origin.z);
    c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - m_radius * m_radius;
    d = b * b - 4.f * a * c;
}

Cylinder::Cylinder()
    : m_center(0.f)
    , m_radius(10.f)
    , m_min(0.f)
    , m_max(25.f)
{}

Cylinder::Cylinder(const Cylinder& cylinder)
    : Object(cylinder)
    , m_center(cylinder.m_center)
    , m_radius(cylinder.m_radius)
    , m_min(cylinder.m_min)
    , m_max(cylinder.m_max)
{
}

Cylinder::Cylinder(const Vector& center, real height, real radius)
    : Object()
    , m_center(center)
    , m_radius(radius)
    , m_min(0.0f)
    , m_max(height)
{
}

Cylinder::Cylinder(const Vector& center, real min, real max, real radius)
    : Object()
    , m_center(center)
    , m_radius(radius)
    , m_min(min)
    , m_max(max)
{
    m_transform.SetPosition(center);
}

Cylinder::~Cylinder()
{}

Cylinder& 
Cylinder::operator=(Cylinder cylinder)
{
    Object::operator=(cylinder);
    Swap<Vector>(m_center, cylinder.m_center);
    Swap<real>(m_radius, cylinder.m_radius);
    Swap<real>(m_min, cylinder.m_min);
    Swap<real>(m_max, cylinder.m_max);

    return *this;
}

Object* 
Cylinder::Clone() const
{
    return static_cast<Object*>(new Cylinder(*this));
}

Raycast 
Cylinder::Query(const Ray& ray, ShadeRecord& record) const
{
    Ray r = m_transform.TransformRaycast(ray);
    Raycast result = Object::InitRaycastRecord(ray, record);

    real a, b, c, d;
    Quadratic(r, a, b, c, d);

    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / (2.0f * a);
        real t = (-b - sDisc) * iDenom;

        if (t >= EPSILON)
        {
            real y = r.origin.y + t * r.direction.y;

            if (y > m_min && y < m_max)
            {
                Vector p = ray.direction * t;
                Vector n = Normalize(Vector((r.origin.x + t * r.direction.x) * (1.f/m_radius), 0.0f, (r.origin.z + t * r.direction.z) * (1.f/m_radius)));

                if (Dot(-r.direction, n) < 0.f)
                {
                    n = -n;
                }

                AssignRaycastRecord(result, record, n, ray.origin + p, t);
                ComputeUV(record);
                return result;
            }
        }

        t = (-b + sDisc) * iDenom;

        if (t >= EPSILON)
        {
            real y = r.origin.y + t * r.direction.y;

            if (y > m_min && y < m_max)
            {
                Vector p = ray.direction * t; 
                Vector n = Normalize(Vector((r.origin.x + t * r.direction.x) * (1.f / m_radius), 0.0f, (r.origin.z + t * r.direction.z) * (1.f / m_radius)));

                if (Dot(-r.direction, n) < 0.f)
                {
                    n = -n;
                }

                AssignRaycastRecord(result, record, n, ray.origin + p, t);
                ComputeUV(record);
                return result;
            };
        }
    }

    return result;
}

bool 
Cylinder::ShadowHit(const Ray& ray, float& tmin) const
{
    Ray r = m_transform.TransformRaycast(ray);

    real a, b, c, d;
    Quadratic(r, a, b, c, d);

    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / (2.0f * a);
        real t = (-b - sDisc) * iDenom;

        if (t >= shadowEpsilon)
        {
            real y = r.origin.y + t * r.direction.y;

            if (y > m_min && y < m_max)
            {
                tmin = t;
                return true;
            }
        }

        t = (-b + sDisc) * iDenom;

        if (t >= shadowEpsilon)
        {
            real y = r.origin.y + t * r.direction.y;

            if (y > m_min && y < m_max)
            {
                tmin = t;
                return true;
            }
        }
    }

    return false;
}

void 
Cylinder::ComputeUV(ShadeRecord& record) const
{
    Vector p = record.localPoint - m_center;

    real phi = atan2(p.x, p.z);

    if (phi <= 0.f)
    {
        phi += 2.f * Pi;
    }

    record.u = phi / (2.f * Pi);
    record.v = ((p.y + 1.f) / 2.f) / (m_max - m_min);
}