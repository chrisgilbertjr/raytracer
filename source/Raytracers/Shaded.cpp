
#include "Raytracers\Shaded.h"
#include "BRDFs\ShadeRecord.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

Shaded::Shaded()
    : Raytracer()
{}

/// --------------------------------------------------------------------------- copy assignment operator

Shaded::Shaded(const Shaded& raycaster)
    : Raytracer()
{}

/// --------------------------------------------------------------------------- destructor

Shaded::~Shaded() {}

/// --------------------------------------------------------------------------- copy assignment operator

Shaded& 
Shaded::operator=(Shaded raycaster)
{
    /// copy and swap
    Raytracer::operator=(raycaster);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Raytracer* 
Shaded::Clone() const
{
    return static_cast<Raytracer*>(new Shaded(*this));
}

/// --------------------------------------------------------------------------- TraceRay

Color 
Shaded::TraceRay(const World* world, const Ray ray, const int depth) const
{
    ShadeRecord record = world->QueryObjects(ray);

    if (record.hit)
    {
        return record.material->Shade(record);
    }
    else
    {
        return world->GetBackground();
    }
}

/// --------------------------------------------------------------------------- EOF