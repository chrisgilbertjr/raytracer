
#include "Cameras\ThinLens.h"

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
ThinLens::Render(const World& world)
{
    /// @TODO:
}