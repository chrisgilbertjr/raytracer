
#ifndef PURE_COLOR_H
#define PURE_COLOR_H

#include "Raytracer.h"

class PureColor : public Raytracer
{
private:

public:
    PureColor();

    PureColor(const World* world);

    PureColor(const PureColor& color);

    virtual ~PureColor();

    PureColor& operator=(PureColor color);

    virtual Raytracer* Clone() const;

    virtual Color TraceRay(const World* world, const Ray ray, const int depth) const;
};

#endif