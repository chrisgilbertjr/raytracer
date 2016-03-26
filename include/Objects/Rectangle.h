
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Object.h"

/// @defgroup Rectangle Rectangle
/// @{

/// rectangle object
class Rectangle : public Object
{
private:
    Vector m_vertices[3]; /// base vertex [0], width vector [1], height vector [2]
    Vector m_normal;      /// normal of the rectangle
    real m_v1Sq;          /// width vector length squared
    real m_v2Sq;          /// height vector length squared
    real m_area;          /// rectangle area

public:
    /// constructor
    Rectangle();

    /// constructor
    Rectangle(const Vector& a, real width, real height, bool reverse = false);

    /// constructor
    Rectangle(const Vector& a, const Vector& b, const Vector& c);

    /// copy constructor
    Rectangle(const Rectangle& rect);
    
    /// destructor
    virtual ~Rectangle();

    /// copy assignment operator
    Rectangle& operator=(Rectangle rect);

    /// deep copy of this object
    virtual Object* Clone() const;

    /// query this object for ray-intersections
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    /// query this object with shadow rays
    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    /// inverse area of the rectangle
    virtual float pdf(const ShadeRecord& record) const;

    /// compute the UV's of an object
    virtual void ComputeUV(ShadeRecord& record) const;

    /// flip the rectangles normal
    void FlipNormal();
};

/// --------------------------------------------------------------------------- FlipNormal

inline void 
Rectangle::FlipNormal() 
{ 
    m_normal = -m_normal; 
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif