
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Object.h"

class Cylinder : public Object
{
private:
    Vector m_center;
    real m_height;
    real m_radius;

public:
    Cylinder();

    Cylinder(const Vector& center, real height, real radius);

    Cylinder(const Cylinder& cylinder);

    virtual ~Cylinder();

    Cylinder& operator=(Cylinder cylinder);

    virtual Object* Clone() const;

    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;
};

#endif