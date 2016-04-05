
#include "Raytracers\AreaLighting.h"
#include "BRDFs\ShadeRecord.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

AreaLighting::AreaLighting()
    : Raytracer()
{}

/// --------------------------------------------------------------------------- copy construtor

AreaLighting::AreaLighting(const AreaLighting& raycaster)
    : Raytracer()
{}

/// --------------------------------------------------------------------------- destructor

AreaLighting::~AreaLighting() {}

/// --------------------------------------------------------------------------- copy assignment operator

AreaLighting& 
AreaLighting::operator=(AreaLighting raycaster)
{
    Raytracer::operator=(raycaster);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Raytracer* 
AreaLighting::Clone() const
{
    return static_cast<Raytracer*>(new AreaLighting(*this));
}

/// --------------------------------------------------------------------------- TraceRay

Color 
AreaLighting::TraceRay(const World* world, const Ray ray, const int depth) const
{
    ShadeRecord record = world->QueryObjects(ray);

    if (record.hit)
    {
        record.ray = ray;
        return record.material->AreaLightShade(record);
    }
    else
    {
        return world->GetBackground();
    }
}

/// --------------------------------------------------------------------------- EOF