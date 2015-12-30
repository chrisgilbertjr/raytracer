
#include "Materials\Matte.h"

Matte::Matte()
{
    /// @TODO:
}

Matte::Matte(const Matte& matte)
{
    /// @TODO:
}

Matte::~Matte() {}

Material& 
Matte::operator=(Matte matte)
{
    /// @TODO:
    return *this;
}

Material* 
Matte::Clone() const
{
    return static_cast<Material*>(new Matte(*this));
}