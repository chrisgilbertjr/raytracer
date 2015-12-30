
#include "Materials\Material.h"

Material::Material()
{
    /// @TODO:
}

Material::Material(const Material& material)
{
    /// @TODO:
}

Material::~Material() {}

Material& 
Material::operator=(Material material)
{
    Assert(false);
    return *this;
}

Material* Material::Clone() const
{
    Assert(false);
    return NULL;
}