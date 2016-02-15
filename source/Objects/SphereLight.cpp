
#include "Samplers\PureRandom.h"
#include "Objects\SphereLight.h"
#include "Objects\Sphere.h"

SphereLight::SphereLight()
    : LightObject(new Sphere(Vector(0.f), 0.f), new PureRandom(8))
{
    Assert(false);
}

SphereLight::SphereLight(Object* object)
    : LightObject(object, new PureRandom(8))
{
    m_sampler->MapSamplesToSphere();
}

SphereLight::SphereLight(Object* object, Sampler* sampler)
    : LightObject(object, sampler)
{
    m_sampler->MapSamplesToSphere();
    int x = 0;
}

SphereLight::SphereLight(const SphereLight& light)
    : LightObject(light)
{}

SphereLight::~SphereLight()
{
    /// resources released in base class
}

SphereLight& 
SphereLight::operator=(SphereLight light)
{
    LightObject::operator=(light);

    return *this;
}

LightObject* 
SphereLight::Clone() const
{
    return static_cast<LightObject*>(new SphereLight(*this));
}

Vector 
SphereLight::Sample() const
{
    Sphere* sphere = static_cast<Sphere*>(m_object);
    Vector point = m_sampler->SampleSphere() * sphere->GetRadius();

    return point + sphere->GetCenter();
}

Vector 
SphereLight::GetNormal(const Vector& point) const
{
    Sphere* sphere = static_cast<Sphere*>(m_object);
    return Normalize(point - sphere->GetCenter());
}

real 
SphereLight::pdf(const ShadeRecord& record) const
{
    m_object->pdf(record);
}