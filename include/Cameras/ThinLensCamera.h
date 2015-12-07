
#ifndef THIN_LENS_CAMERA_H
#define THIN_LENS_CAMERA_H

#include "Cameras\Camera.h"

class ThinLensCamera : public Camera
{
    virtual void Render(const World& world);
};

#endif