
#include "Raytracers\AreaLighting.h"

AreaLighting::AreaLighting()
{
    /// @TODO:
}

AreaLighting::AreaLighting(const AreaLighting& area)
{
    /// @TODO:
}

AreaLighting::~AreaLighting()
{
}

AreaLighting& 
AreaLighting::operator=(AreaLighting area)
{
    /// @TODO:
    return *this;
}

Raytracer* 
AreaLighting::Clone() const
{
    return static_cast<Raytracer*>(new AreaLighting(*this));
}
