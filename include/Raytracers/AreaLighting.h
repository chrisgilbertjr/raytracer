
#ifndef AREALIGHTING_H
#define AREALIGHTING_H

#include "Raytracer.h"

/// @defgroup AreaLighting AreaLighting
/// @{

/// area lighting ray tracer
class AreaLighting : public Raytracer
{
public:
    /// constructor
    AreaLighting();

    /// copy constructor
    AreaLighting(const AreaLighting& area);

    /// destructor
    virtual ~AreaLighting();

    /// copy assignment operator
    AreaLighting& operator=(AreaLighting area);

    /// deep copy of this object
    virtual Raytracer* Clone() const;

    /// trace a ray
    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

/// @}

#endif