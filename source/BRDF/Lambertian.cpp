
#include "BRDFs\Lambertian.h"

Lambertian::Lambertian()
    : BRDF()
    , m_kd(0.0f)
    , m_cd(0.f, 0.f, 0.f)
{
}

Lambertian::Lambertian(const Lambertian& brdf)
    : BRDF(brdf)
    , m_kd(brdf.m_kd)
    , m_cd(brdf.m_cd)
{
}

Lambertian::~Lambertian() {}

Lambertian& 
Lambertian::operator=(Lambertian brdf)
{
    BRDF::operator=(brdf);
    Swap<real>(m_kd, brdf.m_kd);
    Swap<Color>(m_cd, brdf.m_cd);
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
    return m_cd * m_kd;
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