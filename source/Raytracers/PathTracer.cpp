
#include "Raytracers\PathTracer.h"

PathTracer::PathTracer()
{
    /// @TODO:
}

PathTracer::PathTracer(const PathTracer& pathtracer)
{
    /// @TODO:
}

PathTracer::~PathTracer() {}

PathTracer& 
PathTracer::operator=(PathTracer pathtracer)
{
    /// @TODO:
    return *this;
}

Raytracer* 
PathTracer::Clone() const
{
    return static_cast<Raytracer*>(new PathTracer(*this));
}