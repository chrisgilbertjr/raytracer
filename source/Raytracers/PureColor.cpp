
#include "Raytracers\PureColor.h"
#include "BRDFs\ShadeRecord.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

PureColor::PureColor()
    : Raytracer()
{
}

/// --------------------------------------------------------------------------- constructor

PureColor::PureColor(const World* world)
    : Raytracer()
{
}

/// --------------------------------------------------------------------------- copy constructor

PureColor::PureColor(const PureColor& color)
    : Raytracer()
{
}

/// --------------------------------------------------------------------------- destructor

PureColor::~PureColor()
{
}

/// --------------------------------------------------------------------------- copy assignment operator

PureColor& 
PureColor::operator=(PureColor color)
{
    return *this;
}

/// --------------------------------------------------------------------------- Clone

Raytracer* 
PureColor::Clone() const
{
    return static_cast<Raytracer*>(new PureColor(*this));
}

/// --------------------------------------------------------------------------- TraceRay

Color 
PureColor::TraceRay(const World* world, const Ray ray, const int depth) const
{
    ShadeRecord record = world->QueryObjects(ray);

    if (record.hit)
    {
        return record.material->GetColor();
    }
    else
    {
        return world->GetBackground();
    }
}

/// --------------------------------------------------------------------------- EOF