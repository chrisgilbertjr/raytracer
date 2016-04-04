
#include "Objects\Rectangle.h"

/// --------------------------------------------------------------------------- constructor

Rectangle::Rectangle()
    : Object()
{
    m_vertices[0] = Vector( 0.0f,  0.0f, 0.0f);
    m_vertices[1] = Vector( 0.0f,-10.0f, 0.0f);
    m_vertices[2] = Vector(10.0f,  0.0f, 0.0f);
    m_normal = Normalize(Cross(m_vertices[1], m_vertices[2]));
    m_v1Sq = m_vertices[1].LengthSquared();
    m_v2Sq = m_vertices[2].LengthSquared();
    m_area = Sqrt(m_v1Sq) * Sqrt(m_v2Sq);
}

/// --------------------------------------------------------------------------- constructor

Rectangle::Rectangle(const Vector& a, real width, real height, bool reverse)
    : Object()
{
    m_vertices[0] = a;
    m_vertices[1] = Vector( 0.0f,-height, 0.0f);
    m_vertices[2] = Vector(width,  0.0f, 0.0f);
    m_normal = Normalize(Cross(m_vertices[1], m_vertices[2]));
    m_v1Sq = m_vertices[1].LengthSquared();
    m_v2Sq = m_vertices[2].LengthSquared();
    m_area = Sqrt(m_v1Sq) * Sqrt(m_v2Sq);

    if (reverse)
    {
        m_normal = -m_normal;
    }
}

/// --------------------------------------------------------------------------- constructor

Rectangle::Rectangle(const Vector& a, const Vector& b, const Vector& c)
    : Object()
{
    m_vertices[0] = a;
    m_vertices[1] = b;
    m_vertices[2] = c;
    m_normal = Normalize(Cross(m_vertices[1], m_vertices[2]));
    m_v1Sq = m_vertices[1].LengthSquared();
    m_v2Sq = m_vertices[2].LengthSquared();
    m_area = Sqrt(m_v1Sq) * Sqrt(m_v2Sq);
}

/// --------------------------------------------------------------------------- copy constructor

Rectangle::Rectangle(const Rectangle& rect)
    : Object(rect)
    , m_normal(rect.m_normal)
    , m_v1Sq(rect.m_v1Sq)
    , m_v2Sq(rect.m_v2Sq)
    , m_area(rect.m_area)
{
    m_vertices[0] = rect.m_vertices[0];
    m_vertices[1] = rect.m_vertices[1];
    m_vertices[2] = rect.m_vertices[2];
}

/// --------------------------------------------------------------------------- destructor

Rectangle::~Rectangle() {}

/// --------------------------------------------------------------------------- copy assignment operator

Rectangle& 
Rectangle::operator=(Rectangle rect)
{
    /// copy and swap
    Object::operator=(rect);
    Swap<Vector>(m_vertices[0], rect.m_vertices[0]);
    Swap<Vector>(m_vertices[1], rect.m_vertices[1]);
    Swap<Vector>(m_vertices[2], rect.m_vertices[2]);
    Swap<Vector>(m_normal, rect.m_normal);
    Swap<real>(m_v1Sq, rect.m_v1Sq);
    Swap<real>(m_v2Sq, rect.m_v2Sq);
    Swap<real>(m_area, rect.m_area);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Object* 
Rectangle::Clone() const
{
    return static_cast<Object*>(new Rectangle(*this));
}

/// --------------------------------------------------------------------------- Query

Raycast 
Rectangle::Query(const Ray& ray, ShadeRecord& record) const
{
    /// transform raycast
    Raycast result = Object::InitRaycastRecord(ray, record);

    real t = Dot((m_vertices[0] - ray.origin), m_normal) / Dot(ray.direction, m_normal);

    if (t <= EPSILON)
    {
        return result;
    }

    /// check if the ray is outside of the rects limits
    Vector p = ray.origin + t * ray.direction;
    Vector d = p - m_vertices[0];

    real DoV1 = Dot(d, m_vertices[1]);

    if (DoV1 < 0.f || DoV1 > m_v1Sq)
    {
        return result;;
    }

    real DoV2 = Dot(d, m_vertices[2]);

    if (DoV2 < 0.f || DoV2 > m_v2Sq)
    {
        return result;;
    }

    /// collision
    AssignRaycastRecord(result, record, m_normal, p, t);
    ComputeUV(record);
    
    return result;
}

/// ---------------------------------------------------------------------------

bool 
Rectangle::ShadowHit(const Ray& ray, float& tmin) const
{
    real t = Dot((m_vertices[0] - ray.origin), m_normal) / Dot(ray.direction, m_normal);

    if (t <= shadowEpsilon)
    {
        return false;
    }

    /// check if the ray is outside of the rects limits
    Vector p = ray.origin + t * ray.direction;
    Vector d = p - m_vertices[0];

    real DoV1 = Dot(d, m_vertices[1]);

    if (DoV1 < 0.f || DoV1 > m_v1Sq)
    {
        return false;
    }

    real DoV2 = Dot(d, m_vertices[2]);

    if (DoV2 < 0.f || DoV2 > m_v2Sq)
    {
        return false;
    }

    /// collision
    return true;
}

/// ---------------------------------------------------------------------------

float 
Rectangle::pdf(const ShadeRecord& record) const
{
    return 1.f / m_area;
}

/// ---------------------------------------------------------------------------

void 
Rectangle::ComputeUV(ShadeRecord& record) const
{
    Vector nu = Normalize(m_vertices[2]);
    Vector nv = Normalize(m_vertices[1]);

    record.u = Dot(nv, record.localPoint) / Dot(nu, m_vertices[2]);
    record.v = Dot(nu, record.localPoint) / Dot(nv, m_vertices[1]);
}

/// ---------------------------------------------------------------------------
