
#ifndef SHADE_RECORD_H
#define SHADE_RECORD_H

#include "..\Core\MathUtils.h"
#include "..\Core\Color.h"

/// @defgroup ShadeRecord ShadeRecord
/// @{

/// struct for shade records
struct ShadeRecord
{
    class Material* material; /// material pointer
    const class World* world; /// world pointer
    Vector worldPoint;        /// hit point in world space
    Vector localPoint;        /// hit point in local space
    Vector normal;            /// normal at the world hit point
    float u;                  /// texcoord
    float v;                  /// texcoord
    real  t;                  /// ray param
    bool hit;                 /// hit flag
    int depth;                /// ray recursion depth
    Ray ray;                  /// ray
};

/// --------------------------------------------------------------------------- ShadeRecordConstruct

inline ShadeRecord ShadeRecordConstruct(const class World* world)
{
    ShadeRecord record;
    record.material = NULL;
    record.world = world;
    record.worldPoint = Vector(0.f);
    record.localPoint = Vector(0.f);
    record.normal = Vector(0.f);
    record.u = 0.f;
    record.v = 0.f;
    record.t = 0.f;
    record.hit = false;
    record.depth = 0;
    record.ray = Ray();

    return record;
}

/// --------------------------------------------------------------------------- ShadeRecordCopy

inline ShadeRecord ShadeRecordCopy(const ShadeRecord& shade)
{
    ShadeRecord record;
    record.material = shade.material;
    record.world = shade.world;
    record.worldPoint = shade.localPoint;
    record.localPoint = shade.worldPoint;
    record.normal = shade.normal;
    record.u = shade.u;
    record.v = shade.v;
    record.t = shade.t;
    record.hit = shade.hit;
    record.depth = shade.depth;
    record.ray = shade.ray;

    return record;
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif