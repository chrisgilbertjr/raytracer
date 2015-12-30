
#ifndef RAYCAST_H
#define RAYCAST_H

#include "Raytracer.h"

class Raycaster : public Raytracer
{
private:

public:
    Raycaster();

    Raycaster(const Raycaster& raycaster);

    virtual ~Raycaster();

    Raycaster& operator=(Raycaster raycaster);

    virtual Raytracer* Clone() const;
};

#endif