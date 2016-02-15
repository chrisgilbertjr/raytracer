
#ifndef GLOSSY_H
#define GLOSSY_H

#include "CookTorrance.h"
#include "..\BRDFs\GlossySpecular.h"

class Glossy : public CookTorrance
{
private:
    GlossySpecular m_glossy;

public:
    Glossy();

    Glossy(const Glossy& glossy);

    virtual ~Glossy();

    Glossy& operator=(Glossy glossy);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;

    virtual Color AreaLightShade(ShadeRecord& record) const;

    void SetGlossy(const Color& color, real intensity, real exp);
};

#endif