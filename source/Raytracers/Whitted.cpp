
#include "Raytracers\Whitted.h"
#include "World\World.h"

Whitted::Whitted() {}

Whitted::Whitted(const Whitted& whitted) {}

Whitted::~Whitted() {}

Whitted& 
Whitted::operator=(Whitted whitted)
{
    Raytracer::operator=(whitted);
    return *this;
}

Raytracer* 
Whitted::Clone() const
{
    return static_cast<Raytracer*>(new Whitted(*this));
}

Color 
Whitted::TraceRay(const World* world, const Ray ray, const int depth) const
{
    if (depth > world->GetViewingPlane().GetMaxDepth())
    {
        return Color::Black();
    }
    else
    {
        ShadeRecord record = world->QueryObjects(ray);
        record.normal = Normalize(record.normal);

        if (record.hit)
        {
            record.depth = depth;
            record.ray = ray;

            return record.material->Shade(record);
        }
    }
    return world->GetBackground();
}