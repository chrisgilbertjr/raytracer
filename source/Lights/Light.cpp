
#include "Lights\Light.h"

// ---------------------------------------------------------------------------- Constructor

Light::Light() {}

// ---------------------------------------------------------------------------- Destructor

Light::~Light()
{}

// ---------------------------------------------------------------------------- EOF

real 
Light::G(const ShadeRecord& record) const
{
    return 1.0f;
}

// ---------------------------------------------------------------------------- EOF

real 
Light::pdf(const ShadeRecord& record) const
{
    return 1.0f;
}

// ---------------------------------------------------------------------------- EOF
