
#ifndef GLOSSY_H
#define GLOSSY_H

#include "CookTorrance.h"
#include "..\BRDFs\GlossySpecular.h"

/// @defgroup Glossy Glossy
/// @{

/// glossy specular material
class Glossy : public CookTorrance
{
private:
    GlossySpecular m_glossy; /// glossy specular brdf

public:
    /// constructor
    Glossy();

    /// copy constructor
    Glossy(const Glossy& glossy);

    /// destructor
    virtual ~Glossy();

    /// copy assignment operator
    Glossy& operator=(Glossy glossy);

    /// deep copy of the object
    virtual Material* Clone() const;

    /// compute the color given a shade record
    virtual Color Shade(ShadeRecord& record) const;

    /// compute the color given a shade record for area lights
    virtual Color AreaLightShade(ShadeRecord& record) const;

    /// set the glossy materials properties
    void SetGlossy(const Color& color, real intensity, real exp);
};

/// @}

#endif