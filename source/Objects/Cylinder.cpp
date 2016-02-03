
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
    return Raycast();
}

bool 
Cylinder::ShadowHit(const Ray& ray, float& tmin) const
{
    /// @TODO:
    return false;
}