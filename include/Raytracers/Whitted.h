
#ifndef WHITTED_H
#define WHITTED_H

#include "Raytracer.h"

class Whitted : public Raytracer
{
private:

public:
    Whitted();

    Whitted(const Whitted& whitted);

    virtual ~Whitted();

    Whitted& operator=(Whitted whitted);

    virtual Raytracer* Clone() const;
};

#endif