
#include "Raytracers\AreaLighting.h"
#include "BRDFs\ShadeRecord.h"
#include "World\World.h"

AreaLighting::AreaLighting()
{}

AreaLighting::AreaLighting(const AreaLighting& raycaster)
{}

AreaLighting::~AreaLighting() {}

AreaLighting& 
AreaLighting::operator=(AreaLighting raycaster)
{
    Raytracer::operator=(raycaster);
    return *this;
}

Raytracer* 
AreaLighting::Clone() const
{
    return static_cast<Raytracer*>(new AreaLighting(*this));
}

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
