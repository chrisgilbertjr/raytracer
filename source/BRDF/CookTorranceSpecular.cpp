
#include "BRDFs\CookTorranceSpecular.h"

static float
D_GGX(const Vector& N, const Vector& H, float roughness)
{
    float NoH = Dot(N, H);
    float roughness2 = roughness * roughness;
    float NoH2 = NoH * NoH;

    float numerator   = (NoH > 0.f ? 1.f : 0.f) * roughness2;
    float denominator = NoH2 * roughness2 + (1.f - NoH2);
    denominator *= Pi * denominator;

    return numerator / denominator;
}

static float
G_GGX(const Vector& E, const Vector& N, const Vector& H, float roughness)
{
    float EoH = Saturate(Dot(E, H));
    float EoH2 = EoH * EoH;
    float tan = (1.f - EoH2) / EoH2;

    float numerator   = ((EoH/Saturate(Dot(E, N))) > 0.f ? 1.f : 0.f) * 2.0f;
    float denominator = 1.f + Sqrt(1.f + roughness * roughness * tan);

    return numerator / denominator;
}

static float
F_Schlick(const Vector& H, const Vector& E, float F0)
{
    return F0 + (1.f - F0) * powf(1.f - Dot(H, E), 5.f);
}

CookTorranceSpecular::CookTorranceSpecular()
    : m_distribution(NULL)
    , m_geometric(NULL)
    , m_fresnel(NULL)
    , m_roughness(0.2f)
    , m_incidence(0.0f)
    , m_color(Color::White())
{}

CookTorranceSpecular::CookTorranceSpecular(const CookTorranceSpecular& specular)
    : m_distribution(specular.m_distribution)
    , m_geometric(specular.m_geometric)
    , m_fresnel(specular.m_fresnel)
    , m_roughness(specular.m_roughness)
    , m_incidence(specular.m_incidence)
    , m_color(specular.m_color)
{}

CookTorranceSpecular::~CookTorranceSpecular()
{}

CookTorranceSpecular& 
CookTorranceSpecular::operator=(CookTorranceSpecular specular)
{
    BRDF::operator=(specular);
    Swap<t_Distribution>(m_distribution, specular.m_distribution);
    Swap<t_Geometric>(m_geometric, specular.m_geometric);
    Swap<t_Fresnel>(m_fresnel, specular.m_fresnel);
    Swap<float>(m_roughness, specular.m_roughness);
    Swap<float>(m_incidence, specular.m_incidence);
    Swap<Color>(m_color, specular.m_color);

    return *this;
}

BRDF* 
CookTorranceSpecular::Clone() const
{
    return static_cast<BRDF*>(new CookTorranceSpecular(*this));
}

Color 
CookTorranceSpecular::F(const ShadeRecord& record, const Vector& L, const Vector& E) const
{
    float incidence = 1.8f;

    Vector N = record.normal;
    Vector H = Normalize(Add(L, E));

    float D = D_GGX(N, H, m_roughness);
    float F = F_Schlick(H, E, incidence);
    float G = G_GGX(E, N, H, m_roughness);

    float numerator = D*F*G;
    float denominator = 4.f * Dot(N, E) * Dot(N, H);
    float color = Saturate(numerator / denominator);

    return Color(color, color, color);
}

Color 
CookTorranceSpecular::SampleF(const ShadeRecord& record, const Vector& L, const Vector& E) const
{
    return Color::White();
}

Color 
CookTorranceSpecular::P(const ShadeRecord& record, const Vector& E) const
{
    return Color::White();
}