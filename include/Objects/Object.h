
#ifndef OBJECT_H
#define OBJECT_H

#include "..\Materials\Material.h"
#include "..\BRDFs\ShadeRecord.h"

/// base object for object raycast queries
class Object
{
protected:
    Material* m_material; /// the objects material

public:
    Object();

    ~Object();

    /// pure virtual function for raycast queries
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const = 0;

    /// ----------------------------------------------------------------------- Inline member functions

    /// get the objects material
    inline Material* GetMaterial() const        { return m_material; }

    /// set the objects material
    inline void SetMaterial(Material* material) { m_material = material; }
};

#endif