
#include "Lights\AmbientLight.h"

/// --------------------------------------------------------------------------- Constructor

AmbientLight::AmbientLight()
    : m_color(Color::White())
    , m_intensity(1.f)
{}

/// --------------------------------------------------------------------------- Constructor

AmbientLight::AmbientLight(const Color& color, const real intensity)
    : m_color(color)
    , m_intensity(intensity)
{}

/// --------------------------------------------------------------------------- Copy constructor

AmbientLight::AmbientLight(const AmbientLight& light)
    : m_color(light.m_color)
    , m_intensity(light.m_intensity)
{}

/// --------------------------------------------------------------------------- Destructor

AmbientLight::~AmbientLight()
{}

/// --------------------------------------------------------------------------- Copy assignment operator

AmbientLight& 
AmbientLight::operator=(AmbientLight light)
{
    Swap<Color>(light.m_color, m_color);
    Swap<real>(light.m_intensity, m_intensity);

     return *this;
}

/// --------------------------------------------------------------------------- Clone

Light* 
AmbientLight::Clone() const
{
    return static_cast<Light*>(new AmbientLight(*this));
}

/// --------------------------------------------------------------------------- GetDirection

Vector 
AmbientLight::GetDirection(ShadeRecord& record)
{
    return Vector(0.f);
}

/// --------------------------------------------------------------------------- Radiance

Color 
AmbientLight::Radiance(ShadeRecord& record)
{
    return m_intensity * m_color;
}

/// --------------------------------------------------------------------------- EOF