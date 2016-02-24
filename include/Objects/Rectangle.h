
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Object.h"

class Rectangle : public Object
{
private:
    Vector m_vertices[3]; /// counter-clockwise vertex order
    Vector m_normal;
    real m_v1Sq;
    real m_v2Sq;
    real m_area;


public:
    Rectangle();

    Rectangle(const Vector& a, real width, real height, bool reverse = false);

    Rectangle(const Vector& a, const Vector& b, const Vector& c);

    Rectangle(const Rectangle& rect);
    
    virtual ~Rectangle();

    Rectangle& operator=(Rectangle rect);

    virtual Object* Clone() const;

    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    virtual float pdf(const ShadeRecord& record) const;
};

#endif