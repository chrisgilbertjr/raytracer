
#ifndef SHADED_H
#define SHADED_H

#include "Raytracer.h"

/// @defgroup Shaded Shaded
/// @{

/// basic shading raytracer
class Shaded : public Raytracer
{
public:
    /// constructor
    Shaded();

    /// copy constructor
    Shaded(const Shaded& raycaster);

    /// destructor
    virtual ~Shaded();

    /// copy assignment operator
    Shaded& operator=(Shaded raycaster);

    /// deep copy this object
    virtual Raytracer* Clone() const;

    /// trace a ray
    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

/// @}

#endif