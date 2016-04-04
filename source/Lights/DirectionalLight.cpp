
#include "Lights\DirectionalLight.h"

/// --------------------------------------------------------------------------- constructor

DirectionalLight::DirectionalLight()
    : m_direction(0.f, -1.f, 0.f)
    , m_color(Color::White())
    , m_intensity(1.f)
{}

/// --------------------------------------------------------------------------- constructor

DirectionalLight::DirectionalLight(const Vector& direction)
    : m_direction(direction)
    , m_color(Color::White())
    , m_intensity(1.f)
{}

/// --------------------------------------------------------------------------- constructor

DirectionalLight::DirectionalLight(const Color& color, const real intensity)
    : m_direction(Vector(0.f, -1.f, 0.f))
    , m_color(color)
    , m_intensity(intensity)
{}

/// --------------------------------------------------------------------------- constructor

DirectionalLight::DirectionalLight(const Vector& direction, const Color& color, const real intensity)
    : m_direction(direction)
    , m_color(color)
    , m_intensity(intensity)
{}

/// --------------------------------------------------------------------------- copy assignment operator

DirectionalLight::DirectionalLight(const DirectionalLight& light)
    : Light(light)
    , m_direction(light.m_direction)
    , m_color(light.m_color)
    , m_intensity(light.m_intensity)
{}

/// --------------------------------------------------------------------------- destructor

DirectionalLight::~DirectionalLight() {}

/// --------------------------------------------------------------------------- copy assignment operator

DirectionalLight& 
DirectionalLight::operator=(DirectionalLight light)
{
    /// copy and swap
    Light::operator=(light);
    Swap<Vector>(m_direction, light.m_direction);
    Swap<Color>(m_color, light.m_color);
    Swap<real>(m_intensity, light.m_intensity);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Light* 
DirectionalLight::Clone() const
{
    return static_cast<Light*>(new DirectionalLight(*this));
}

/// --------------------------------------------------------------------------- GetDirection

Vector 
DirectionalLight::GetDirection(ShadeRecord& record)
{
    return -m_direction;
}

/// --------------------------------------------------------------------------- Radiance

Color 
DirectionalLight::Radiance(ShadeRecord& record)
{
    return m_intensity * m_color;
}

/// --------------------------------------------------------------------------- CastsShadow

bool 
DirectionalLight::CastsShadow() const
{
    /// @TODO:
    return m_shadows;
}

/// --------------------------------------------------------------------------- InShadow

bool 
DirectionalLight::InShadow(const Ray& ray, ShadeRecord& record) const
{
    /// @TODO:
    return false;
}

/// --------------------------------------------------------------------------- EOF