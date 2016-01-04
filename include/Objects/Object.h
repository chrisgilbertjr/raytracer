
#ifndef OBJECT_H
#define OBJECT_H

#include "..\Materials\Material.h"
#include "..\BRDFs\ShadeRecord.h"

/// base object for object raycast queries
class Object
{
protected:
    Material* m_material;

public:
    Object();

    ~Object();

    /// pure virtual function for raycast queries
    virtual Raycast Query(const Ray& ray, ShadeRecord& record) const = 0;
};

#endif