
#ifndef AREA_LIGHT_H
#define AREA_LIGHT_H

#include "..\Objects\LightObject.h"
#include "Light.h"

class AreaLight : public Light
{
private:
    LightObject* m_object; /// a light object
    Vector m_point;        /// sampled point
    Vector m_normal;       /// lights normal
    Vector m_wi;           /// incomind ray direction

public:
    AreaLight();

    AreaLight(LightObject* object);

    AreaLight(const AreaLight& light);

    virtual ~AreaLight();

    AreaLight& operator=(AreaLight light);

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

    void SetObject(LightObject* object);

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

#define SphereAreaLight(center, radius, sampler) AreaLight((LightObject*)new SphereLight(new Sphere(center, radius), sampler))

#endif