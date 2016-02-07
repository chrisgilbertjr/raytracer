
#ifndef AREALIGHTING_H
#define AREALIGHTING_H

#include "Raytracer.h"

class AreaLighting : public Raytracer
{
private:

public:
    AreaLighting();

    AreaLighting(const AreaLighting& area);

    virtual ~AreaLighting();

    AreaLighting& operator=(AreaLighting area);

    virtual Raytracer* Clone() const;

    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

#endif