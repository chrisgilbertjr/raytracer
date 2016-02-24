
#ifndef COMPOUND_OBJECT_H
#define COMPOUND_OBJECT_H

#include "..\Core\Array.h"
#include "Object.h"

class CompoundObject : public Object
{
protected:
    Array<Object*> m_objects;

public:
    CompoundObject();

    CompoundObject(const CompoundObject& object);

    virtual ~CompoundObject();

    CompoundObject& operator=(CompoundObject object);

    virtual Object* Clone() const;

    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    void PushObject(Object* object);

    int GetObjectCount() const;
};

#endif