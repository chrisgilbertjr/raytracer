
#include "Objects\Object.h"

/// --------------------------------------------------------------------------- Constructor

Object::Object()
    : m_material(NULL)
{
    SetTransform(Vector(0.f), Vector(0.f), 0.0f, 1.0f);
}

/// --------------------------------------------------------------------------- Constructor

Object::Object(const Vector& position, const Vector& axis, real angle, real scale)
    : m_material(NULL)
{
    SetTransform(position, axis, angle, scale);
}

/// --------------------------------------------------------------------------- Copy constructor

Object::Object(const Object& object)
    : m_material(object.m_material)
    , m_transform(object.m_transform)
{}

/// --------------------------------------------------------------------------- Destructor

Object::~Object() {}

/// --------------------------------------------------------------------------- Copy assignment operator

Object& 
Object::operator=(Object object)
{
    Swap<Material*>(m_material, object.m_material);
    Swap<Matrix>(m_transform, object.m_transform);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Object* 
Object::Clone() const
{
    Assert(false);
    return NULL;
}

/// --------------------------------------------------------------------------- InitRaycastResult

Raycast 
Object::InitRaycastRecord(const Ray& ray, ShadeRecord& record) const
{
    Raycast result;
    result.ray = ray;
    result.hit = record.hit = false;
    result.t = record.t = 0.0f;
    record.normal = record.localPoint = Vector(0.0f);

    return result;
}

/// --------------------------------------------------------------------------- AssignRaycastRecord

void 
Object::AssignRaycastRecord(Raycast& raycast, ShadeRecord& record, const Vector& normal, const Vector localPoint, real t) const
{
    record.normal = Normalize(normal);
    record.localPoint = localPoint;
    raycast.t = record.t = t;
    raycast.hit = record.hit = true;
}

/// --------------------------------------------------------------------------- Query

Raycast 
Object::Query(const Ray& ray, ShadeRecord& record) const
{
    return Raycast();
}

/// --------------------------------------------------------------------------- ShadowHit

bool 
Object::ShadowHit(const Ray& ray, float& tmin) const
{
    return false;
}

/// --------------------------------------------------------------------------- pdf

float 
Object::pdf(const ShadeRecord& record) const
{
    return 0.f;
}

/// --------------------------------------------------------------------------- SetTransform

void 
Object::SetTransform(const Vector& position, const Vector& axis, real angle, real scale)
{
    m_transform = Matrix::Transform(position, axis, angle, scale);
}

/// --------------------------------------------------------------------------- EOF