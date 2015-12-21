
#ifndef PATH_TRACER_H
#define PATH_TRACER_H

#include "Raytracer.h"

class PathTracer : public Raytracer
{
private:

public:
    PathTracer();

    PathTracer(const PathTracer& pathtracer);

    virtual ~PathTracer();

    virtual Raytracer* Clone() const;

    PathTracer& operator=(PathTracer pathtracer);
};

#endif