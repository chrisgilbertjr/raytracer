
#include "BRDFs\CookTorranceSpecular.h"

/// --------------------------------------------------------------------------- Dist_GGX

static float
Dist_GGX(const Vector& N, const Vector& H, float roughness)
{
    float roughness2 = roughness * roughness;
    float NoH = Dot(N, H);
    float NoH2 = NoH * NoH;

    float numerator   = ((NoH > 0.f) ? 1.f : 0.f) * roughness2;
    float denominator = NoH2 * roughness2 + (1.f - NoH2);
    denominator *= Pi * denominator;

    return numerator / denominator;
}

/// --------------------------------------------------------------------------- Geo_GGX_Partial

static float
Geo_GGX_Partial(const Vector& E, const Vector& N, const Vector& H, float roughness)
{
    float EoH = Saturate(Dot(E, H));
    float EoH2 = EoH * EoH;
    float tan = (1.f - EoH2) / EoH2;

    float numerator   = ((EoH/Saturate(Dot(E, N))) > 0.f ? 1.f : 0.f) * 2.0f;
    float denominator = 1.f + Sqrt(1.f + roughness * roughness * tan);

    return numerator / denominator;
}

/// --------------------------------------------------------------------------- Geo_GGX

static float
Geo_GGX(const Vector& E, const Vector& L, const Vector& N, const Vector& H, float roughness)
{
    return Geo_GGX_Partial(E, N, H, roughness) * Geo_GGX_Partial(L, N, H, roughness);
}

/// --------------------------------------------------------------------------- Fres_Schlick

static float
Fres_Schlick(const Vector& H, const Vector& E, float F0)
{
    return F0 + (1.f - F0) * powf(1.f - Dot(H, E), 5.f);
}

/// --------------------------------------------------------------------------- constructor

CookTorranceSpecular::CookTorranceSpecular()
    : BRDF()
    , m_distribution(Dist_GGX)
    , m_geometric(Geo_GGX)
    , m_fresnel(Fres_Schlick)
    , m_roughness(0.4f)
    , m_incidence(0.018f)
    , m_color(Color::White())
{}

/// --------------------------------------------------------------------------- copy constructor

CookTorranceSpecular::CookTorranceSpecular(const CookTorranceSpecular& specular)
    : BRDF(specular)
    , m_distribution(specular.m_distribution)
    , m_geometric(specular.m_geometric)
    , m_fresnel(specular.m_fresnel)
    , m_roughness(specular.m_roughness)
    , m_incidence(specular.m_incidence)
    , m_color(specular.m_color)
{}

/// --------------------------------------------------------------------------- destructor

CookTorranceSpecular::~CookTorranceSpecular()
{}

/// --------------------------------------------------------------------------- copy assignment operator

CookTorranceSpecular& 
CookTorranceSpecular::operator=(CookTorranceSpecular specular)
{
    /// copy and swap
    BRDF::operator=(specular);
    Swap<t_Distribution>(m_distribution, specular.m_distribution);
    Swap<t_Geometric>(m_geometric, specular.m_geometric);
    Swap<t_Fresnel>(m_fresnel, specular.m_fresnel);
    Swap<float>(m_roughness, specular.m_roughness);
    Swap<float>(m_incidence, specular.m_incidence);
    Swap<Color>(m_color, specular.m_color);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

BRDF* 
CookTorranceSpecular::Clone() const
{
    return static_cast<BRDF*>(new CookTorranceSpecular(*this));
}

/// --------------------------------------------------------------------------- F

Color 
CookTorranceSpecular::F(const ShadeRecord& record, const Vector& L, const Vector& E) const
{
    Vector N = record.normal;
    Vector H = Normalize(Add(L, E));

    real D = Dist_GGX(N, H, m_roughness);
    real F = Fres_Schlick(H, E, m_incidence);
    real G = Geo_GGX(E, L, N, H, m_roughness);

    real numerator = D*F*G;
    real denominator = 4.f * Dot(N, E) * Dot(N, H);
    real color = Saturate(numerator / denominator);

    return Color(color, color, color) * m_color;
}

/// --------------------------------------------------------------------------- SampleF

Color 
CookTorranceSpecular::SampleF(const ShadeRecord& record, Vector& L, const Vector& E) const
{
    return Color::White();
}

/// --------------------------------------------------------------------------- P

Color 
CookTorranceSpecular::P(const ShadeRecord& record, const Vector& E) const
{
    return Color::White();
}

/// --------------------------------------------------------------------------- EOF