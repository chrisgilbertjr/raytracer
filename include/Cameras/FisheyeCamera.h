
#ifndef FISHEYE_CAMERA_H
#define FISHEYE_CAMERA_H

#include "Cameras\Camera.h"

class FisheyeCamera : public Camera
{
    virtual void Render(const World& world);
};

#endif