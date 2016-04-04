
#include "BRDFs\GlossySpecular.h"
#include "Samplers\PureRandom.h"

/// --------------------------------------------------------------------------- constructor

GlossySpecular::GlossySpecular()
    : BRDF()
    , m_exp(1.0f)
    , m_intensity(1.0f)
    , m_color(0.f, 0.f, 0.f)
{
    m_sampler = new PureRandom(8);
    m_sampler->MapSamplesToHemisphere();
}

/// --------------------------------------------------------------------------- copy constructor

GlossySpecular::GlossySpecular(const GlossySpecular& brdf)
    : BRDF(brdf)
    , m_exp(brdf.m_exp)
    , m_intensity(brdf.m_intensity)
    , m_color(brdf.m_color)
{
    m_sampler = new PureRandom(8);
    m_sampler->MapSamplesToHemisphere();
}

/// --------------------------------------------------------------------------- destructor

GlossySpecular::~GlossySpecular()
{}

/// --------------------------------------------------------------------------- copy assignment operator

GlossySpecular& 
GlossySpecular::operator=(GlossySpecular brdf)
{
    BRDF::operator=(brdf);
    Swap<real>(m_exp, brdf.m_exp);
    Swap<real>(m_intensity, brdf.m_intensity);
    Swap<Color>(m_color, brdf.m_color);
    return *this;
}

/// --------------------------------------------------------------------------- Clone

BRDF* 
GlossySpecular::Clone() const
{
    return static_cast<BRDF*>(new GlossySpecular(*this));
}

/// --------------------------------------------------------------------------- Hue

Color
GlossySpecular::Hue() const
{
    return m_color * m_intensity;
}

/// --------------------------------------------------------------------------- F

Color 
GlossySpecular::F(const ShadeRecord& record, const Vector& wi, const Vector& wo) const
{
    Color radiance(0.f, 0.f, 0.f);

    Vector E = wi; /// incoming 
    Vector L = wo; /// outgoing
    Vector N = record.normal; /// normal
    Vector R = -E + N * 2.0f * Dot(N, E); /// reflection

    real k = Dot(R, L); /// phong reflection: L = Color * Max(0, (R, V)^exp)

    /// compute radiance if visible
    if (k > 0.f)
    {
        radiance = Hue() * Pow(k, m_exp);
    }

    return radiance;
}

/// --------------------------------------------------------------------------- SampleF

Color 
GlossySpecular::SampleF(const ShadeRecord& record, Vector& wi, const Vector& wo, real& pdf) const
{
   real NoR = Dot(record.normal, wo);

   /// reflection vector
   Vector r = -wo + 2.f * record.normal * NoR;

   /// compute basis
   Vector w = r;
   Vector u = Normalize(Cross(Vector(0.00424f, 1.f, 0.00764f), w));
   Vector v = Cross(u, w);

   /// sample point and compute normal
   Vector point = m_sampler->SampleHemisphere();
   wi = Normalize(point.x*u + point.y*v + point.z*w);

   /// check if we have an inter-reflection
   if (Dot(record.normal, wi) < 0.f)
   {
       wi = -point.x*u - point.y*v + point.z*w;
   }

   /// spec lobe
   real lobe = Pow(Dot(r, wi), m_exp);
   pdf = lobe * Dot(record.normal, wi);

   return Hue() * lobe;
}

/// --------------------------------------------------------------------------- P

Color 
GlossySpecular::P(const ShadeRecord& record, const Vector& wo) const
{
    return Color(0.f, 0.f, 0.f);
}

/// --------------------------------------------------------------------------- EOF