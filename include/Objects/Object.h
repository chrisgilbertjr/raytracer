
#ifndef OBJECT_H
#define OBJECT_H

#include "..\Materials\Material.h"
#include "..\BRDFs\ShadeRecord.h"

/// base object for object raycast queries
class Object
{
protected:
    Material* m_material; /// the objects material
    Matrix m_transform; /// the objects transform

    /// used to initialize records/results in query functions
    Raycast InitRaycastRecord(const Ray& ray, ShadeRecord& record) const;

    /// assigns the records/result in query functions
    void AssignRaycastRecord(Raycast& raycast, ShadeRecord& record, const Vector& normal, const Vector localPoint, real t) const;

public:
    Object();

    Object(const Object& object);

    Object(const Vector& position, const Vector& axis, real angle, real scale);

    virtual ~Object();

    /// copy assignment operator
    Object& operator=(Object object);

    /// pure virtual function for raycast queries
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const;

    virtual bool ShadowHit(const Ray& ray, float& tmin) const;

    void SetTransform(const Vector& position, const Vector& axis, real angle, real scale);

    /// ----------------------------------------------------------------------- Inline member functions

    /// get the objects material
    inline Material* GetMaterial() const        { return m_material; }

    /// set the objects material
    inline void SetMaterial(Material* material) { m_material = material; }

    inline Matrix GetTransform() const { return m_transform; }
};

#endif