
#ifndef ORTHO_CAMERA_H
#define ORTHO_CAMERA_H

#include "Cameras\Camera.h"

class OrthoCamera : public Camera
{
    virtual void Render(const World& world);
};

#endif