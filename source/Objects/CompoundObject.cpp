
#include "Objects\CompoundObject.h"

CompoundObject::CompoundObject()
    : Object()
    , m_objects(4)
{
}

CompoundObject::CompoundObject(const CompoundObject& object)
    : Object(object)
{
    /// deep array copy
    for (int i = 0; i < object.m_objects.GetSize(); ++i)
    {
        m_objects.Push(object.m_objects[i]->Clone());
    }
}

CompoundObject::~CompoundObject()
{
    for (int i = 0; i < m_objects.GetSize(); ++i)
    {
        delete m_objects[i];
        m_objects[i] = NULL;
    }
}

CompoundObject& 
CompoundObject::operator=(CompoundObject object)
{
    Object::operator=(object);

    for (int i = 0; i < object.m_objects.GetSize(); ++i)
    {
        Swap<Object*>(m_objects[i], object.m_objects[i]);
    }
}

Object* 
CompoundObject::Clone() const
{
    return static_cast<Object*>(new CompoundObject(*this));
}

Raycast 
CompoundObject::Query(const Ray& ray, ShadeRecord& record) const
{
    Raycast result = Object::InitRaycastRecord(ray, record);

    /// @TODO:

    return result;
}

bool 
CompoundObject::ShadowHit(const Ray& ray, float& tmin) const
{
    /// @TODO:

    return false;
}

void 
CompoundObject::PushObject(Object* object)
{
    m_objects.Push(object);
}

int 
CompoundObject::GetObjectCount() const
{
    return m_objects.GetSize();
}