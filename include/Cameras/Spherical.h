
#ifndef SPHERICAL_H
#define SPHERICAL_H

#include "Cameras\Camera.h"

class Spherical : public Camera
{
private:

public:
    Spherical();

    Spherical(const Spherical& spherical);

    virtual ~Spherical();

    Spherical& operator=(Spherical spherical);

    virtual Camera* Clone() const;

    virtual void Render(const World& world);
};

#endif