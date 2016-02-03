
#include "Raytracers\Raytracer.h"

Raytracer::Raytracer()
    : m_world(NULL)
{}

Raytracer::Raytracer(const Raytracer& raytracer)
    : m_world(raytracer.m_world)
{}

Raytracer::Raytracer(World* world)
    : m_world(world)
{}

Raytracer::~Raytracer() {}


Raytracer& 
Raytracer::operator=(Raytracer raytracer)
{
    Swap<World*>(m_world, raytracer.m_world);

    return *this;
}

Raytracer* 
Raytracer::Clone() const
{
    Assert(false);
    return NULL;
}

Color 
Raytracer::TraceRay(const World* world, const Ray ray, const int depth) const
{
    return Color::Green();
}