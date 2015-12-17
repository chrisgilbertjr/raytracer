
#ifndef OBJECT_H
#define OBJECT_H

#include "Core\MathUtils.h"

/// struct for raycast results
struct Raycast
{
    Vector localPoint;
    Vector normal;
    real tmin;
    real t;
    bool hit;
};

/// base object for object raycast queries
class Object
{
protected:

public:
    Object();

    ~Object();

    /// pure virtual function for raycast queries
    virtual Raycast Query(const Ray& ray) const = 0;
};

#endif