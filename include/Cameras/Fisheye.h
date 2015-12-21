
#ifndef FISHEYE_H
#define FISHEYE_H

#include "Cameras\Camera.h"

class Fisheye : public Camera
{
private:

public:
    Fisheye();

    Fisheye(const Fisheye& fisheye);

    virtual ~Fisheye();

    Fisheye& operator=(Fisheye fisheye);

    virtual Camera* Clone() const;

    virtual void Render(const World& world);
};

#endif