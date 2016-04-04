
#include "BRDFs\PerfectSpecular.h"

/// --------------------------------------------------------------------------- constructor

PerfectSpecular::PerfectSpecular()
    : BRDF()
    , m_intensity(0.0f)
    , m_color(0.f, 0.f, 0.f)
{
    InitSampler();
}

/// --------------------------------------------------------------------------- copy constructor

PerfectSpecular::PerfectSpecular(const PerfectSpecular& brdf)
    : BRDF(brdf)
    , m_intensity(brdf.m_intensity)
    , m_color(brdf.m_color)
{
    InitSampler();
}

/// --------------------------------------------------------------------------- destructor

PerfectSpecular::~PerfectSpecular()
{}

/// --------------------------------------------------------------------------- copy assignment operator

PerfectSpecular& 
PerfectSpecular::operator=(PerfectSpecular brdf)
{
    /// copy and swap
    BRDF::operator=(brdf);
    Swap<real>(m_intensity, brdf.m_intensity);
    Swap<Color>(m_color, brdf.m_color);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

BRDF* 
PerfectSpecular::Clone() const
{
    return static_cast<BRDF*>(new PerfectSpecular(*this));
}

/// --------------------------------------------------------------------------- Hue

Color 
PerfectSpecular::Hue() const
{
    return m_color * m_intensity;
}

/// --------------------------------------------------------------------------- F

Color 
PerfectSpecular::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}

/// --------------------------------------------------------------------------- SampleF

Color 
PerfectSpecular::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo) const
{
    /// reflection vector
    float NoR = Dot(record.normal, wo);
    wi = -(wo - 2.f * NoR * record.normal);

    /// compute radiance
    return ((m_intensity * m_color) / Dot(record.normal, wi));
}

/// --------------------------------------------------------------------------- P

Color 
PerfectSpecular::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, float& pdf) const
{
    /// reflection vector
    float NoR = Dot(record.normal, wo);
    wi = -(wo - 2.f * NoR * record.normal);
    pdf = Dot(record.normal, wi);

    /// compute radiance
    return (m_intensity * m_color);
}

/// --------------------------------------------------------------------------- SampleF

Color 
PerfectSpecular::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}

/// --------------------------------------------------------------------------- EOF