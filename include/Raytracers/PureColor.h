
#ifndef PURE_COLOR_H
#define PURE_COLOR_H

#include "Raytracer.h"

/// @defgroup PureColor PureColor
/// @{

/// ray tracing for base material colors only
class PureColor : public Raytracer
{
public:
    /// constructor
    PureColor();

    /// constructor
    PureColor(const World* world);

    /// copy constructor
    PureColor(const PureColor& color);

    /// destructor
    virtual ~PureColor();

    /// copy assignment operator
    PureColor& operator=(PureColor color);

    /// deep copy this object
    virtual Raytracer* Clone() const;

    /// trace a ray
    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

/// @}

#endif