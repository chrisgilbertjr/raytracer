
#include "Cameras\ThinLens.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

ThinLens::ThinLens()
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- copy constructor

ThinLens::ThinLens(const ThinLens& thinlens)
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- destructor

ThinLens::~ThinLens()
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- copy assignment operator

ThinLens&
ThinLens::operator=(ThinLens thinlens)
{
    /// @TODO:
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Camera*
ThinLens::Clone() const
{
    /// @TODO:
    return static_cast<Camera*>(new ThinLens(*this));
}

/// --------------------------------------------------------------------------- Render

void
ThinLens::Render(const World* world, const OutputOptions& options)
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- EOF