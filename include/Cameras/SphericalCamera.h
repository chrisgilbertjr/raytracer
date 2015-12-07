
#ifndef SPHERICAL_CAMERA_H
#define SPHERICAL_CAMERA_H

#include "Cameras\Camera.h"

class SphericalCamera : public Camera
{
    virtual void Render(const World& world);
};

#endif