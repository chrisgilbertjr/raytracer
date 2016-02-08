
#include "Lights\AreaLight.h"
#include "World\World.h"

AreaLight::AreaLight()
    : m_object(NULL)
    , m_point()
    , m_normal()
    , m_wi()
{}

AreaLight::AreaLight(LightObject* object)
    : m_object(object)
    , m_point()
    , m_normal()
    , m_wi()
{
    if (!object) Assert(false);
}

AreaLight::AreaLight(const AreaLight& light)
    : m_object(light.m_object)
    , m_point(light.m_point)
    , m_normal(light.m_normal)
    , m_wi(light.m_wi)
{}

AreaLight::~AreaLight() { if (m_object) delete m_object; }

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

Light* 
AreaLight::Clone() const
{
    return static_cast<Light*>(new AreaLight(*this));
}

Vector 
AreaLight::GetDirection(ShadeRecord& record)
{
    m_point = m_object->Sample();
    m_normal = m_object->GetNormal(m_point);
    m_wi = Normalize(m_point - record.worldPoint);

    return m_wi;
}

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

bool 
AreaLight::CastsShadow() const
{
    return true;
}

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

real 
AreaLight::G(const ShadeRecord& record) const
{
    float d = Dot(-m_normal, m_wi);
    float l = LengthSquared(m_point - record.worldPoint);
    return d / l;
    //return Dot(-m_normal, m_wi) / LengthSquared(record.worldPoint - m_point);
}

real 
AreaLight::pdf(const ShadeRecord& record) const
{
    return m_object->pdf(record);
}