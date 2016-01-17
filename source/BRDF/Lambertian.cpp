
#include "BRDFs\Lambertian.h"

Lambertian::Lambertian()
    : BRDF()
    , m_scale(0.0f)
    , m_color(0.f, 0.f, 0.f)
{
}

Lambertian::Lambertian(const Lambertian& brdf)
    : BRDF(brdf)
    , m_scale(brdf.m_scale)
    , m_color(brdf.m_color)
{} 

Lambertian::~Lambertian() {}

Lambertian& 
Lambertian::operator=(Lambertian brdf)
{
    BRDF::operator=(brdf);
    Swap<real>(m_scale, brdf.m_scale);
    Swap<Color>(m_color, brdf.m_color);
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
    return m_color * m_scale;
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