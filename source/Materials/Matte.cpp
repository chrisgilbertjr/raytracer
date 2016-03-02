
#include "Materials\Matte.h"
#include "Lights\Light.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- Constructor

Matte::Matte()
    : m_ambient()
    , m_diffuse()
{}

/// --------------------------------------------------------------------------- Constructor

Matte::Matte(Texture* texture)
    : Material()
    , m_ambient(texture)
    , m_diffuse(texture)
{
}

/// --------------------------------------------------------------------------- Copy constructor

Matte::Matte(const Matte& matte)
    : m_ambient(matte.m_ambient)
    , m_diffuse(matte.m_diffuse)
{}

/// --------------------------------------------------------------------------- Destructor

Matte::~Matte() {}

/// --------------------------------------------------------------------------- Copy assignment operator

Material& 
Matte::operator=(Matte matte)
{
    Material::operator=(matte);
    Swap<Lambertian>(m_ambient, matte.m_ambient);
    Swap<Lambertian>(m_diffuse, matte.m_diffuse);

    return *this;
}

/// --------------------------------------------------------------------------- Clone

Material* 
Matte::Clone() const
{
    return static_cast<Material*>(new Matte(*this));
}

/// --------------------------------------------------------------------------- Shade

Color 
Matte::Shade(ShadeRecord& record) const
{
    /// get the normal and incoming ray direction
    Vector N = record.normal;
    Vector E = -record.ray.direction;

    /// compute the ambient radiance in the world
    Color radiance = m_ambient.P(record, E) * record.world->GetAmbientRadiance(record);

    /// get all lights in the world
    const Array<Light*>* lights = record.world->GetLights();
    const int lightCount = lights->GetSize();

    /// loop through each light and accumulate the radiance
    for (int i = 0; i < lightCount; ++i)
    {
        Light* light = lights->operator[](i);

        /// get the light direction
        Vector L = light->GetDirection(record);

        /// compute the
        float NoL = Dot(N, L);
        float NoE = Dot(N, E);

        /// if the light and ray direction are within 90 deg, the light is visible, accumulate the radiance
        if (NoL > 0.f && NoE > 0.f)
        {
            bool inShadow = false;

            if (light->CastsShadow())
            {
                inShadow = light->InShadow(Ray(record.worldPoint, L), record);
            }

            if (!inShadow)
            {
                radiance += m_diffuse.F(record, L, E)
                         *  light->Radiance(record)
                         *  NoL;
            }
        }
    }

    return radiance;
}

/// --------------------------------------------------------------------------- AreaLightShade

Color 
Matte::AreaLightShade(ShadeRecord& record) const
{
    /// get the normal and incoming ray direction
    Vector N = record.normal;
    Vector E = -record.ray.direction;

    /// compute the ambient radiance in the world
    Color radiance = m_ambient.P(record, E) * record.world->GetAmbientRadiance(record);

    /// get all lights in the world
    const Array<Light*>* lights = record.world->GetLights();
    const int lightCount = lights->GetSize();

    /// loop through each light and accumulate the radiance
    for (int i = 0; i < lightCount; ++i)
    {
        Light* light = lights->operator[](i);

        /// get the light direction
        Vector L = light->GetDirection(record);

        /// compute the
        float NoL = Dot(N, L);
        float NoE = Dot(N, E);

        /// if the light and ray direction are within 90 deg, the light is visible, accumulate the radiance
        if (NoL > 0.f && NoE > 0.f)
        {
            bool inShadow = false;

            if (light->CastsShadow())
            {
                inShadow = light->InShadow(Ray(record.worldPoint, L), record);
            }

            if (!inShadow)
            {
                radiance += m_diffuse.F(record, L, E)
                         *  light->Radiance(record)
                         *  light->G(record)
                         *  NoL
                         /  light->pdf(record);
            }
        }
    }

    return radiance;
}

/// --------------------------------------------------------------------------- PathShade


Color 
Matte::PathShade(ShadeRecord& record) const
{
    float pdf;
    Vector R;
    Vector E = -record.ray.direction;

    Color f = m_diffuse.SampleF(record, R, E, pdf);
    float NoR = Dot(record.normal, R);

    Ray reflected = Ray(record.worldPoint, R);
    const Raytracer* tracer = record.world->GetRaytracer();

    return f * tracer->TraceRay(record.world, reflected, record.depth + 1) * NoR / pdf;
}

/// --------------------------------------------------------------------------- EOF