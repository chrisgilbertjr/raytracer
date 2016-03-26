
#ifndef PATH_TRACER_H
#define PATH_TRACER_H

#include "Raytracer.h"

/// @defgroup PathTracer PathTracer
/// @{

/// path tracing for global illumination
class PathTracer : public Raytracer
{
public:
    /// constructor
    PathTracer();

    /// copy constructor
    PathTracer(const PathTracer& tracer);

    /// destructor
    virtual ~PathTracer();

    /// copy assignment operator
    PathTracer& operator=(PathTracer tracer);

    /// deep copy this object
    virtual Raytracer* Clone() const;

    /// trace a ray
    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

/// @}

#endif