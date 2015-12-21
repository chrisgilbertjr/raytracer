
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

    /// copy constructor
    Raytracer(const Raytracer& raytracer);

    /// constructor given a world pointer
    Raytracer(const World* world);

    /// destructor
    virtual ~Raytracer();

    /// clone a raytracer object
    virtual Raytracer* Clone() const;

    /// copy assignment operator
    Raytracer& operator=(Raytracer raytracer);

    /// trace a ray and return its color
    virtual Color TraceRay(const Ray& ray) const;
};

#endif