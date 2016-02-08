
#ifndef LIGHT_OBJECT_H
#define LIGHT_OBJECT_H

#include "Object.h"
#include "..\Samplers\Sampler.h"

class LightObject
{
protected:
    Material* m_material;
    Sampler* m_sampler;
    Object* m_object;

public:
    LightObject();

    LightObject(Object* object);

    LightObject(Object* object, Sampler* sampler);

    LightObject(const LightObject& light);

    virtual ~LightObject();

    LightObject& operator=(LightObject light);

    virtual LightObject* Clone() const;

    virtual Vector Sample() const;

    virtual Vector GetNormal(const Vector& point) const;

    virtual real pdf(const ShadeRecord& record) const;

    Color GetEmmisive(ShadeRecord& record) const;

    Object* GetObject() const;
};

inline Object* 
LightObject::GetObject() const
{
    return m_object;
}

#endif