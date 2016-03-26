
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Object.h"

/// @defgroup Cylinder Cylinder
/// @{

/// open cylinder
class Cylinder : public Object
{
private:
    Vector m_center; /// center of the cylinder
    real m_radius;   /// radius of the cylinder
    real m_min;      /// min of the cylinders height
    real m_max;      /// max of the clinders height

    /// compute the quadratic coeffs
    void Quadratic(const Ray& ray, real& a, real& b, real& c, real& d) const;

public:
    /// constructor
    Cylinder();

    /// constructor
    Cylinder(const Vector& center, real height, real radius);

    /// constructor
    Cylinder(const Vector& center, real min, real max, real radius);

    /// copy constructor
    Cylinder(const Cylinder& cylinder);

    /// destructor
    virtual ~Cylinder();

    /// copy assignment operator
    Cylinder& operator=(Cylinder cylinder);

    /// deep copy of this object
    virtual Object* Clone() const;

    /// query this object for ray-intersections
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    /// query this object with shadow rays
    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    /// compute the objects UV coordinates
    virtual void ComputeUV(ShadeRecord& record) const;
};

/// @}

#endif