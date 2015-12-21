
#ifndef PHONG_H
#define PHONG_H

#include "Material.h"

class Phong : public Material
{
private:

public:
    Phong();

    Phong(const Phong& phong);

    virtual ~Phong();

    Phong& operator=(Phong phong);

    virtual Material* Clone() const;
};
#endif