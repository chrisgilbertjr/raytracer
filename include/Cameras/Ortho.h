
#ifndef ORTHO_H
#define ORTHO_H

#include "Cameras\Camera.h"

/// @defgroup Ortho Ortho
/// @{

/// @TODO: skeleton class

/// orthographic projection camera
class Ortho : public Camera
{
private:

public:
    /// constructor
    Ortho();

    /// copy constructor
    Ortho(const Ortho& ortho);

    /// desutrctor
    virtual ~Ortho();

    /// copy assignment operator
    Ortho& operator=(Ortho ortho);

    /// deep copy the object
    virtual Camera* Clone() const;

    /// render the scene
    virtual void Render(const World* world, const OutputOptions& output);
};

/// @}

#endif