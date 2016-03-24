
#ifndef ENVIRONMENT_LIGHT_H
#define ENVIRONMENT_LIGHT_H

#include "Light.h"
#include "..\Samplers\Sampler.h"
#include "..\Materials\Material.h"

/// @defgroup EnvironmentLight EnvironmentLight
/// @{

class EnvironmentLight : public Light
{
private:
    Material* m_material; /// emmisive material
    Sampler* m_sampler;   /// the lights sampler
    Vector m_w;           /// w basis vector
    Vector m_u;           /// u basis vector
    Vector m_v;           /// v basis vector
    Vector m_wi;          /// sampler incoming vector

public:
    /// constructor
    EnvironmentLight();

    /// copy constructor
    EnvironmentLight(const EnvironmentLight& light);

    /// destructor
    virtual ~EnvironmentLight();

    /// copy assignment operator
    EnvironmentLight& operator=(EnvironmentLight light);

    /// deep copy this object
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

    /// sets the lights material
    void SetMaterial(Material* material);
};

/// --------------------------------------------------------------------------- SetMaterial

inline void 
EnvironmentLight::SetMaterial(Material* material)
{
    m_material = material;
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif