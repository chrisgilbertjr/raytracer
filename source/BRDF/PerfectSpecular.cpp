
#include "BRDFs\PerfectSpecular.h"

PerfectSpecular::PerfectSpecular()
    : BRDF()
    , m_intensity(0.0f)
    , m_color(0.f, 0.f, 0.f)
{
    InitSampler();
}

PerfectSpecular::PerfectSpecular(const PerfectSpecular& brdf)
    : BRDF(brdf)
    , m_intensity(brdf.m_intensity)
    , m_color(brdf.m_color)
{
    InitSampler();
}

PerfectSpecular::~PerfectSpecular()
{}

PerfectSpecular& 
PerfectSpecular::operator=(PerfectSpecular brdf)
{
    BRDF::operator=(brdf);
    Swap<real>(m_intensity, brdf.m_intensity);
    Swap<Color>(m_color, brdf.m_color);
    return *this;
}

BRDF* 
PerfectSpecular::Clone() const
{
    return static_cast<BRDF*>(new PerfectSpecular(*this));
}


Color 
PerfectSpecular::Hue() const
{
    return m_color * m_intensity;
}

Color 
PerfectSpecular::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}

Color 
PerfectSpecular::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo) const
{
    float NoR = Dot(record.normal, wo);
    wi = -(wo - 2.f * NoR * record.normal);
    return ((m_intensity * m_color) / Dot(record.normal, wi));
}

Color 
PerfectSpecular::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const
{
    float NoR = Dot(record.normal, wo);
    wi = -(wo - 2.f * NoR * record.normal);
    pdf = Dot(record.normal, wi);

    return (m_intensity * m_color);
}

Color 
PerfectSpecular::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}