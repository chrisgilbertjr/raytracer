
#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Core\MathUtils.h"
#include "Core\Color.h"

/// @defgroup Raytracer Raytracer
/// @{

/// base class for all ray tracers
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
    Raytracer(World* world);

    /// destructor
    virtual ~Raytracer();

    /// copy assignment operator
    Raytracer& operator=(Raytracer raytracer);

    /// deep copy this object
    virtual Raytracer* Clone() const;

    /// trace a ray
    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

/// @}

#endif