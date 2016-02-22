
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Object.h"

class Rectangle : public Object
{
private:

public:
    Rectangle();

    Rectangle(const Rectangle& rect);
    
    virtual ~Rectangle();

    Rectangle& operator=(Rectangle rect);

    virtual Object* Clone() const;

    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    virtual bool ShadowHit(const Ray& ray, float& tmin) const;
};

#endif