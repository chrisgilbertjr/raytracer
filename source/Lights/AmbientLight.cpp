
#include "Lights\AmbientLight.h"

/// --------------------------------------------------------------------------- constructor

AmbientLight::AmbientLight()
    : Light()
    , m_color(Color::White())
    , m_intensity(1.f)
{}

/// --------------------------------------------------------------------------- constructor

AmbientLight::AmbientLight(const Color& color, const real intensity)
    : Light()
    , m_color(color)
    , m_intensity(intensity)
{}

/// --------------------------------------------------------------------------- copy constructor

AmbientLight::AmbientLight(const AmbientLight& light)
    : Light(light)
    , m_color(light.m_color)
    , m_intensity(light.m_intensity)
{}

/// --------------------------------------------------------------------------- Destructor

AmbientLight::~AmbientLight() {}

/// --------------------------------------------------------------------------- Copy assignment operator

AmbientLight& 
AmbientLight::operator=(AmbientLight light)
{
    /// copy and swap
    Light::operator=(light);
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

/// --------------------------------------------------------------------------- CastsShadow

bool 
AmbientLight::CastsShadow() const
{
    return m_shadows;
}

/// --------------------------------------------------------------------------- InShadow

bool 
AmbientLight::InShadow(const Ray& ray, ShadeRecord& record) const
{
    return false;
}

/// --------------------------------------------------------------------------- EOF