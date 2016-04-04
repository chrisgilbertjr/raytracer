
#include "Materials\Emmisive.h"
#include "BRDFs\ShadeRecord.h"

/// --------------------------------------------------------------------------- constructor

Emmisive::Emmisive()
    : Material()
    , m_color(Color::White())
    , m_intensity(2000.f)
{}

/// --------------------------------------------------------------------------- copy constructor

Emmisive::Emmisive(const Emmisive& emmisive)
    : Material()
    , m_color(emmisive.m_color)
    , m_intensity(emmisive.m_intensity)
{}

/// --------------------------------------------------------------------------- destructor

Emmisive::~Emmisive() {}

/// --------------------------------------------------------------------------- copy assignment operator

Emmisive& 
Emmisive::operator=(Emmisive emmisive)
{
    /// copy and swap
    Material::operator=(emmisive);
    Swap<Color>(m_color, emmisive.m_color);
    Swap<real>(m_intensity, emmisive.m_intensity);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Material* 
Emmisive::Clone() const
{
    return static_cast<Material*>(new Emmisive(*this));
}

/// --------------------------------------------------------------------------- Shade

Color 
Emmisive::Shade(ShadeRecord& record) const
{
    return this->GetEmmisive();
}

/// --------------------------------------------------------------------------- AreaLightShade

Color 
Emmisive::AreaLightShade(ShadeRecord& record) const
{
    if (Dot(-record.normal, record.ray.direction) > 0.f)
    {
        return this->GetEmmisive();
    }
    else
    {
        return Color::Black();
    }
}

/// --------------------------------------------------------------------------- PathShade

Color 
Emmisive::PathShade(ShadeRecord& record) const
{
    return this->GetEmmisive();
}

/// --------------------------------------------------------------------------- GetEmmisive

Color 
Emmisive::GetEmmisive() const
{
    return m_color * m_intensity;
}

/// --------------------------------------------------------------------------- EOF