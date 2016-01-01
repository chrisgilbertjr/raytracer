
#include "Lights\PointLight.h"

/// --------------------------------------------------------------------------- Constructor

PointLight::PointLight()
    : m_position(0.f, 0.f, 0.f)
    , m_color(Color::White())
    , m_intensity(1.f)
{}

/// --------------------------------------------------------------------------- Constructor

PointLight::PointLight(const Vector& position)
    : m_position(position)
    , m_color(Color::White())
    , m_intensity(1.f)
{}

/// --------------------------------------------------------------------------- Constructor

PointLight::PointLight(const Color& color, const real intensity)
    : m_position(0.f, 0.f, 0.f)
    , m_color(color)
    , m_intensity(intensity)
{}

/// --------------------------------------------------------------------------- Constructor

PointLight::PointLight(const Vector& position, const Color& color, const real intensity)
    : m_position(position)
    , m_color(color)
    , m_intensity(intensity)
{}

/// --------------------------------------------------------------------------- Copy assignment operator

PointLight::PointLight(const PointLight& light)
    : m_position(light.m_position)
    , m_color(light.m_color)
    , m_intensity(light.m_intensity)
{}

/// --------------------------------------------------------------------------- Destructor

PointLight::~PointLight() {}

/// --------------------------------------------------------------------------- Assignment operator

PointLight& 
PointLight::operator=(PointLight light)
{
    Swap<Vector>(m_position, light.m_position);
    Swap<Color>(m_color, light.m_color);
    Swap<real>(m_intensity, light.m_intensity);
}

/// --------------------------------------------------------------------------- Clone

Light* 
PointLight::Clone() const
{
    return static_cast<Light*>(new PointLight(*this));
}

/// --------------------------------------------------------------------------- GetDirection

Vector 
PointLight::GetDirection(ShadeRecord& record)
{
    return Vector(0.f, 0.f, 0.f);
}

/// --------------------------------------------------------------------------- Radiance

Color 
PointLight::Radiance(ShadeRecord& record)
{
    return Color::White();
}

/// --------------------------------------------------------------------------- EOF