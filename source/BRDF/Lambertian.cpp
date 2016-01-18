
#include "BRDFs\Lambertian.h"

Lambertian::Lambertian()
    : BRDF()
    , m_color(0.f, 0.f, 0.f)
    , m_intensity(1.0f)
{
}

Lambertian::Lambertian(const Lambertian& brdf)
    : BRDF(brdf)
    , m_color(brdf.m_color)
    , m_intensity(brdf.m_intensity)
{} 

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
Lambertian::SampleF(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return Color(0,0,0); /// @TODO!
}

Color 
Lambertian::P(const ShadeRecord& record, const Vector& wo) const
{
    return Hue();
}