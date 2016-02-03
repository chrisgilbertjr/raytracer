
#ifndef RAYCAST_H
#define RAYCAST_H

#include "Raytracer.h"

class Shaded : public Raytracer
{
private:

public:
    Shaded();

    Shaded(const Shaded& raycaster);

    virtual ~Shaded();

    Shaded& operator=(Shaded raycaster);

    virtual Raytracer* Clone() const;

    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

#endif