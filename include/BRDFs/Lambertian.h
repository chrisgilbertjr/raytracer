
#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "BRDF.h"

class Lambertian : public BRDF
{
private:

public:
    Lambertian();

    ~Lambertian();
};

#endif