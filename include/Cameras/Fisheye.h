
#ifndef FISHEYE_H
#define FISHEYE_H

#include "Cameras\Camera.h"

class Fisheye : public Camera
{
private:

public:
    Fisheye();

    ~Fisheye();

    virtual void Render(const World& world);
};

#endif