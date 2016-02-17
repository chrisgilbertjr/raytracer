
#ifndef ENVIRONMENT_LIGHT_H
#define ENVIRONMENT_LIGHT_H

#include "Light.h"
#include "..\Samplers\Sampler.h"
#include "..\Materials\Material.h"

class EnvironmentLight : public Light
{
private:
    Material* m_material;
    Sampler* m_sampler;
    Vector m_w;
    Vector m_u;
    Vector m_v;
    Vector m_wi;

public:
    EnvironmentLight();

    EnvironmentLight(const EnvironmentLight& light);

    virtual ~EnvironmentLight();

    EnvironmentLight& operator=(EnvironmentLight light);

    virtual Light* Clone() const;

    /// get the direction of the light source
    virtual Vector GetDirection(ShadeRecord& record);

    /// compute the radiance of the light
    virtual Color Radiance(ShadeRecord& record);

    /// check if the light casts a shadow
    virtual bool CastsShadow() const;

    /// test a ray to see if the hit point is in a shadow
    virtual bool InShadow(const Ray& ray, ShadeRecord& record) const;

    virtual real pdf(const ShadeRecord& record) const;

    void SetMaterial(Material* material);
};

inline void 
EnvironmentLight::SetMaterial(Material* material)
{
    m_material = material;
}

#endif