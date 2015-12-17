
#ifndef CAMERA_H
#define CAMERA_H

#include "World\World.h"

class Camera
{
protected:
    /// @TODO

public:
    Camera();

    ~Camera();

    /// @TODO:
    void ComputeBasis();

    virtual void Render(const World& world) = 0;
};

#endif