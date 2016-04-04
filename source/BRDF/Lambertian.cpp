
#include "BRDFs\Lambertian.h"
#include "Samplers\PureRandom.h"
#include "Textures\Texture.h"

/// --------------------------------------------------------------------------- constructor

Lambertian::Lambertian()
    : BRDF()
    , m_texture(new Texture(0.f, 0.f, 0.f))
    , m_intensity(1.0f)
{
    m_sampler = new PureRandom(1);
}

/// --------------------------------------------------------------------------- constructor

Lambertian::Lambertian(Texture* texture)
    : BRDF()
    , m_texture(texture)
    , m_intensity(1.0f)
{
    InitSampler();
}

/// --------------------------------------------------------------------------- copy constructor

Lambertian::Lambertian(const Lambertian& brdf)
    : BRDF(brdf)
    , m_texture(brdf.m_texture->Clone())
    , m_intensity(brdf.m_intensity)
{
    InitSampler();
}

/// --------------------------------------------------------------------------- destructor

Lambertian::~Lambertian() 
{
    if (m_texture)
    {
        delete m_texture;
    }
}

/// --------------------------------------------------------------------------- copy assignment operator

Lambertian& 
Lambertian::operator=(Lambertian brdf)
{
    /// copy and swap
    BRDF::operator=(brdf);
    Swap<Texture*>(m_texture, brdf.m_texture);
    Swap<real>(m_intensity, brdf.m_intensity);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

BRDF* 
Lambertian::Clone() const
{
    return static_cast<Lambertian*>(new Lambertian(*this));
}

/// --------------------------------------------------------------------------- Hue

Color
Lambertian::Hue(const ShadeRecord& record) const
{
    /// compute color at a texel
    return m_texture->GetTexel(record) * m_intensity;
}

/// --------------------------------------------------------------------------- F

Color 
Lambertian::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return (Hue(record) * InvPi);
}

/// --------------------------------------------------------------------------- SampleF

Color 
Lambertian::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const
{
    /// compute basis from normal
    Vector w = Normalize(record.normal);
    Vector v = Normalize(Cross(Vector(0.0034f, 1.f, 0.0071f), w));
    Vector u = Cross(v, w);

    /// sample the hemisphere at a given point
    Vector point = g_pathSampler->SampleHemisphere();

    /// reflection vector from sampled point and the basis
    wi = Normalize(point.x*u + point.y*v + point.z*w);
    pdf = Dot(record.normal, wi) * InvPi ;

    /// compute the radiance 
    return Hue(record) * InvPi;
}

/// --------------------------------------------------------------------------- P

Color 
Lambertian::P(const ShadeRecord& record, const Vector& wo) const
{
    return Hue(record);
}

/// --------------------------------------------------------------------------- SetIntensity

void 
Lambertian::SetIntensity(const real intensity)   
{ 
    m_intensity = intensity; 
}

/// --------------------------------------------------------------------------- SetColor

void 
Lambertian::SetColor(const Color& color)
{
    m_texture->SetColor(color);
}

/// --------------------------------------------------------------------------- SetTexture

void 
Lambertian::SetTexture(Texture* texture)
{
    if (m_texture)
    {
        delete m_texture;
    }

    m_texture = texture;
}

/// --------------------------------------------------------------------------- Ignore

void 
Lambertian::Ignore()
{
    m_texture = NULL;
}

/// --------------------------------------------------------------------------- GetIntensity

real  
Lambertian::GetIntensity() 
{ 
    return m_intensity; 
}

/// --------------------------------------------------------------------------- GetColor

Color 
Lambertian::GetColor() 
{ 
    return m_texture->GetColor(); 
}

/// --------------------------------------------------------------------------- EOF