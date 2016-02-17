
#include "BRDFs\Lambertian.h"

Lambertian::Lambertian()
    : BRDF()
    , m_color(0.f, 0.f, 0.f)
    , m_intensity(1.0f)
{
    InitSampler();
}

Lambertian::Lambertian(const Lambertian& brdf)
    : BRDF(brdf)
    , m_color(brdf.m_color)
    , m_intensity(brdf.m_intensity)
{
    InitSampler();
}

Lambertian::~Lambertian() {}

Lambertian& 
Lambertian::operator=(Lambertian brdf)
{
    BRDF::operator=(brdf);
    Swap<Color>(m_color, brdf.m_color);
    Swap<real>(m_intensity, brdf.m_intensity);
    return *this;
}

BRDF* 
Lambertian::Clone() const
{
    return static_cast<Lambertian*>(new Lambertian(*this));
}

Color
Lambertian::Hue() const
{
    return m_color * m_intensity;
}

Color 
Lambertian::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return (Hue() * InvPi);
}

Color 
Lambertian::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const
{
    Vector w = record.normal;
    Vector v = Normalize(Cross(Vector(0.0034f, 1.f, 0.0071f), w));
    Vector u = Cross(v, w);

    Vector point = m_sampler->SampleHemisphere();
    wi = Normalize(point.x*u + point.y*v + point.z*w);
    pdf = Dot(record.normal, wi) * InvPi;

    return Hue() * InvPi;
}

Color 
Lambertian::P(const ShadeRecord& record, const Vector& wo) const
{
    return Hue();
}