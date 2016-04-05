
#include "Raytracers\Raytracer.h"

/// --------------------------------------------------------------------------- constructor

Raytracer::Raytracer()
    : m_world(NULL)
{}

/// --------------------------------------------------------------------------- copy constructor

Raytracer::Raytracer(const Raytracer& raytracer)
    : m_world(raytracer.m_world)
{}

/// --------------------------------------------------------------------------- constructor

Raytracer::Raytracer(World* world)
    : m_world(world)
{}

/// --------------------------------------------------------------------------- destructor

Raytracer::~Raytracer() {}

/// --------------------------------------------------------------------------- copy assignment operator

Raytracer& 
Raytracer::operator=(Raytracer raytracer)
{
    /// copy and swap
    Swap<World*>(m_world, raytracer.m_world);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Raytracer* 
Raytracer::Clone() const
{
    Assert(false);
    return NULL;
}

/// --------------------------------------------------------------------------- TraceRay

Color 
Raytracer::TraceRay(const World* world, const Ray ray, const int depth) const
{
    return Color::Green();
}

/// --------------------------------------------------------------------------- EOF