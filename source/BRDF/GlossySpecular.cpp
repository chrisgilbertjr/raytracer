
#include "BRDFs\GlossySpecular.h"

GlossySpecular::GlossySpecular()
    : BRDF()
    , m_exp(1.0f)
    , m_intensity(1.0f)
    , m_color(0.f, 0.f, 0.f)
{}

GlossySpecular::GlossySpecular(const GlossySpecular& brdf)
    : BRDF(brdf)
    , m_exp(brdf.m_exp)
    , m_intensity(brdf.m_intensity)
    , m_color(brdf.m_color)
{}

GlossySpecular::~GlossySpecular()
{}

GlossySpecular& 
GlossySpecular::operator=(GlossySpecular brdf)
{
    BRDF::operator=(brdf);
    Swap<real>(m_exp, brdf.m_exp);
    Swap<real>(m_intensity, brdf.m_intensity);
    Swap<Color>(m_color, brdf.m_color);
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
    return m_color * m_intensity;
}

Color 
GlossySpecular::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    Color radiance(0.f, 0.f, 0.f);

    Vector E = wi; /// incoming 
    Vector L = wo; /// outgoing
    Vector N = record.normal; /// normal
    Vector R = -E + N * 2.0f * Dot(N, E); /// reflection

    real k = Dot(R, L); /// phong reflection: L = Color * Max(0, (R, V)^exp)

    if (k > 0.f)
    {
        radiance = Hue() * Pow(k, m_exp);
    }

    return radiance;
}

Color 
GlossySpecular::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo) const
{
    /// @TODO:
    return Color(0.f, 0.f, 0.f);
}

Color 
GlossySpecular::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}