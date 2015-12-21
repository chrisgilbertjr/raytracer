
#ifndef THIN_LENS_H
#define THIN_LENS_H

#include "Cameras\Camera.h"

class ThinLens : public Camera
{
public:
    ThinLens();

    ThinLens(const ThinLens& thinlens);

    virtual ~ThinLens();

    ThinLens& operator=(ThinLens thinlens);

    virtual Camera* Clone() const;

    virtual void Render(const World& world);
};

#endif