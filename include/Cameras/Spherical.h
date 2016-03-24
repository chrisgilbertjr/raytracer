
#ifndef SPHERICAL_H
#define SPHERICAL_H

#include "Cameras\Camera.h"

/// @defgroup Spherical Spherical
/// @{

/// @TODO: skeleton class

/// spherical projection camera
class Spherical : public Camera
{
private:

public:
    /// constructor
    Spherical();

    /// copy constructor
    Spherical(const Spherical& spherical);

    /// destructor
    virtual ~Spherical();

    /// copy assignment operator
    Spherical& operator=(Spherical spherical);

    /// deep copy the object
    virtual Camera* Clone() const;

    /// render the world
    virtual void Render(const World* world, const OutputOptions& output);
};

/// @}

#endif