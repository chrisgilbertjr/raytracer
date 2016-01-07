
#include "Cameras\ThinLens.h"
#include "World\World.h"

ThinLens::ThinLens()
{
    /// @TODO:
}

ThinLens::ThinLens(const ThinLens& thinlens)
{
    /// @TODO:
}

ThinLens::~ThinLens()
{
    /// @TODO:
}

ThinLens&
ThinLens::operator=(ThinLens thinlens)
{
    /// @TODO:
    return *this;
}

Camera*
ThinLens::Clone() const
{
    /// @TODO:
    return static_cast<Camera*>(new ThinLens(*this));
}

void
ThinLens::Render(const World* world, const OutputOptions& options)
{
    /// @TODO:
}