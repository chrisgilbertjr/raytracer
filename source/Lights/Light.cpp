
#include "Lights\Light.h"

// ---------------------------------------------------------------------------- constructor

Light::Light()
    : m_shadows(true)
{}

// ---------------------------------------------------------------------------- copy constructor

Light::Light(const Light& light)
    : m_shadows(light.m_shadows)
{}

// ---------------------------------------------------------------------------- copy assignment operator

Light& 
Light::operator=(const Light& light)
{
    m_shadows = light.m_shadows;
    return *this;
}

// ---------------------------------------------------------------------------- destructor

Light::~Light()
{}

// ---------------------------------------------------------------------------- G

real 
Light::G(const ShadeRecord& record) const
{
    return 1.0f;
}

// ---------------------------------------------------------------------------- pdf

real 
Light::pdf(const ShadeRecord& record) const
{
    return 1.0f;
}

// ---------------------------------------------------------------------------- EOF
