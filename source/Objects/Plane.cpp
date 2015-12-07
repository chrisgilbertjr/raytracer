
#include "Objects\Plane.h"

Plane::Plane()
{
}

Plane::Plane(const Plane& plane)
{
}

Plane::Plane(const Vector& point, const Vector& normal)
{
}

Plane::Plane(const Vector& normal, real offset)
{
}

Plane::~Plane()
{
}

Plane& 
Plane::operator=(const Plane& plane)
{
    return *this;
}

Raycast 
Plane::Query(const Ray& ray) const
{
    Raycast result;

    return result;
}
