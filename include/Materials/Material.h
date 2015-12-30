
#ifndef MATERIAL_H
#define MATERIAL_H

#include "..\Core\Color.h"

class Material
{
protected:

public:
    Material();

    Material(const Material& material);

    virtual ~Material();

    Material& operator=(Material material);

    virtual Material* Clone() const;
};

#endif