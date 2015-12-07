
#ifndef STEREO_CAMERA_H
#define STEREO_CAMERA_H

#include "Cameras\Camera.h"

class StereoCamera : public Camera
{
    virtual void Render(const World& world);
};

#endif