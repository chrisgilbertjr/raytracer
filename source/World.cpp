
#include "World.h"

World::World()
{
}

World::~World()
{
}

void 
World::SetBackgroundColor(const Color& color)
{
    m_background = color;
}

const ViewingPlane* 
World::GetViewingPlane() const
{
    return &m_viewingPlane;
}

const Array<Object*>* 
World::GetObjects() const
{
    return &m_objects;
}

const Raytracer* 
World::GetRaytracer() const
{
    return m_tracer;
}

Color 
World::GetBackgroundColor() const
{
    return m_background;
}

void 
World::PushObject(Object* object)
{
    m_objects.Push(object);
}

void 
World::RemoveObject(Object* object)
{
    m_objects.Remove(object);
}