
#include "Objects\Cylinder.h"

Cylinder::Cylinder()
    : m_center(0.f)
    , m_height(25.f)
    , m_radius(10.f)
{}

Cylinder::Cylinder(const Cylinder& cylinder)
    : Object(cylinder)
    , m_center(cylinder.m_center)
    , m_height(cylinder.m_height)
    , m_radius(cylinder.m_radius)
{}

Cylinder::Cylinder(const Vector& center, real height, real radius)
    : Object()
    , m_center(center)
    , m_height(height)
    , m_radius(radius)
{}

Cylinder::~Cylinder()
{}

Cylinder& 
Cylinder::operator=(Cylinder cylinder)
{
    Object::operator=(cylinder);
    Swap<Vector>(m_center, cylinder.m_center);
    Swap<real>(m_height, cylinder.m_height);
    Swap<real>(m_radius, cylinder.m_radius);

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
    //Ray r = ray;
    Ray r = m_transform.TransformRaycast(ray);
    Raycast result = Object::InitRaycastRecord(ray, record);

    real a, b, c, d;
    a = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
    b = 2.f * (r.direction.x * r.origin.x + r.direction.z * r.origin.z);
    c = r.origin.x * r.origin.x + r.origin.z * r.origin.z - m_radius * m_radius;
    d = b * b - 4.f * a * c;

    if (d >= 0.0f)
    {
        real sDisc = Sqrt(d);
        real iDenom = 1.0f / 2.0f * a;
        real t = (-b - sDisc) * iDenom;

        if (t >= EPSILON)
        {
            Vector p = ray.direction * t; /// local hit point
            Vector n = (r.origin + p) * (1.f / m_radius); /// world normal
            n.y = 0.0f;
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
            return result;
        }

        t = (-b + sDisc) * iDenom;

        if (t >= EPSILON)
        {
            Vector p = ray.direction * t; /// local hit point
            Vector n = (r.origin + p) * (1.f / m_radius); /// world normal
            n.y = 0.0f;
            AssignRaycastRecord(result, record, n, ray.origin + p, t);
            return result;
        }
    }

    return Raycast();
}

bool 
Cylinder::ShadowHit(const Ray& ray, float& tmin) const
{
    /// @TODO:
    return false;
}