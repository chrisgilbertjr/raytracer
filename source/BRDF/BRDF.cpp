
#include "BRDFs\BRDF.h"
#include "Samplers\PureRandom.h"

/// global sampler for path tracing if needed
Sampler* g_pathSampler = NULL;

// ---------------------------------------------------------------------------- Constructor

BRDF::BRDF()
    : m_sampler(NULL)
{}

// ---------------------------------------------------------------------------- Copy constructor

BRDF::BRDF(const BRDF& brdf)
{
    if (brdf.m_sampler && brdf.m_sampler != g_pathSampler)
    {
        m_sampler = brdf.m_sampler->Clone();
    }
    else
    {
        m_sampler = NULL;
    }
}

// ---------------------------------------------------------------------------- Destructor

BRDF::~BRDF()
{
    if (m_sampler && m_sampler != g_pathSampler)
    {
        delete m_sampler;
    }
}

// ---------------------------------------------------------------------------- Copy assignment operator

BRDF& 
BRDF::operator=(BRDF brdf)
{
    // copy and swap
    Swap<Sampler*>(this->m_sampler, brdf.m_sampler);
    return *this;
}

// ---------------------------------------------------------------------------- Clone

BRDF* 
BRDF::Clone() const
{
    /// cant clone abstract object
    Assert(false);
    return NULL;
}

// ---------------------------------------------------------------------------- SetSampler

void 
BRDF::SetSampler(Sampler* sampler)
{
    if (m_sampler == sampler || !sampler) return;

    if (m_sampler && m_sampler != g_pathSampler)
    {
        delete m_sampler;
    }
    m_sampler = sampler;
}

// ---------------------------------------------------------------------------- InitSampler

void 
BRDF::InitSampler()
{
    if (!m_sampler)
    {
        /// used for base colors
        m_sampler = new PureRandom(1);
        m_sampler->MapSamplesToHemisphere();
    }
}

// ---------------------------------------------------------------------------- F

Color 
BRDF::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    return Color(0,0,0);
}

// ---------------------------------------------------------------------------- SampleF

Color 
BRDF::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo) const
{
    return Color(0,0,0);
}

// ---------------------------------------------------------------------------- P

Color 
BRDF::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0,0,0);
}

// ---------------------------------------------------------------------------- EOF