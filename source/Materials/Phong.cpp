
#include "Materials\Phong.h"
#include "Lights\Light.h"
#include "World\World.h"

Phong::Phong()
    : m_ambient()
    , m_diffuse()
    , m_specular()
{}

Phong::Phong(const Phong& phong)
    : m_ambient(phong.m_ambient)
    , m_diffuse(phong.m_diffuse)
    , m_specular(phong.m_specular)
{}

Phong::~Phong() {}

Phong& 
Phong::operator=(Phong phong)
{
    Material::operator=(phong);
    Swap<Lambertian>(m_ambient, phong.m_ambient);
    Swap<Lambertian>(m_diffuse, phong.m_diffuse);
    Swap<GlossySpecular>(m_specular, phong.m_specular);

    return *this;
}

Material* 
Phong::Clone() const
{
    return static_cast<Material*>(new Phong(*this));
}

Color 
Phong::Shade(ShadeRecord& record) const
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
                radiance += (m_diffuse.F(record, L, E)
                         +   m_specular.F(record, L, E)) 
                         *   light->Radiance(record)
                         *   NoL;
            }
        }
    }

    return radiance;
}