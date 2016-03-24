
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "BRDF.h"
#include "..\Textures\Texture.h"

/// @defgroup Lambertian Lambertian
/// @{

class Texture;

/// lambertian diffuse brdf
class Lambertian : public BRDF
{
private:
    Texture* m_texture; /// texture. contains color component if texture isnt used
    real  m_intensity;  /// intensity

    Color Hue(const ShadeRecord& record) const; /// compute color (rho)

public:
    /// constructor
    Lambertian();

    /// constructor given a texture
    Lambertian(Texture* texture);

    /// copy constructor
    Lambertian(const Lambertian& brdf);

    /// destructor
    virtual ~Lambertian();

    /// copy assignment operator
    Lambertian& operator=(Lambertian brdf);

    /// deep copy the object
    virtual BRDF* Clone() const;

    /// evaluate f given an incoming and eye vector 
    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    /// sample f given an eye vector 
    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const;

    /// evaluate rho given an eye vector 
    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    /// set the intensity
    void SetIntensity(const real intensity);

    /// set the color
    void SetColor(const Color& color);

    /// set the texture
    void SetTexture(Texture* texture);

    /// ignore the diffuse texture resource.
    void Ignore();

    /// get the intensity
    real  GetIntensity();

    /// get the color
    Color GetColor();
};

/// @}

#endif