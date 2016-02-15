
#include "Materials\Reflective.h"
#include "World\World.h"

Reflective::Reflective()
    : m_reflective()
{}

Reflective::Reflective(const Reflective& material)
    : m_reflective(material.m_reflective)
{}

Reflective::~Reflective() {}

Reflective& 
Reflective::operator=(Reflective material)
{
    CookTorrance::operator=(material);
    Swap<PerfectSpecular>(m_reflective, material.m_reflective);

    return *this;
}

Material* 
Reflective::Clone() const
{
    return static_cast<Material*>(new Reflective(*this));
}

static void 
PrintVector(const Vector& v, const char* msg)
{
    fprintf(stdout, "%s x:%.5f, y:%.5f z:%.5f\n", msg, v.x, v.y, v.z);
}

Color 
Reflective::Shade(ShadeRecord& record) const
{
    Color Radiance = CookTorrance::Shade(record);

    Vector wi;
    Vector wo = -record.ray.direction;
    Color fr = m_reflective.SampleF(record, wi, wo);
    Vector point = Add(record.worldPoint, record.normal * shadowEpsilon);
    Ray reflected(point, wi);
    const Raytracer* tracer = record.world->GetRaytracer();

    Color reflection = tracer->TraceRay(record.world, reflected, record.depth + 1);

    Radiance += fr * reflection * Dot(record.normal, wi);

    return Radiance;
}

Color
Reflective::AreaLightShade(ShadeRecord& record) const
{
    Color Radiance = CookTorrance::AreaLightShade(record);

    Vector wi;
    Vector wo = -record.ray.direction;
    Color fr = m_reflective.SampleF(record, wi, wo);
    Vector point = Add(record.worldPoint, record.normal * shadowEpsilon);
    Ray reflected(point, wi);
    const Raytracer* tracer = record.world->GetRaytracer();

    Color reflection = tracer->TraceRay(record.world, reflected, record.depth + 1);

    Radiance += fr * reflection * Dot(record.normal, wi);

    return Radiance;
}

Color 
Reflective::PathShade(ShadeRecord& record) const
{
    float pdf;
    Vector R;
    Vector E = -record.ray.direction;

    Color f = m_reflective.SampleF(record, R, E, pdf);
    Ray reflected = Ray(record.worldPoint, R);

    const Raytracer* tracer = record.world->GetRaytracer();

    return f * tracer->TraceRay(record.world, reflected, record.depth + 1) * Dot(record.normal, R) / pdf;
}