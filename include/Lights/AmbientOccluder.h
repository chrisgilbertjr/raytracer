
#ifndef AMBIENT_OCCULDER_H
#define AMBIENT_OCCULDER_H

#include "..\Samplers\Sampler.h"
#include "Light.h"

/// @defgroup AmbientOccluder AmbientOccluder
/// @{

class AmbientOccluder : public Light
{
private:
    Sampler* m_sampler; /// hemisphere sampler
    Color m_minAmount;  /// min color of the ambient light
    Color m_color;      /// color of the ambient light
    Vector m_u;         /// u basis vector (up)
    Vector m_v;         /// v basis vector (view)
    Vector m_w;         /// w basis vector (right)
    real m_intensity;   /// intensity of the light

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

/// @}

#endif