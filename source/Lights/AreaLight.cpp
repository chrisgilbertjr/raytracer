
#include "Lights\AreaLight.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

AreaLight::AreaLight()
    : m_object(NULL)
    , m_point()
    , m_normal()
    , m_wi()
{}

/// --------------------------------------------------------------------------- constructor

AreaLight::AreaLight(LightObject* object)
    : m_object(object)
    , m_point()
    , m_normal()
    , m_wi()
{
    if (!object) Assert(false);
}

/// --------------------------------------------------------------------------- copy constructor

AreaLight::AreaLight(const AreaLight& light)
    : Light(light)
    , m_object(light.m_object)
    , m_point(light.m_point)
    , m_normal(light.m_normal)
    , m_wi(light.m_wi)
{}

/// --------------------------------------------------------------------------- destructor

AreaLight::~AreaLight() { if (m_object) delete m_object; }

/// --------------------------------------------------------------------------- copy assignment operator

AreaLight& 
AreaLight::operator=(AreaLight light)
{
    Light::operator=(light);

    m_object = m_object ? light.m_object->Clone() : NULL;
    Swap<Vector>(m_point, light.m_point);
    Swap<Vector>(m_normal, light.m_normal);
    Swap<Vector>(m_wi, light.m_wi);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Light* 
AreaLight::Clone() const
{
    return static_cast<Light*>(new AreaLight(*this));
}

/// --------------------------------------------------------------------------- GetDirection

Vector 
AreaLight::GetDirection(ShadeRecord& record)
{
    m_point = m_object->Sample();
    m_normal = m_object->GetNormal(m_point);
    m_wi = Normalize(m_point - record.worldPoint);

    return m_wi;
}

/// --------------------------------------------------------------------------- Radiance

Color 
AreaLight::Radiance(ShadeRecord& record)
{
    real NoD = Dot(-m_normal, m_wi);

    if (NoD > 0.f)
    {
        return m_object->GetEmmisive(record);
    }
    else
    {
        return Color::Black();
    }
}

/// --------------------------------------------------------------------------- CastsShadow

bool 
AreaLight::CastsShadow() const
{
    return m_shadows;
}

/// --------------------------------------------------------------------------- InShadow

bool 
AreaLight::InShadow(const Ray& ray, ShadeRecord& record) const
{
    real t;
    real ts = Dot((m_point - ray.origin), ray.direction);

    const Array<Object*>* objects = record.world->GetObjects();
    int objectCount = objects->GetSize();

    for (int i = 0; i < objectCount; ++i)
    {
        Object* object = objects->operator[](i);

        if (object->ShadowHit(ray, t) && t < ts)
        {
            return true;
        }
    }
    return false;
}

/// --------------------------------------------------------------------------- G

real 
AreaLight::G(const ShadeRecord& record) const
{
    float d = Dot(-m_normal, m_wi);
    float l = LengthSquared(m_point - record.worldPoint);
    return d / l;
    //return Dot(-m_normal, m_wi) / LengthSquared(record.worldPoint - m_point);
}

/// --------------------------------------------------------------------------- pdf

real 
AreaLight::pdf(const ShadeRecord& record) const
{
    return m_object->pdf(record);
}

/// --------------------------------------------------------------------------- EOF