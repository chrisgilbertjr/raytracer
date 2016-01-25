
#include "Lights\PointLight.h"
#include "BRDFs\ShadeRecord.h"

/// --------------------------------------------------------------------------- Attenuation

real 
PointLight::Attenuation(real distance) const
{
    if (distance > m_radius*2.5f)
    {
        return 0.f;
    }
    float r = m_radius;
    float d = distance - r;
    if (d < 0.f) d = 0.f;
    float denom = d/r + 1.f;
    float att = 1.f / (denom*denom);
    att = (att - 0.0005f) / (1.f - 0.0005f);
    if (att < 0.f) att = 0.f;
    return Saturate(att);
}

/// --------------------------------------------------------------------------- Constructor

PointLight::PointLight()
    : m_position(0.f, 0.f, 0.f)
    , m_color(Color::White())
    , m_intensity(1.f)
    , m_radius(100.f)
{}

/// --------------------------------------------------------------------------- Constructor

PointLight::PointLight(const Vector& position)
    : m_position(position)
    , m_color(Color::White())
    , m_intensity(1.f)
    , m_radius(100.f)
{}

/// --------------------------------------------------------------------------- Constructor

PointLight::PointLight(const Color& color, const real intensity)
    : m_position(0.f, 0.f, 0.f)
    , m_color(color)
    , m_intensity(intensity)
    , m_radius(100.f)
{}

/// --------------------------------------------------------------------------- Constructor

PointLight::PointLight(const Vector& position, const Color& color, real radius, real intensity)
    : m_position(position)
    , m_color(color)
    , m_intensity(intensity)
    , m_radius(radius)
{}

/// --------------------------------------------------------------------------- Copy assignment operator

PointLight::PointLight(const PointLight& light)
    : m_position(light.m_position)
    , m_color(light.m_color)
    , m_intensity(light.m_intensity)
    , m_radius(light.m_radius)
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
    Swap<real>(m_radius, light.m_radius);

    return *this;
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
    return Normalize(m_position - record.worldPoint);
}

/// --------------------------------------------------------------------------- Radiance

Color 
PointLight::Radiance(ShadeRecord& record)
{
    return Attenuation(Length(m_position - record.worldPoint)) * m_color * m_intensity;
}

/// --------------------------------------------------------------------------- EOF