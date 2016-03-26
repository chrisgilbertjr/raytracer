
#ifndef MATERIAL_H
#define MATERIAL_H

#include "..\Core\Color.h"

/// @defgroup Material Material
/// @{

/// forward declaration
struct ShadeRecord;

/// base class for all materials
class Material
{
protected:
    Color m_color; /// base color for materials

public:
    /// constructor
    Material();

    /// copy constructor
    Material(const Material& material);

    /// destructor
    virtual ~Material();

    /// copy assignment operator
    Material& operator=(Material material);

    /// deep copy of the object
    virtual Material* Clone() const;

    /// compute the color given a shade record
    virtual Color Shade(ShadeRecord& record) const;

    /// compute the color given a shade record for area lighting
    virtual Color AreaLightShade(ShadeRecord& record) const;

    /// compute the color given a shade record for path tracing
    virtual Color PathShade(ShadeRecord& record) const;
    
    /// get the emmisive color of the material
    virtual Color GetEmmisive() const;

    /// get the materials base color
    Color GetColor() const;

    /// set the materials base color
    void SetColor(const Color& color);
};

/// --------------------------------------------------------------------------- GetColor

inline Color 
Material::GetColor() const            
{ 
    return m_color; 
}

/// --------------------------------------------------------------------------- SetColor

inline void 
Material::SetColor(const Color& color) 
{ 
    m_color = color; 
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif