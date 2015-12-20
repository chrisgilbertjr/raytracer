
#include "BRDFs\BRDF.h"

BRDF::BRDF()
    : m_sampler(NULL)
{
}

BRDF::BRDF(const BRDF& brdf)
{
    if (brdf.m_sampler)
    {
        m_sampler = brdf.m_sampler->Clone();
    }
    else
    {
        m_sampler = NULL;
    }
}

BRDF::~BRDF()
{
    if (m_sampler)
    {
        delete m_sampler;
    }
}

BRDF& 
BRDF::operator=(BRDF brdf)
{
    Swap<Sampler*>(this->m_sampler, brdf.m_sampler);
    return *this;
}

BRDF* 
BRDF::Clone() const
{
    Assert(false);
    return NULL;
}

void 
BRDF::SetSampler(Sampler* sampler)
{
    if (m_sampler == sampler || !sampler) return;

    if (m_sampler)
    {
        delete m_sampler;
    }
    m_sampler = sampler;
}

Color 
BRDF::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return Color(0,0,0);
}

Color 
BRDF::SampleF(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return Color(0,0,0);
}

Color 
BRDF::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0,0,0);
}