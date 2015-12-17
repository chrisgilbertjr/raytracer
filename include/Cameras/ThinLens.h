
#ifndef THIN_LENS_H
#define THIN_LENS_H

#include "Cameras\Camera.h"

class ThinLens : public Camera
{
private:

public:
    ThinLens();

    ~ThinLens();

    virtual void Render(const World& world);
};

#endif