
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

    PathTracer& operator=(PathTracer pathtracer);

    virtual Raytracer* Clone() const;
};

#endif