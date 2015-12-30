
#include "Raytracers\Whitted.h"

Whitted::Whitted()
{
    /// @TODO:
}

Whitted::Whitted(const Whitted& whitted)
{
    /// @TODO:
}

Whitted::~Whitted() {}

Whitted& 
Whitted::operator=(Whitted whitted)
{
    /// @TODO:
    return *this;
}

Raytracer* 
Whitted::Clone() const
{
    return static_cast<Raytracer*>(new Whitted(*this));
}