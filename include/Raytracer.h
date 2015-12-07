
#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "MathUtils.h"
#include "Color.h"

class Raytracer
{
private:
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