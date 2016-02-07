
#ifndef LIGHT_OBJECT_H
#define LIGHT_OBJECT_H

#include "Object.h"
#include "..\Samplers\Sampler.h"

class LightObject
{
private:
    Material* m_material;
    Sampler* m_sampler;
    Object* m_object;

public:
    LightObject();

    LightObject(Object* object);

    LightObject(const LightObject& light);

    virtual ~LightObject();

    LightObject& operator=(LightObject light);

    LightObject* Clone() const;

    Vector Sample() const;

    Vector GetNormal(const Vector& point) const;

    Color Le(ShadeRecord& record) const;

    real pdf(const ShadeRecord& record) const;

};

#endif