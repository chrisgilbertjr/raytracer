
#ifndef PINHOLE_H
#define PINHOLE_H

#include "Cameras\Camera.h"

class Pinhole : public Camera
{
private:

public:
    Pinhole();

    Pinhole(const Pinhole& pinhole);

    virtual ~Pinhole();

    Pinhole& operator=(Pinhole pinhole);

    virtual Camera* Clone() const;

    virtual void Render(const World& world);
};

#endif