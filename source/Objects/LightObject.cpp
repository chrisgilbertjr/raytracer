
#include "Objects\LightObject.h"
#include "Materials\Emmisive.h"
#include "Samplers\PureRandom.h"

LightObject::LightObject()
    : m_material(NULL)
    , m_sampler(NULL)
    , m_object(NULL)
{ 
    Assert(false);
}

LightObject::LightObject(Object* object)
    : m_material(new Emmisive())
    , m_sampler(new PureRandom(16))
    , m_object(object)
{
    m_object->SetMaterial(m_material);
}

LightObject::LightObject(Object* object, Sampler* sampler)
    : m_material(new Emmisive())
    , m_sampler(sampler)
    , m_object(object)
{
    if (!object || !sampler) 
    {
        Assert(false);
    }

    m_object->SetMaterial(m_material);
}

LightObject::LightObject(const LightObject& light)
    : m_material(light.m_material)
    , m_sampler(light.m_sampler)
    , m_object(light.m_object)
{}

LightObject::~LightObject()
{
    if (m_sampler) delete m_sampler;
}

LightObject& 
LightObject::operator=(LightObject light)
{
    Swap<Material*>(m_material, light.m_material);
    Swap<Sampler*>(m_sampler, light.m_sampler);
    Swap<Object*>(m_object, light.m_object);

    return *this;
}

LightObject* 
LightObject::Clone() const
{
    return new LightObject(*this);
}

Vector 
LightObject::Sample() const
{
    return Vector(0.f);
}

Vector 
LightObject::GetNormal(const Vector& point) const
{
    return Vector(0.f);
}

Color 
LightObject::GetEmmisive(ShadeRecord& record) const
{
    return m_material->GetEmmisive();
}

real 
LightObject::pdf(const ShadeRecord& record) const
{
    return 0.0f;
}