
#ifndef FISHEYE_H
#define FISHEYE_H

#include "Cameras\Camera.h"

/// @defgroup Fisheye
/// @{

/// @TODO: skeleton class

/// fisheye camera lens
class Fisheye : public Camera
{
private:

public:
    /// constructor
    Fisheye();

    /// copy constructor
    Fisheye(const Fisheye& fisheye);

    /// destructor
    virtual ~Fisheye();

    /// copy assignment operator
    Fisheye& operator=(Fisheye fisheye);

    /// deep copy of the object
    virtual Camera* Clone() const;

    /// render the world
    virtual void Render(const World* world, const OutputOptions& output);
};

/// @}

#endif