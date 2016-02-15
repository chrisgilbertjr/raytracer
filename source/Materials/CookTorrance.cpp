
#include "Materials\CookTorrance.h"
#include "Lights\Light.h"
#include "World\World.h"

CookTorrance::CookTorrance()
    : m_ambient()
    , m_diffuse()
    , m_specular()
{}

CookTorrance::CookTorrance(const CookTorrance& ct)
    : Material(ct)
    , m_ambient(ct.m_ambient)
    , m_diffuse(ct.m_diffuse)
    , m_specular(ct.m_specular)
{}

CookTorrance::~CookTorrance() {}

CookTorrance& 
CookTorrance::operator=(CookTorrance ct)
{
    Material::operator=(ct);
    Swap<Lambertian>(m_ambient, ct.m_ambient);
    Swap<Lambertian>(m_diffuse, ct.m_diffuse);
    Swap<CookTorranceSpecular>(m_specular, ct.m_specular);

    return *this;
}

Material* 
CookTorrance::Clone() const
{
    return static_cast<Material*>(new CookTorrance(*this));
}

Color CookTorrance::Shade(ShadeRecord& record) const
{
    /// get the normal and incoming ray direction
    Vector N = record.normal;
    Vector E = -record.ray.direction;

    /// compute the ambient radiance in the world
    Color radiance = m_ambient.P(record, E) * record.world->GetAmbientRadiance(record);

    /// get all lights in the world
    const Array<Light*>* lights = record.world->GetLights();
    const int lightCount = lights->GetSize();

    t_Fresnel fresnel = m_specular.GetFresnal();

    /// loop through each light and accumulate the radiance
    for (int i = 0; i < lightCount; ++i)
    {
        Light* light = lights->operator[](i);

        /// get the light direction
        Vector L = light->GetDirection(record);
        Vector H = Normalize(Add(L, E));

        /// get cos of the light and eye vector
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
                float diffuseIntensity  = 1.f - fresnel(L, N, m_specular.GetIncidence());

                radiance += (m_diffuse.F(record, L, E) * diffuseIntensity
                         +   m_specular.F(record, L, E)) 
                         *   light->Radiance(record) 
                         *   NoL;
            }
        }
    }

    return radiance;
}

Color 
CookTorrance::AreaLightShade(ShadeRecord& record) const
{
    /// get the normal and incoming ray direction
    Vector N = record.normal;
    Vector E = -record.ray.direction;

    /// compute the ambient radiance in the world
    Color radiance = m_ambient.P(record, E) * record.world->GetAmbientRadiance(record);

    /// get all lights in the world
    const Array<Light*>* lights = record.world->GetLights();
    const int lightCount = lights->GetSize();

    t_Fresnel fresnel = m_specular.GetFresnal();

    /// loop through each light and accumulate the radiance
    for (int i = 0; i < lightCount; ++i)
    {
        Light* light = lights->operator[](i);

        /// get the light direction
        Vector L = light->GetDirection(record);
        Vector H = Normalize(Add(L, E));

        /// get cos of the light and eye vector
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
                float diffuseIntensity  = 1.f - fresnel(L, N, m_specular.GetIncidence());

                radiance += (m_diffuse.F(record, L, E) * diffuseIntensity
                         +   m_specular.F(record, L, E)) 
                         *   light->Radiance(record) 
                         *   light->G(record)
                         *   NoL
                         /   light->pdf(record);
            }
        }
    }

    return radiance;
}