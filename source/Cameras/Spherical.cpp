
#include "Cameras\Spherical.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

Spherical::Spherical()
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- copy constructor

Spherical::Spherical(const Spherical& spherical)
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- destructor

Spherical::~Spherical()
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- copy assignment operator

Spherical&
Spherical::operator=(Spherical spherical)
{
    /// @TODO:
    return *this;
}

/// -------------------------------------------------------------------------- Clone

Camera*
Spherical::Clone() const
{
    /// @TODO:
    return static_cast<Camera*>(new Spherical(*this));
}

/// --------------------------------------------------------------------------- Render

void
Spherical::Render(const World* world, const OutputOptions& options)
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- EOF