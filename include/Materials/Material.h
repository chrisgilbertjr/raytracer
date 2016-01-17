
#ifndef MATERIAL_H
#define MATERIAL_H

#include "..\Core\Color.h"

struct ShadeRecord;

class Material
{
protected:
    Color m_color;

public:
    Material();

    Material(const Material& material);

    virtual ~Material();

    Material& operator=(Material material);

    virtual Material* Clone() const;

    virtual Color Shade(ShadeRecord& record) const;

    inline Color GetColor() const            { return m_color; }

    inline void SetColor(const Color& color) { m_color = color; }
};

#endif