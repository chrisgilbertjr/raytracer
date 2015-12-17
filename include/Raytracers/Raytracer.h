
#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Core\MathUtils.h"
#include "Core\Color.h"

class Raytracer
{
protected:
    class World* m_world; /// forward declare world class pointer

public:
    /// constructor
    Raytracer();

    /// constructor given a world pointer
    Raytracer(const World* world);

    /// destructor
    ~Raytracer();

    /// trace a ray and return its color
    virtual Color TraceRay(const Ray& ray) const;
};

#endif