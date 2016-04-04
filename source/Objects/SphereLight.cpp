
#include "Samplers\PureRandom.h"
#include "Objects\SphereLight.h"
#include "Objects\Sphere.h"

/// --------------------------------------------------------------------------- constructor

SphereLight::SphereLight()
    : LightObject(new Sphere(Vector(0.f), 0.f), new PureRandom(8))
{
    Assert(false);
}

/// --------------------------------------------------------------------------- constructor

SphereLight::SphereLight(Object* object)
    : LightObject(object, new PureRandom(8))
{
    m_sampler->MapSamplesToSphere();
}

/// --------------------------------------------------------------------------- constructor

SphereLight::SphereLight(Object* object, Sampler* sampler)
    : LightObject(object, sampler)
{
    m_sampler->MapSamplesToSphere();
}

/// --------------------------------------------------------------------------- copy assignment operator

SphereLight::SphereLight(const SphereLight& light)
    : LightObject(light)
{}

/// --------------------------------------------------------------------------- destructor

SphereLight::~SphereLight()
{
    /// resources released in base class
}

/// --------------------------------------------------------------------------- copy assignment operator

SphereLight& 
SphereLight::operator=(SphereLight light)
{
    /// copy and swap
    LightObject::operator=(light);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

LightObject* 
SphereLight::Clone() const
{
    return static_cast<LightObject*>(new SphereLight(*this));
}

/// --------------------------------------------------------------------------- Sample

Vector 
SphereLight::Sample() const
{
    Sphere* sphere = static_cast<Sphere*>(m_object);
    Vector point = m_sampler->SampleSphere() * sphere->GetRadius();

    return point + sphere->GetCenter();
}

/// --------------------------------------------------------------------------- GetNormal

Vector 
SphereLight::GetNormal(const Vector& point) const
{
    Sphere* sphere = static_cast<Sphere*>(m_object);
    return Normalize(point - sphere->GetCenter());
}

/// --------------------------------------------------------------------------- pdf

real 
SphereLight::pdf(const ShadeRecord& record) const
{
    return m_object->pdf(record);
}

/// --------------------------------------------------------------------------- EOF