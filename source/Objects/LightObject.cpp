
#include "Objects\LightObject.h"

LightObject::LightObject()
{
}

LightObject::LightObject(Object* object)
{
}

LightObject::LightObject(const LightObject& light)
{
}

LightObject::~LightObject()
{
}

LightObject& 
LightObject::operator=(LightObject light)
{
}

LightObject* 
LightObject::Clone() const
{
}

Vector 
LightObject::Sample() const
{
}

Vector 
LightObject::GetNormal(const Vector& point) const
{
}

Color 
LightObject::Le(ShadeRecord& record) const
{
}

real 
LightObject::pdf(const ShadeRecord& record) const
{
}