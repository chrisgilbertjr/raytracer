
#ifndef AREA_LIGHTING_H
#define AREA_LIGHTING_H

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
};

#endif