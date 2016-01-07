
#ifndef ORTHO_H
#define ORTHO_H

#include "Cameras\Camera.h"

class Ortho : public Camera
{
private:

public:
    Ortho();

    Ortho(const Ortho& ortho);

    virtual ~Ortho();

    Ortho& operator=(Ortho ortho);

    virtual Camera* Clone() const;

    virtual void Render(const World* world, const OutputOptions& output);
};

#endif