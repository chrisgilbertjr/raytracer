
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

    virtual Raytracer* Clone() const;

    Raycaster& operator=(Raycaster raycaster);
};

#endif