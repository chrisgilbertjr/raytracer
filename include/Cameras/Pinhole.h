
#ifndef PINHOLE_H
#define PINHOLE_H

#include "Cameras\Camera.h"

class Pinhole : public Camera
{
private:

public:
    Pinhole();

    ~Pinhole();

    virtual void Render(const World& world);
};

#endif