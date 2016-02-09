
#include "BRDFs\GlossySpecular.h"
#include "Samplers\PureRandom.h"

GlossySpecular::GlossySpecular()
    : BRDF()
    , m_exp(1.0f)
    , m_intensity(1.0f)
    , m_color(0.f, 0.f, 0.f)
{
    m_sampler = new PureRandom(8);
    m_sampler->MapSamplesToHemisphere();
}

GlossySpecular::GlossySpecular(const GlossySpecular& brdf)
    : BRDF(brdf)
    , m_exp(brdf.m_exp)
    , m_intensity(brdf.m_intensity)
    , m_color(brdf.m_color)
{
    m_sampler = new PureRandom(8);
    m_sampler->MapSamplesToHemisphere();
}

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
GlossySpecular::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, real& pdf) const
{
   real NoR = Dot(record.normal, wo);
   Vector r = -wo + 2.f * record.normal * NoR;

   Vector w = r;
   Vector u = Normalize(Cross(Vector(0.00424f, 1.f, 0.00764f), w));
   Vector v = Cross(u, w);

   Vector point = m_sampler->SampleHemisphere();
   wi = point.x*u + point.y*v + point.z*w;

   if (Dot(record.normal, wi) < 0.f)
   {
       wi = -point.x*u - point.y*v + point.z*w;
   }

   real lobe = Pow(Dot(r, wi), m_exp);
   pdf = lobe * Dot(record.normal, wi);

   return Hue() * lobe;
}

Color 
GlossySpecular::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}