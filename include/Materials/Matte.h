
#ifndef MATTE_H
#define MATTE_H

#include "Material.h"

class Matte : public Material
{
private:

public:
    Matte();

    Matte(const Matte& matte);

    virtual ~Matte();

    Material& operator=(Matte matte);

    virtual Material* Clone() const;
};

#endif