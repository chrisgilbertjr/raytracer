
#include "Raytracers\PathTracer.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

PathTracer::PathTracer()
    : Raytracer()
{
}

/// --------------------------------------------------------------------------- copy constructor

PathTracer::PathTracer(const PathTracer& tracer)
    : Raytracer(tracer)
{
}

/// --------------------------------------------------------------------------- destructor

PathTracer::~PathTracer() {}

/// --------------------------------------------------------------------------- copy assignment operator

PathTracer& 
PathTracer::operator=(PathTracer tracer)
{
    Raytracer::operator=(tracer);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Raytracer* 
PathTracer::Clone() const
{
    return static_cast<Raytracer*>(new PathTracer(*this));
}

/// --------------------------------------------------------------------------- TraceRay

Color 
PathTracer::TraceRay(const World* world, const Ray ray, const int depth) const
{
    if (depth > world->GetViewingPlane().GetMaxDepth())
    {
        return Color::Black();
    }
    else
    {
        ShadeRecord record = world->QueryObjects(ray);

        if (record.hit)
        {
            record.depth = depth;
            record.ray = ray;

            return record.material->PathShade(record);
        }
    }

    return world->GetBackground();
}

/// --------------------------------------------------------------------------- EOF