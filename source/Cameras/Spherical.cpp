
#include "Cameras\Spherical.h"

Spherical::Spherical()
{
    /// @TODO:
}

Spherical::Spherical(const Spherical& spherical)
{
    /// @TODO:
}

Spherical::~Spherical()
{
    /// @TODO:
}

Spherical&
Spherical::operator=(Spherical spherical)
{
    /// @TODO:
    return *this;
}

Camera*
Spherical::Clone() const
{
    /// @TODO:
    return static_cast<Camera*>(new Spherical(*this));
}

void
Spherical::Render(const World& world)
{
    /// @TODO:
}