
#ifndef WHITTED_H
#define WHITTED_H

#include "Raytracer.h"

/// @defgroup Whitted Whitted
/// @{

/// ray tracer for recursive ray tracing
class Whitted : public Raytracer
{
public:
    /// constructor
    Whitted();

    /// copy constructor
    Whitted(const Whitted& whitted);

    /// destructor
    virtual ~Whitted();

    /// copy assignment operator
    Whitted& operator=(Whitted whitted);

    /// deep copy of this object
    virtual Raytracer* Clone() const;

    /// trace a ray
    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

/// @}

#endif