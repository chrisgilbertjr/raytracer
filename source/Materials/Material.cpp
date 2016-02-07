
#include "Materials\Material.h"

/// --------------------------------------------------------------------------- Constructor

Material::Material()
    : m_color(Color::Black())
{}

/// --------------------------------------------------------------------------- Copy constructor

Material::Material(const Material& material)
    : m_color(material.m_color)
{}

/// --------------------------------------------------------------------------- Destructor

Material::~Material() {}

/// --------------------------------------------------------------------------- Copy assignment operator

Material& 
Material::operator=(Material material)
{
    Assert(false);
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

/// --------------------------------------------------------------------------- EOF

Color 
Material::AreaLightShade(ShadeRecord& record) const
{
    return Color::Black();
}

/// --------------------------------------------------------------------------- EOF