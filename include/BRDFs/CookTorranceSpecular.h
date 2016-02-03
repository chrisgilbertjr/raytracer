
#ifndef COOK_TORRANCE_SPECULAR_H
#define COOK_TORRANCE_SPECULAR_H

#include "BRDF.h"

typedef float (*t_Geometric)(const Vector& E, const Vector& L, const Vector& N, const Vector& H, float roughness);
typedef float (*t_Distribution)(const Vector& N, const Vector& H, float roughness);
typedef float (*t_Fresnel)(const Vector& H, const Vector& E, float F0);
/// cosT = HoE

enum CT_GEOMETRIC
{
    G_GGX,
};

enum CT_DISTRIBUTION
{
    D_GGX,
};

enum CT_FRESNEL
{
    F_SCHLICK,
};

class CookTorranceSpecular : public BRDF
{
private:
    t_Distribution m_distribution;
    t_Geometric m_geometric;
    t_Fresnel m_fresnel;
    float m_roughness;
    float m_incidence;
    Color m_color;

public:
    CookTorranceSpecular();

    CookTorranceSpecular(const CookTorranceSpecular& specular);

    virtual ~CookTorranceSpecular();

    CookTorranceSpecular& operator=(CookTorranceSpecular specular);

    virtual BRDF* Clone() const;

    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& E) const;

    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& E) const;

    virtual Color P(const ShadeRecord& record, const Vector& E) const;

    void SetRoughness(float roughness);

    void SetIncidence(float incidence);

    void SetColor(const Color& color);

    float GetRoughness() const;

    float GetIncidence() const;

    float GetF0() const;

    t_Fresnel GetFresnal() const;
};

inline void 
CookTorranceSpecular::SetRoughness(float roughness)
{
    m_roughness = roughness;
}

inline void 
CookTorranceSpecular::SetIncidence(float incidence)
{
    m_incidence = incidence;
}

inline void 
CookTorranceSpecular::SetColor(const Color& color)
{
    m_color = color;
}

inline float 
CookTorranceSpecular::GetRoughness() const
{
    return m_roughness;
}

inline float 
CookTorranceSpecular::GetIncidence() const
{
    return m_incidence;
}

inline float 
CookTorranceSpecular::GetF0() const
{
    float a = m_incidence - 1.f;
    float b = m_incidence + 1.f;
    return (a*a) / (b*b);
}

inline t_Fresnel 
CookTorranceSpecular::GetFresnal() const
{
    return m_fresnel;
}

#endif