
#include "Cameras\Fisheye.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

Fisheye::Fisheye()
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- copy constructor

Fisheye::Fisheye(const Fisheye& fisheye)
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- destructor

Fisheye::~Fisheye()
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- copy assignment operator

Fisheye&
Fisheye::operator=(Fisheye fisheye)
{
    /// @TODO:
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Camera*
Fisheye::Clone() const
{
    /// @TODO:
    return static_cast<Camera*>(new Fisheye(*this));
}

/// --------------------------------------------------------------------------- Render

void
Fisheye::Render(const World* world, const OutputOptions& options)
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- EOF