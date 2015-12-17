
#ifndef SPHERICAL_H
#define SPHERICAL_H

#include "Cameras\Camera.h"

class Spherical : public Camera
{
private:

public:
    Spherical();

    ~Spherical();

    virtual void Render(const World& world);
};

#endif