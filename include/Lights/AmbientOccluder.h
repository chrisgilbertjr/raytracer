
#ifndef AMBIENT_OCCULDER_H
#define AMBIENT_OCCULDER_H

#include "..\Samplers\Sampler.h"
#include "Light.h"

class AmbientOccluder : public Light
{
private:
    Sampler* m_sampler;
    Color m_minAmount;
    Color m_color;
    Vector m_u;
    Vector m_v;
    Vector m_w;
    real m_intensity;

public:
    /// constructor
    AmbientOccluder();

    /// copy constructor
    AmbientOccluder(const AmbientOccluder& occluder);

    /// destructor
    virtual ~AmbientOccluder();

    /// copy assignment operator
    AmbientOccluder& operator=(AmbientOccluder occluder);

    /// sets the sampler
    void SetSampler(Sampler* sampler);

    /// deep copy of this light object
    virtual Light* Clone() const;

    /// get the direction of the light
    virtual Vector GetDirection(ShadeRecord& record);

    /// compute the radiance of the light
    virtual Color Radiance(ShadeRecord& record);

    /// check if the light casts a shadow
    virtual bool CastsShadow() const;

    /// test a ray to see if the hit point is in a shadow
    virtual bool InShadow(const Ray& ray, ShadeRecord& record) const;
};

#endif