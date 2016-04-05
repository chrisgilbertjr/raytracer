
#include "Raytracers\Whitted.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

Whitted::Whitted() {}

/// --------------------------------------------------------------------------- copy constructor

Whitted::Whitted(const Whitted& whitted) {}

/// --------------------------------------------------------------------------- destructor

Whitted::~Whitted() {}

/// --------------------------------------------------------------------------- copy assignment operator

Whitted& 
Whitted::operator=(Whitted whitted)
{
    Raytracer::operator=(whitted);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Raytracer* 
Whitted::Clone() const
{
    return static_cast<Raytracer*>(new Whitted(*this));
}

/// --------------------------------------------------------------------------- TraceRay

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

/// --------------------------------------------------------------------------- EOF