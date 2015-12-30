
#include "Cameras\Fisheye.h"

Fisheye::Fisheye()
{
    /// @TODO:
}

Fisheye::Fisheye(const Fisheye& fisheye)
{
    /// @TODO:
}

Fisheye::~Fisheye()
{
    /// @TODO:
}

Fisheye&
Fisheye::operator=(Fisheye fisheye)
{
    /// @TODO:
    return *this;
}

Camera*
Fisheye::Clone() const
{
    /// @TODO:
    return static_cast<Camera*>(new Fisheye(*this));
}

void 
Fisheye::Render(const World& world)
{
    /// @TODO:
}