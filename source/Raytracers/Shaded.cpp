
#include "Raytracers\Shaded.h"
#include "BRDFs\ShadeRecord.h"
#include "World\World.h"

Shaded::Shaded()
{
    /// @TODO:
}

Shaded::Shaded(const Shaded& raycaster)
{
    /// @TODO:
}

Shaded::~Shaded() {}

Shaded& 
Shaded::operator=(Shaded raycaster)
{
    /// @TODO:
    return *this;
}

Raytracer* 
Shaded::Clone() const
{
    return static_cast<Raytracer*>(new Shaded(*this));
}

Color 
Shaded::TraceRay(const World* world, const Ray& ray, const int depth) const
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