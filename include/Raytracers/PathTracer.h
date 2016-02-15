
#ifndef PATH_TRACER_H
#define PATH_TRACER_H

#include "Raytracer.h"

class PathTracer : public Raytracer
{
public:
    PathTracer();

    PathTracer(const PathTracer& tracer);

    virtual ~PathTracer();

    PathTracer& operator=(PathTracer tracer);

    virtual Raytracer* Clone() const;

    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

#endif