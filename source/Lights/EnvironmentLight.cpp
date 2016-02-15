
#include "Lights\EnvironmentLight.h"

EnvironmentLight::EnvironmentLight()
{
}

EnvironmentLight::EnvironmentLight(const EnvironmentLight& light)
{
}

EnvironmentLight::~EnvironmentLight()
{
}

EnvironmentLight& 
EnvironmentLight::operator=(EnvironmentLight light)
{
}

Light* 
EnvironmentLight::Clone() const
{
}

Vector 
EnvironmentLight::GetDirection(ShadeRecord& record)
{
}

Color 
EnvironmentLight::Radiance(ShadeRecord& record)
{
}

bool 
EnvironmentLight::CastsShadow() const
{
}

bool 
EnvironmentLight::InShadow(const Ray& ray, ShadeRecord& record) const
{
}

real 
EnvironmentLight::pdf(const ShadeRecord& record) const
{
}