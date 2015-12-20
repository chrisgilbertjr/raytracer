
#include "BRDFs\PerfectSpecular.h"

PerfectSpecular::PerfectSpecular()
    : BRDF()
    , m_kr(0.0f)
    , m_cr(0.f, 0.f, 0.f)
{}

PerfectSpecular::PerfectSpecular(const PerfectSpecular& brdf)
    : BRDF(brdf)
    , m_kr(brdf.m_kr)
    , m_cr(brdf.m_cr)
{}

PerfectSpecular::~PerfectSpecular()
{}

PerfectSpecular& 
PerfectSpecular::operator=(PerfectSpecular brdf)
{
    BRDF::operator=(brdf);
    Swap<real>(m_kr, brdf.m_kr);
    Swap<Color>(m_cr, brdf.m_cr);
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
    return m_cr * m_kr;
}

Color 
PerfectSpecular::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}

Color 
PerfectSpecular::SampleF(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    /// @TODO: 
    return Color(0.f, 0.f, 0.f);
}

Color 
PerfectSpecular::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}