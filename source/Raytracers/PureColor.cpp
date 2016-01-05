
#include "Raytracers\PureColor.h"
#include "BRDFs\ShadeRecord.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- Constructor

PureColor::PureColor()
{
}

/// --------------------------------------------------------------------------- Constructor

PureColor::PureColor(const World* world)
{
}

/// --------------------------------------------------------------------------- Copy constructor

PureColor::PureColor(const PureColor& color)
{
}

/// --------------------------------------------------------------------------- Destructor

PureColor::~PureColor()
{
}

/// --------------------------------------------------------------------------- Copy assignment operator

PureColor& 
PureColor::operator=(PureColor color)
{
}

/// --------------------------------------------------------------------------- Clone

Raytracer* 
PureColor::Clone() const
{
    return static_cast<Raytracer*>(new PureColor(*this));
}

/// --------------------------------------------------------------------------- TraceRay

Color 
PureColor::TraceRay(const World* world, const Ray& ray, const int depth) const
{
    ShadeRecord record = world->QueryObjects(ray);

    if (record.hit)
    {
        /// get material from shade record
        /// return the color
    }
    else
    {
        return world->GetBackground();
    }
}

/// --------------------------------------------------------------------------- EOF