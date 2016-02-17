
#include "Lights\EnvironmentLight.h"
#include "Samplers\MultiJittered.h"
#include "Samplers\PureRandom.h"
#include "BRDFs\ShadeRecord.h"
#include "Objects\Object.h"
#include "World\World.h"

EnvironmentLight::EnvironmentLight()
    : Light()
    , m_material(NULL)
    , m_sampler(new PureRandom(128))
    , m_w(0.f)
    , m_u(0.f)
    , m_v(0.f)
    , m_wi(0.f)
{
    m_sampler->MapSamplesToHemisphere();
}

EnvironmentLight::EnvironmentLight(const EnvironmentLight& light)
    : Light(light)
    , m_material(light.m_material)
    , m_sampler(light.m_sampler ? light.m_sampler->Clone() : NULL)
    , m_w(light.m_w)
    , m_u(light.m_u)
    , m_v(light.m_v)
    , m_wi(light.m_wi)
{
}

EnvironmentLight::~EnvironmentLight()
{
    if (m_sampler)
    {
        delete m_sampler;
    }
}

EnvironmentLight& 
EnvironmentLight::operator=(EnvironmentLight light)
{
    Swap<Material*>(m_material, light.m_material);
    Swap<Sampler*>(m_sampler, light.m_sampler);
    Swap<Vector>(m_w, light.m_w);
    Swap<Vector>(m_u, light.m_u);
    Swap<Vector>(m_v, light.m_v);
    Swap<Vector>(m_wi, light.m_wi);

    return *this;
}

Light* 
EnvironmentLight::Clone() const
{
    return static_cast<Light*>(new EnvironmentLight(*this));
}

Vector 
EnvironmentLight::GetDirection(ShadeRecord& record)
{
    m_w = record.normal;
    m_v = Normalize(Cross(Vector(0.0034f, 1.f, 0.0071f), m_w));
    m_u = Cross(m_v, m_w);

    Vector point = m_sampler->SampleHemisphere();
    m_wi = point.x*m_u + point.y*m_v + point.z*m_w;

    return m_wi;
}

Color 
EnvironmentLight::Radiance(ShadeRecord& record)
{
    return m_material->GetEmmisive();
}

bool 
EnvironmentLight::CastsShadow() const
{
    return true;
}

bool 
EnvironmentLight::InShadow(const Ray& ray, ShadeRecord& record) const
{
    float t;
    const Array<Object*>* objects = record.world->GetObjects();
    int objectCount = objects->GetSize();

    for (int i = 0; i < objectCount; ++i)
    {
        Object* object = objects->operator[](i);

        if (object->ShadowHit(ray, t))
        {
            return true;
        }
    }
    return false;
}

real 
EnvironmentLight::pdf(const ShadeRecord& record) const
{
    return 1.f;
}