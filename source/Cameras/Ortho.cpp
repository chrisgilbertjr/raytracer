
#include "Cameras\Ortho.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

Ortho::Ortho()
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- copy constructor

Ortho::Ortho(const Ortho& ortho)
{
    /// @TODO:
}
 
/// --------------------------------------------------------------------------- destructor

Ortho::~Ortho()
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- copy assignment operator

Ortho&
Ortho::operator=(Ortho ortho)
{
    /// @TODO:
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Camera*
Ortho::Clone() const
{
    /// @TODO:
    return static_cast<Camera*>(new Ortho(*this));
}

/// --------------------------------------------------------------------------- Render

void
Ortho::Render(const World* world, const OutputOptions& options)
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- EOF