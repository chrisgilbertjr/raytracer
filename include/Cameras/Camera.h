
#ifndef CAMERA_H
#define CAMERA_H

#include "World.h"

class Camera
{
protected:
    /// @TODO

public:
    void ComputeBasis();

    virtual void Render(const World& world) = 0;
};

#endif