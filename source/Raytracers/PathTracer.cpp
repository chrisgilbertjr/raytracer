
#include "Raytracers\PathTracer.h"
#include "World\World.h"

PathTracer::PathTracer()
    : Raytracer()
{
}

PathTracer::PathTracer(const PathTracer& tracer)
    : Raytracer(tracer)
{
}

PathTracer::~PathTracer() {}

PathTracer& 
PathTracer::operator=(PathTracer tracer)
{
    Raytracer::operator=(tracer);
    return *this;
}

Raytracer* 
PathTracer::Clone() const
{
    return static_cast<Raytracer*>(new PathTracer(*this));
}

Color 
PathTracer::TraceRay(const World* world, const Ray ray, const int depth) const
{
    if (depth > 2)
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