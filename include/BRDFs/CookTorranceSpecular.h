
#ifndef COOK_TORRANCE_SPECULAR_H
#define COOK_TORRANCE_SPECULAR_H

#include "BRDF.h"

/// @defgroup CookTorranceSpecular CookTorranceSpecular
/// @{

/// function pointers for Cook-Torrance lighting equation
typedef float (*t_Geometric)(const Vector& E, const Vector& L, const Vector& N, const Vector& H, float roughness);
typedef float (*t_Distribution)(const Vector& N, const Vector& H, float roughness);
typedef float (*t_Fresnel)(const Vector& H, const Vector& E, float F0);
/// cosT = HoE

/// geometric term in microfacted BRDF equation
enum CT_GEOMETRIC
{
    G_GGX,
};

/// distribution term in microfacted BRDF equation
enum CT_DISTRIBUTION
{
    D_GGX,
};

/// fresnel term in microfacted BRDF equation
enum CT_FRESNEL
{
    F_SCHLICK,
};

/// Cook-Torrance microfaceted specular BRDF
class CookTorranceSpecular : public BRDF
{
private:
    t_Distribution m_distribution; /// D term
    t_Geometric m_geometric;       /// G term
    t_Fresnel m_fresnel;           /// F term
    float m_roughness;             /// roughness of the material
    float m_incidence;             /// IOR of the material
    Color m_color;                 /// base color of the material

public:
    /// constructor
    CookTorranceSpecular();

    /// copy constructor
    CookTorranceSpecular(const CookTorranceSpecular& specular);

    /// destructor
    virtual ~CookTorranceSpecular();

    /// copy assignment operator
    CookTorranceSpecular& operator=(CookTorranceSpecular specular);

    /// deep copy of the object
    virtual BRDF* Clone() const;

    /// evaluate f given an incoming and eye vector 
    virtual Color F(const ShadeRecord& record, const Vector& wi, const Vector& E) const;

    /// sample f given an eye vector 
    virtual Color SampleF(const ShadeRecord& record, Vector& wi, const Vector& E) const;

    /// evaluate f given an eye vector 
    virtual Color P(const ShadeRecord& record, const Vector& E) const;

    /// set the roughness of the material
    void SetRoughness(float roughness);

    /// set the IOR of the material
    void SetIncidence(float incidence);

    /// set the base color of the material
    void SetColor(const Color& color);

    /// get the roughness of the material
    float GetRoughness() const;

    /// get the IOR of the material
    float GetIncidence() const;

    /// compute F0 (fresnel coeff) of the F term
    float GetF0() const;

    /// get the fresnel function being used (function pointer)
    t_Fresnel GetFresnel() const;
};

/// --------------------------------------------------------------------------- SetRoughness

inline void 
CookTorranceSpecular::SetRoughness(float roughness)
{
    m_roughness = roughness;
}

/// --------------------------------------------------------------------------- SetIncidence

inline void 
CookTorranceSpecular::SetIncidence(float incidence)
{
    m_incidence = incidence;
}

/// --------------------------------------------------------------------------- SetColor

inline void 
CookTorranceSpecular::SetColor(const Color& color)
{
    m_color = color;
}

/// --------------------------------------------------------------------------- GetRoughness

inline float 
CookTorranceSpecular::GetRoughness() const
{
    return m_roughness;
}

/// --------------------------------------------------------------------------- GetIncidence

inline float 
CookTorranceSpecular::GetIncidence() const
{
    return m_incidence;
}

/// --------------------------------------------------------------------------- GetF0

inline float 
CookTorranceSpecular::GetF0() const
{
    float a = m_incidence - 1.f;
    float b = m_incidence + 1.f;
    return (a*a) / (b*b);
}

/// --------------------------------------------------------------------------- GetFresnel

inline t_Fresnel 
CookTorranceSpecular::GetFresnel() const
{
    return m_fresnel;
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif