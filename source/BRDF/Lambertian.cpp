
#include "BRDFs\Lambertian.h"
#include "Samplers\Sampler.h"
#include "Textures\Texture.h"

Lambertian::Lambertian()
    : BRDF()
    , m_texture(new Texture(0.f, 0.f, 0.f))
    , m_intensity(1.0f)
{
    InitSampler();
}

Lambertian::Lambertian(Texture* texture)
    : BRDF()
    , m_texture(texture)
    , m_intensity(1.0f)
{
    InitSampler();
}

Lambertian::Lambertian(const Lambertian& brdf)
    : BRDF(brdf)
    , m_texture(brdf.m_texture->Clone())
    , m_intensity(brdf.m_intensity)
{
    InitSampler();
}

Lambertian::~Lambertian() 
{
    if (m_texture)
    {
        delete m_texture;
    }
}

Lambertian& 
Lambertian::operator=(Lambertian brdf)
{
    BRDF::operator=(brdf);
    Swap<Texture*>(m_texture, brdf.m_texture);
    Swap<real>(m_intensity, brdf.m_intensity);
    return *this;
}

BRDF* 
Lambertian::Clone() const
{
    return static_cast<Lambertian*>(new Lambertian(*this));
}

Color
Lambertian::Hue(const ShadeRecord& record) const
{
    return m_texture->GetTexel(record) * m_intensity;
}

Color 
Lambertian::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return (Hue(record) * InvPi);
}

Color 
Lambertian::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const
{
    Vector w = record.normal;
    Vector v = Normalize(Cross(Vector(0.0034f, 1.f, 0.0071f), w));
    Vector u = Cross(v, w);

    Vector point = m_sampler->SampleHemisphere();
    wi = point.x*u + point.y*v + point.z*w;
    wi = Normalize(wi);
    pdf = Dot(record.normal, wi) * InvPi;

    return Hue(record) * InvPi;
}

Color 
Lambertian::P(const ShadeRecord& record, const Vector& wo) const
{
    return Hue(record);
}

void 
Lambertian::SetIntensity(const real intensity)   
{ 
    m_intensity = intensity; 
}

void 
Lambertian::SetColor(const Color& color)
{
    m_texture->SetColor(color);
}

void 
Lambertian::SetTexture(Texture* texture)
{
    if (m_texture)
    {
        delete m_texture;
    }

    m_texture = texture;
}

void 
Lambertian::Ignore()
{
    m_texture = NULL;
}

real  
Lambertian::GetIntensity() 
{ 
    return m_intensity; 
}

Color 
Lambertian::GetColor() 
{ 
    return m_texture->GetColor(); 
}