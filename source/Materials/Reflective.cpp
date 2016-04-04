
#include "Materials\Reflective.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- constructor

Reflective::Reflective()
    : CookTorrance()
    , m_reflective()
{}

/// --------------------------------------------------------------------------- copy constructor

Reflective::Reflective(const Reflective& material)
    : CookTorrance()
    , m_reflective(material.m_reflective)
{}

/// --------------------------------------------------------------------------- destructor

Reflective::~Reflective() {}
 
/// --------------------------------------------------------------------------- copy assignment operator

Reflective& 
Reflective::operator=(Reflective material)
{
    CookTorrance::operator=(material);
    Swap<PerfectSpecular>(m_reflective, material.m_reflective);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Material* 
Reflective::Clone() const
{
    return static_cast<Material*>(new Reflective(*this));
}

/// --------------------------------------------------------------------------- Shade

Color 
Reflective::Shade(ShadeRecord& record) const
{
    Color Radiance = CookTorrance::Shade(record);

    Vector wi;
    Vector wo = -record.ray.direction;

    /// sample reflections
    Color fr = m_reflective.SampleF(record, wi, wo);
    Vector point = Add(record.worldPoint, record.normal * shadowEpsilon);
    Ray reflected(point, wi);

    const Raytracer* tracer = record.world->GetRaytracer();

    Color reflection = tracer->TraceRay(record.world, reflected, record.depth + 1);

    /// compute the lighting equation
    Radiance += fr * reflection * Dot(record.normal, wi);

    return Radiance;
}

/// --------------------------------------------------------------------------- AreaLightShade

Color
Reflective::AreaLightShade(ShadeRecord& record) const
{
    Color Radiance = CookTorrance::AreaLightShade(record);

    Vector wi;
    Vector wo = -record.ray.direction;

    /// sample reflections
    Color fr = m_reflective.SampleF(record, wi, wo);
    Vector point = Add(record.worldPoint, record.normal * shadowEpsilon);
    Ray reflected(point, wi);
    const Raytracer* tracer = record.world->GetRaytracer();

    Color reflection = tracer->TraceRay(record.world, reflected, record.depth + 1);

    /// compute the lighting equation
    Radiance += fr * reflection * Dot(record.normal, wi);

    return Radiance;
}

/// --------------------------------------------------------------------------- PathShade

Color 
Reflective::PathShade(ShadeRecord& record) const
{
    float pdf;
    Vector R;
    Vector E = -record.ray.direction;

    /// sample reflections
    Color f = m_reflective.SampleF(record, R, E, pdf);
    Ray reflected = Ray(record.worldPoint, R);

    const Raytracer* tracer = record.world->GetRaytracer();

    /// compute the lighting equation
    return f * tracer->TraceRay(record.world, reflected, record.depth + 1) * Dot(record.normal, R) / pdf;
}

/// --------------------------------------------------------------------------- EOF