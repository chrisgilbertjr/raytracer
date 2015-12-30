
#include "Cameras\Ortho.h"

Ortho::Ortho()
{
    /// @TODO:
}

Ortho::Ortho(const Ortho& ortho)
{
    /// @TODO:
}

Ortho::~Ortho()
{
    /// @TODO:
}

Ortho&
Ortho::operator=(Ortho ortho)
{
    /// @TODO:
    return *this;
}

Camera*
Ortho::Clone() const
{
    /// @TODO:
    return static_cast<Camera*>(new Ortho(*this));
}

void
Ortho::Render(const World& world)
{
    /// @TODO:
}