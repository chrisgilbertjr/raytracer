
#include "BRDFs\GlossySpecular.h"

GlossySpecular::GlossySpecular()
    : BRDF()
    , m_exp(1.0f)
    , m_ks(0.0f)
    , m_cs(0.f, 0.f, 0.f)
{}

GlossySpecular::GlossySpecular(const GlossySpecular& brdf)
    : BRDF(brdf)
    , m_exp(brdf.m_exp)
    , m_ks(brdf.m_ks)
    , m_cs(brdf.m_cs)
{}

GlossySpecular::~GlossySpecular()
{}

GlossySpecular& 
GlossySpecular::operator=(GlossySpecular brdf)
{
    BRDF::operator=(brdf);
    Swap<real>(m_exp, brdf.m_exp);
    Swap<real>(m_ks, brdf.m_ks);
    Swap<Color>(m_cs, brdf.m_cs);
    return *this;
}

BRDF* 
GlossySpecular::Clone() const
{
    return static_cast<BRDF*>(new GlossySpecular(*this));
}

Color
GlossySpecular::Hue() const
{
    return m_cs * m_ks;
}

Color 
GlossySpecular::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    Color L(0.f, 0.f, 0.f);

    Vector E = wi; /// incoming 
    Vector V = wo; /// outgoing
    Vector N = record.normal; /// normal
    Vector R = -E + (N * 2.0f) * Dot(N, E); /// reflection

    real k = Dot(R, V); /// phong reflection: L = Color * Max(0, (R, V)^exp)

    if (k > 0.f)
    {
        L = Hue() * Pow(k, m_exp);
    }

    return L;
}

Color 
GlossySpecular::SampleF(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    /// @TODO:
    return Color(0.f, 0.f, 0.f);
}

Color 
GlossySpecular::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}