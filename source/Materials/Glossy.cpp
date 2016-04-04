
#include "Materials\Glossy.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

Glossy::Glossy()
    : CookTorrance()
    , m_glossy()
{
}

/// --------------------------------------------------------------------------- copy constructor

Glossy::Glossy(const Glossy& glossy)
    : CookTorrance(glossy)
    , m_glossy(glossy.m_glossy)
{
}

/// --------------------------------------------------------------------------- destructor

Glossy::~Glossy() {}

/// --------------------------------------------------------------------------- copy assignment operator

Glossy& 
Glossy::operator=(Glossy glossy)
{
    /// copy and swap
    CookTorrance::operator=(glossy);
    Swap<GlossySpecular>(m_glossy, glossy.m_glossy);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Material* 
Glossy::Clone() const
{
    return static_cast<Material*>(new Glossy(*this));
}

/// --------------------------------------------------------------------------- Shade

Color 
Glossy::Shade(ShadeRecord& record) const
{
    return this->AreaLightShade(record);
}

/// --------------------------------------------------------------------------- AreaLightShade

Color 
Glossy::AreaLightShade(ShadeRecord& record) const
{
    Color Radiance = CookTorrance::AreaLightShade(record);

    Vector E;
    Vector R = -record.ray.direction;
    real pdf = 0.f;

    Color f = m_glossy.SampleF(record, E, R, pdf);
    Vector point = Add(record.worldPoint, record.normal * shadowEpsilon);
    Ray ray(point, E);

    const Raytracer* tracer = record.world->GetRaytracer();

    /// compute the lighting equation
    Radiance += f 
             *  tracer->TraceRay(record.world, ray, record.depth + 1)
             *  Dot(record.normal, E)
             /  pdf;

    return Radiance;
}

/// --------------------------------------------------------------------------- SetGlossy

void 
Glossy::SetGlossy(const Color& color, real intensity, real exp)
{
    m_glossy.SetIntensity(intensity);
    m_glossy.SetColor(color);
    m_glossy.SetExp(exp);
}

/// --------------------------------------------------------------------------- EOF