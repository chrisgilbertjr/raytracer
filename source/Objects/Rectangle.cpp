
#include "Objects\Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(const Rectangle& rect)
{
}

Rectangle::~Rectangle()
{
}

Rectangle& 
Rectangle::operator=(Rectangle rect)
{
}

Object* 
Rectangle::Clone() const
{
    return static_cast<Object*>(new Rectangle(*this));
}

Raycast 
Rectangle::Query(const Ray& ray, ShadeRecord& record) const
{
    Ray r = m_transform.TransformRaycast(ray);
    Raycast result = Object::InitRaycastRecord(ray, record);
    
    return result;
}

bool 
Rectangle::ShadowHit(const Ray& ray, float& tmin) const
{
    return false;
}