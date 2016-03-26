
#ifndef OBJECT_H
#define OBJECT_H

#include "..\Materials\Material.h"
#include "..\BRDFs\ShadeRecord.h"

/// @defgroup Object Object
/// @{

/// base object for object raycast queries
class Object
{
protected:
    Material* m_material; /// the objects material
    Matrix m_transform;   /// the objects transform

    /// used to initialize records/results in query functions
    Raycast InitRaycastRecord(const Ray& ray, ShadeRecord& record) const;

    /// assigns the records/result in query functions
    void AssignRaycastRecord(Raycast& raycast, ShadeRecord& record, const Vector& normal, const Vector localPoint, real t) const;

public:
    /// constructor
    Object();

    /// copy constructor
    Object(const Object& object);

    /// constructor
    Object(const Vector& position, const Vector& axis, real angle, real scale);

    /// destructor
    virtual ~Object();

    /// copy assignment operator
    Object& operator=(Object object);

    /// deep copy this object
    virtual Object* Clone() const;

    /// query this object for ray-intersections
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    /// query this object with shadow rays
    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    /// inverse area of the object
    virtual float pdf(const ShadeRecord& record) const;

    /// compute the UV's of an object
    virtual void ComputeUV(ShadeRecord& record) const;

    /// set the objects transform
    void SetTransform(const Vector& position, const Vector& axis, real angle, real scale);

    /// get the objects material
    Material* GetMaterial() const;

    /// set the objects material
    void SetMaterial(Material* material);

    /// get the objects transform
    Matrix GetTransform() const;
};

/// --------------------------------------------------------------------------- GetMaterial

inline Material* 
Object::GetMaterial() const        
{ 
    return m_material; 
}

/// --------------------------------------------------------------------------- SetMaterial

inline void 
Object::SetMaterial(Material* material) 
{ 
    m_material = material; 
}

/// --------------------------------------------------------------------------- GetTransform

inline Matrix 
Object::GetTransform() const 
{ 
    return m_transform; 
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif