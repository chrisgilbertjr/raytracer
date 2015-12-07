
#ifndef PINHOLE_CAMERA_H
#define PINHOLE_CAMERA_H

#include "Cameras\Camera.h"

class PineholeCamera : public Camera
{
    virtual void Render(const World& world);
};

#endif