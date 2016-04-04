
#include "Objects\Plane.h"

/// default based on camera position
static float s_planeTextureScale =  1.f / 500.f;

/// --------------------------------------------------------------------------- Quadratic

real
Plane::Quadtratic(const Ray& ray, const Vector& normal) const
{
    return Dot((m_transform.GetPosition() - ray.origin), normal) / Dot(ray.direction, normal);
}

/// --------------------------------------------------------------------------- constructor

Plane::Plane()
    : Object()
    , m_normal(0.0f, 1.f, 0.f)
{}

/// --------------------------------------------------------------------------- copy constructor

Plane::Plane(const Plane& plane)
    : Object(plane)
    , m_normal(plane.m_normal)
{}

/// --------------------------------------------------------------------------- constructor

Plane::Plane(const Vector& point, const Vector& normal)
    : Object(point, Vector(0.f), 0.0f, 1.0f)
    , m_normal(Normalize(normal))
{
}

/// --------------------------------------------------------------------------- constructor

Plane::Plane(const Vector& normal, real offset)
{
    Assert(false);
    /// @TODO:
}

/// --------------------------------------------------------------------------- destructor

Plane::~Plane() {}

/// --------------------------------------------------------------------------- copy assignment operator

Plane& 
Plane::operator=(Plane plane)
{
    /// copy and swap
    Object::operator=(plane);
    Swap<Vector>(m_normal, m_normal);

    return *this;
}

/// --------------------------------------------------------------------------- Query

Raycast 
Plane::Query(const Ray& ray, ShadeRecord& record) const
{
    /// transform raycast
    Raycast result = Object::InitRaycastRecord(ray, record);

    real t = Quadtratic(ray, m_normal);

    if (t >= EPSILON)
    {
        /// collision
        AssignRaycastRecord(result, record, m_normal, ray.origin + ray.direction * t, t);
        ComputeUV(record);
    }

    return result;
}

/// --------------------------------------------------------------------------- ShadowHit

bool 
Plane::ShadowHit(const Ray& ray, float& tmin) const
{
    /// transform raycast
    real t = Quadtratic(ray, m_normal);

    if (t > shadowEpsilon)
    {
        /// collision
        tmin = t;
        return true;
    }

    return false;
}

/// --------------------------------------------------------------------------- ComputeUV

void 
Plane::ComputeUV(ShadeRecord& record) const
{
    Vector nu = Normalize(Vector( m_normal.x, -m_normal.z, m_normal.y));
    Vector nv = Normalize(Vector( m_normal.y, -m_normal.x, m_normal.z));

    record.u = Dot(nu, record.localPoint) * s_planeTextureScale;
    record.v = Dot(nv, record.localPoint) * s_planeTextureScale;
}

/// --------------------------------------------------------------------------- EOF
