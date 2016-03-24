
#ifndef EMMISIVE_H
#define EMMISIVE_H

#include "Material.h"

/// @defgroup Emmisive Emmisive
/// @{

class Emmisive : public Material
{
private:
    Color m_color;    /// the color of the emmisive material
    real m_intensity; /// the intensity of the emmisive material

public:
    /// constructor
    Emmisive();

    /// copy constructor
    Emmisive(const Emmisive& emmisive);

    /// destructor
    virtual ~Emmisive();

    /// copy assignment operator
    Emmisive& operator=(Emmisive emmisive);

    /// deep copy of the object
    virtual Material* Clone() const;

    /// compute the color given a shade record
    virtual Color Shade(ShadeRecord& record) const;

    /// compute the color given a shade record for area lights
    virtual Color AreaLightShade(ShadeRecord& record) const;

    /// compute the color given a shade record for path shading
    virtual Color PathShade(ShadeRecord& record) const;

    /// get the emmisive materials color
    virtual Color GetEmmisive() const;

    /// set the emmisive materials properties
    void SetEmmisive(const Color& color, const real intensity = 1.0f);
};

/// --------------------------------------------------------------------------- SetEmmisive

inline void 
Emmisive::SetEmmisive(const Color& color, const real intensity)
{
    m_color = color;
    m_intensity = intensity;
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif