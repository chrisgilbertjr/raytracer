
#ifndef AREA_LIGHT_H
#define AREA_LIGHT_H

#include "..\Objects\LightObject.h"
#include "Light.h"

/// @defgroup AreaLight AreaLight
/// @{

class AreaLight : public Light
{
private:
    LightObject* m_object; /// a light object
    Vector m_point;        /// sampled point
    Vector m_normal;       /// lights normal
    Vector m_wi;           /// incomind ray direction

public:
    /// constructor
    AreaLight();

    /// constructor
    AreaLight(LightObject* object);

    /// copy constructor
    AreaLight(const AreaLight& light);

    /// destructor
    virtual ~AreaLight();

    /// copy assignment operator
    AreaLight& operator=(AreaLight light);

    /// deep copy of the object
    virtual Light* Clone() const;

    /// get the direction of the light source
    virtual Vector GetDirection(ShadeRecord& record);

    /// compute the radiance of the light
    virtual Color Radiance(ShadeRecord& record);

    /// check if the light casts a shadow
    virtual bool CastsShadow() const;

    /// test a ray to see if the hit point is in a shadow
    virtual bool InShadow(const Ray& ray, ShadeRecord& record) const;

    ///
    virtual real G(const ShadeRecord& record) const;

    virtual real pdf(const ShadeRecord& record) const;

    /// set the lights object
    void SetObject(LightObject* object);

    /// get the lights object
    Object* GetObject() const;
};

/// --------------------------------------------------------------------------- SetObject

inline void 
AreaLight::SetObject(LightObject* object)
{
    if (!m_object)
    {
        Assert(false);
    }

    m_object = object;
}
 
/// --------------------------------------------------------------------------- GetObject

inline Object* 
AreaLight::GetObject() const
{
    return m_object->GetObject();
}

/// --------------------------------------------------------------------------- EOF

#include "..\Objects\SphereLight.h"

/// sphere light macro for easy creation
#define SphereAreaLight(center, radius, sampler) AreaLight((LightObject*)new SphereLight(new Sphere(center, radius), sampler))

/// @}

#endif