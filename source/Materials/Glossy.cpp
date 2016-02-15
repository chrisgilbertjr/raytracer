
#include "Materials\Glossy.h"
#include "World\World.h"

Glossy::Glossy()
    : CookTorrance()
    , m_glossy()
{
}

Glossy::Glossy(const Glossy& glossy)
    : CookTorrance(glossy)
    , m_glossy(glossy.m_glossy)
{
}

Glossy::~Glossy() {}

Glossy& 
Glossy::operator=(Glossy glossy)
{
    CookTorrance::operator=(glossy);
    Swap<GlossySpecular>(m_glossy, glossy.m_glossy);

    return *this;
}

Material* 
Glossy::Clone() const
{
    return static_cast<Material*>(new Glossy(*this));
}

Color 
Glossy::Shade(ShadeRecord& record) const
{
    return this->AreaLightShade(record);
}

Color 
Glossy::AreaLightShade(ShadeRecord& record) const
{
    Vector E;
    Vector R = -record.ray.direction;
    real pdf = 0.f;
    Ray ray(record.worldPoint, E);

    Color Radiance = CookTorrance::AreaLightShade(record);
    Color f = m_glossy.SampleF(record, E, R, pdf);

    const Raytracer* tracer = record.world->GetRaytracer();

    Radiance += f 
             *  tracer->TraceRay(record.world, ray, record.depth + 1)
             *  Dot(record.normal, E)
             /  pdf;

    return Radiance;
}

void 
Glossy::SetGlossy(const Color& color, real intensity, real exp)
{
    m_glossy.SetIntensity(intensity);
    m_glossy.SetColor(color);
    m_glossy.SetExp(exp);
}