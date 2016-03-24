
#ifndef THIN_LENS_H
#define THIN_LENS_H

#include "Cameras\Camera.h"

/// @defgroup ThinLens ThinLens
/// @{

/// @TODO: skeleton class

/// depth of field camera
class ThinLens : public Camera
{
public:
    /// constructor
    ThinLens();

    /// copy constructor
    ThinLens(const ThinLens& thinlens);

    /// destructor
    virtual ~ThinLens();

    /// copy assignment operator
    ThinLens& operator=(ThinLens thinlens);

    /// deep copy the object
    virtual Camera* Clone() const;

    /// render the world
    virtual void Render(const World* world, const OutputOptions& output);
};

/// @{

#endif