
#include "Materials\Material.h"

/// --------------------------------------------------------------------------- constructor

Material::Material()
    : m_color(Color::Black())
{}

/// --------------------------------------------------------------------------- copy constructor

Material::Material(const Material& material)
    : m_color(material.m_color)
{}

/// --------------------------------------------------------------------------- destructor

Material::~Material() {}

/// --------------------------------------------------------------------------- copy assignment operator

Material& 
Material::operator=(Material material)
{
    Swap<Color>(m_color, material.m_color);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Material* Material::Clone() const
{
    Assert(false);
    return NULL;
}

/// --------------------------------------------------------------------------- Shade

Color 
Material::Shade(ShadeRecord& record) const
{
    return Color::Black();
}

/// --------------------------------------------------------------------------- AreaLightShade

Color 
Material::AreaLightShade(ShadeRecord& record) const
{
    return Color::Black();
}

/// --------------------------------------------------------------------------- PathShade

Color 
Material::PathShade(ShadeRecord& record) const
{
    return Color::Black();
}

/// --------------------------------------------------------------------------- GetEmmisive

Color 
Material::GetEmmisive() const
{
    return Color::Black();
}

/// --------------------------------------------------------------------------- EOF