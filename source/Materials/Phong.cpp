
#include "Materials\Phong.h"

Phong::Phong()
{
    /// @TODO:
}

Phong::Phong(const Phong& phong)
{
    /// @TODO:
}

Phong::~Phong() {}

Phong& 
Phong::operator=(Phong phong)
{
    /// @TODO:
    return *this;
}

Material* 
Phong::Clone() const
{
    return static_cast<Material*>(new Phong(*this));
}