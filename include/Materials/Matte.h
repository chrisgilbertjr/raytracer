
#ifndef MATTE_H
#define MATTE_H

#include "Material.h"
#include "..\BRDFs\Lambertian.h"

class Matte : public Material
{
private:
    Lambertian m_ambient;
    Lambertian m_diffuse;

public:
    Matte();

    Matte(const Matte& matte);

    virtual ~Matte();

    Material& operator=(Matte matte);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;
};

#endif