
#ifndef SPHERE_LIGHT_H
#define SPHERE_LIGHT_H

#include "LightObject.h"

class SphereLight : LightObject
{
public:
    SphereLight();

    SphereLight(Object* object);

    SphereLight(Object* object, Sampler* sampler);

    SphereLight(const SphereLight& light);

    virtual ~SphereLight();

    SphereLight& operator=(SphereLight light);

    virtual LightObject* Clone() const;

    virtual Vector Sample() const;

    virtual Vector GetNormal(const Vector& point) const;

    virtual real pdf(const ShadeRecord& record) const;
};

#endif