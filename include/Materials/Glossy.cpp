
#include "Glossy.h"

    Glossy();

    Glossy(const Glossy& glossy);

    virtual ~Glossy();

    Glossy& operator=(Glossy glossy);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;

    virtual Color AreaLightShade(ShadeRecord& record) const;

    void SetGlossy(const Color& color, real intensity);