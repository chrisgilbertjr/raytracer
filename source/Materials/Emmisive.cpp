
#include "Materials\Emmisive.h"
#include "BRDFs\ShadeRecord.h"

Emmisive::Emmisive()
    : m_color(Color::White())
    , m_intensity(50.f)
{}

Emmisive::Emmisive(const Emmisive& emmisive)
    : m_color(emmisive.m_color)
    , m_intensity(emmisive.m_intensity)
{}

Emmisive::~Emmisive() {}

Emmisive& 
Emmisive::operator=(Emmisive emmisive)
{
    Material::operator=(emmisive);
    Swap<Color>(m_color, emmisive.m_color);
    Swap<real>(m_intensity, emmisive.m_intensity);

    return *this;
}

Material* 
Emmisive::Clone() const
{
    return static_cast<Material*>(new Emmisive(*this));
}

Color 
Emmisive::Shade(ShadeRecord& record) const
{
    return this->GetEmmisive();
}

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

Color 
Emmisive::GetEmmisive() const
{
    return m_color * m_intensity;
}