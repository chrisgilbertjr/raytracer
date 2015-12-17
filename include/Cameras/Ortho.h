
#ifndef ORTHO_H
#define ORTHO_H

#include "Cameras\Camera.h"

class Ortho : public Camera
{
private:

public:
    Ortho();

    ~Ortho();

    virtual void Render(const World& world);
};

#endif