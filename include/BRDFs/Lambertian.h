
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "BRDF.h"
#include "..\Textures\Texture.h"

class Texture;

class Lambertian : public BRDF
{
private:
    Texture* m_texture;
    real  m_intensity;

    /// compute Rho without extram params
    Color Hue(const ShadeRecord& record) const;

public:
    Lambertian();

    Lambertian(Texture* texture);

    Lambertian(const Lambertian& brdf);

    virtual ~Lambertian();

    Lambertian& operator=(Lambertian brdf);

    virtual BRDF* Clone() const;

    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const;

    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const;

    virtual Color P(const ShadeRecord& record, const Vector& wo) const;

    void SetIntensity(const real intensity);

    void SetColor(const Color& color);

    void SetTexture(Texture* texture);

    real  GetIntensity();

    Color GetColor();
};

#endif