
#ifndef LIGHT_OBJECT_H
#define LIGHT_OBJECT_H

#include "Object.h"
#include "..\Samplers\Sampler.h"

/// @defgroup LightObject LightObject
/// @{

/// objects used as lights for area lighting
class LightObject
{
protected:
    Material* m_material; /// the objects emmisive material
    Sampler* m_sampler;   /// the sampler the object uses
    Object* m_object;     /// the object pointer

public:
    /// constructor
    LightObject();

    /// constructor
    LightObject(Object* object);

    /// constructor
    LightObject(Object* object, Sampler* sampler);

    /// copy constructor
    LightObject(const LightObject& light);

    /// destructor
    virtual ~LightObject();

    /// copy assignment operator
    LightObject& operator=(LightObject light);

    /// deep copy of this object
    virtual LightObject* Clone() const;

    /// sample a point on the object
    virtual Vector Sample() const;

    /// get the normal given a point on the object
    virtual Vector GetNormal(const Vector& point) const;

    /// inverse area of the object
    virtual real pdf(const ShadeRecord& record) const;

    /// get the emmisive color of the object
    Color GetEmmisive(ShadeRecord& record) const;

    /// get a pointer to the object
    Object* GetObject() const;
};

/// --------------------------------------------------------------------------- GetObject

inline Object* 
LightObject::GetObject() const
{
    return m_object;
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif