
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
    Vector origin = ray.origin;
    Vector direction = ray.direction;

    real ox = origin.x;
    real oy = origin.y;
    real oz = origin.z;
    real dx = direction.x;
    real dy = direction.y;
    real dz = direction.z;

    Raycast result;
    result.ray.origin = origin;
    result.ray.direction = direction;
    result.hit = record.hit = false;
    result.t = record.t = 0.f;
    record.normal = record.localPoint = Vector(0.0f, 0.0f, 0.0f);

    real a = dx * dx + dz * dz;
    real b = 2.0f * (ox * dx + oz * dz);
    real c = ox * ox + oz * oz - m_radius * m_radius;
    real discriminant = b * b - 4.0f * a * c;

    if (discriminant >= 0.0f)
    {
        real invRadius = 1.f / m_radius;
        real sDiscriminant = Sqrt(discriminant);
        real invDenominator = 1.0f / 2.0f * a;
        for (real i = -1.0f; i < 2.0f; i += 2.0f)
        {
            real quadtratic = (-b + sDiscriminant * i) * invDenominator;

            if (quadtratic >= EPSILON)
            {
                //real y = oy + (quadtratic * dy);

                //if (y > -m_height && y < m_height)
                //{                
                    result.t = record.t = quadtratic;
                    //record.normal = Normalize(Vector((ox + quadtratic * dx) * m_radius, 0.f, (oz + quadtratic * dz) * m_radius));
                    record.normal = Normalize(Vector((ox + quadtratic * dx) * invRadius, 0.f, (oz + quadtratic * dz) * invRadius));

                    if (Dot(-direction, record.normal) < 0.0f)
                    {
                        record.normal = -record.normal;
                    }
                    record.localPoint = origin + direction * quadtratic;
                    result.hit = record.hit = true;

                    return result;
                //}
            }
        }
    }
    /// no hits, return false
    return result;
}