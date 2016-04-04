
#include "Objects\LightObject.h"
#include "Materials\Emmisive.h"
#include "Samplers\PureRandom.h"

/// --------------------------------------------------------------------------- constructor

LightObject::LightObject()
    : m_material(NULL)
    , m_sampler(NULL)
    , m_object(NULL)
{ 
    Assert(false);
}

/// --------------------------------------------------------------------------- constructor

LightObject::LightObject(Object* object)
    : m_material(new Emmisive())
    , m_sampler(new PureRandom(16))
    , m_object(object)
{
    m_object->SetMaterial(m_material);
}

/// --------------------------------------------------------------------------- constructor

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

/// --------------------------------------------------------------------------- copy constructor

LightObject::LightObject(const LightObject& light)
    : m_material(light.m_material)
    , m_sampler(light.m_sampler)
    , m_object(light.m_object)
{}

/// --------------------------------------------------------------------------- destructor

LightObject::~LightObject()
{
    if (m_sampler) delete m_sampler;
}

/// --------------------------------------------------------------------------- copy assignment operator

LightObject& 
LightObject::operator=(LightObject light)
{
    Swap<Material*>(m_material, light.m_material);
    Swap<Sampler*>(m_sampler, light.m_sampler);
    Swap<Object*>(m_object, light.m_object);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

LightObject* 
LightObject::Clone() const
{
    return new LightObject(*this);
}

/// --------------------------------------------------------------------------- Sample

Vector 
LightObject::Sample() const
{
    return Vector(0.f);
}

/// --------------------------------------------------------------------------- GetNormal

Vector 
LightObject::GetNormal(const Vector& point) const
{
    return Vector(0.f);
}

/// --------------------------------------------------------------------------- GetEmmisive

Color 
LightObject::GetEmmisive(ShadeRecord& record) const
{
    return m_material->GetEmmisive();
}

/// --------------------------------------------------------------------------- pdf

real 
LightObject::pdf(const ShadeRecord& record) const
{
    return 0.0f;
}

/// --------------------------------------------------------------------------- EOF