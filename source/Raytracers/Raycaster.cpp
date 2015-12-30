
#include "Raytracers\Raycaster.h"

Raycaster::Raycaster()
{
    /// @TODO:
}

Raycaster::Raycaster(const Raycaster& raycaster)
{
    /// @TODO:
}

Raycaster::~Raycaster() {}

Raycaster& 
Raycaster::operator=(Raycaster raycaster)
{
    /// @TODO:
    return *this;
}

Raytracer* 
Raycaster::Clone() const
{
    return static_cast<Raytracer*>(new Raycaster(*this));
}