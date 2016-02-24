
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Object.h"

class Cylinder : public Object
{
private:
    Vector m_center;
    real m_radius;
    real m_min;
    real m_max;

    void Quadratic(const Ray& ray, real& a, real& b, real& c, real& d) const;

public:
    Cylinder();

    Cylinder(const Vector& center, real height, real radius);

    Cylinder(const Vector& center, real min, real max, real radius);

    Cylinder(const Cylinder& cylinder);

    virtual ~Cylinder();

    Cylinder& operator=(Cylinder cylinder);

    virtual Object* Clone() const;

    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    virtual bool ShadowHit(const Ray& ray, float& tmin) const;
};

#endif