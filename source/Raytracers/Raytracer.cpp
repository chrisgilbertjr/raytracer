
#include "Raytracers\Raytracer.h"

Raytracer::Raytracer()
{
    /// @TODO:
}

Raytracer::Raytracer(const Raytracer& raytracer)
{
    /// @TODO:
}

Raytracer::Raytracer(const World* world)
{
    /// @TODO:
}

Raytracer::~Raytracer()
{
    /// @TODO:
}


Raytracer& 
Raytracer::operator=(Raytracer raytracer)
{
    /// @TODO:
    return *this;
}

Raytracer* 
Raytracer::Clone() const
{
    Assert(false);
    return NULL;
}

Color 
Raytracer::TraceRay(const Ray& ray, const int depth) const
{
    return Color(0.f, 0.f, 0.f);
}