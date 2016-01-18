
#include "Materials\Matte.h"
#include "Lights\Light.h"
#include "World\World.h"

/// --------------------------------------------------------------------------- Constructor

Matte::Matte()
    : m_ambient()
    , m_diffuse()
{}

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

static float max = 0.f;

Color 
Matte::Shade(ShadeRecord& record) const
{
    /// get the normal and incoming ray direction
    Vector N = record.normal;
    Vector R = -record.ray.direction;

    /// compute the ambient radiance in the world
    Color radiance = m_ambient.P(record, R) * record.world->GetAmbientRadiance(record);

    /// get all lights in the world
    const Array<Light*>* lights = record.world->GetLights();
    const int lightCount = lights->GetSize();
    int x = 0;

    /// loop through each light and accumulate the radiance
    for (int i = 0; i < lightCount; ++i)
    {
        /// get the light direction
        Vector L = lights->operator[](i)->GetDirection(record);

        /// compute the
        float NoL = Dot(N, L);
        float NoR = Dot(N, R);

        /// if the light and ray direction are within 90 deg, the light is visible, accumulate the radiance
        if (NoL > 0.f && NoR > 0.f)
        {
            radiance += m_diffuse.F(record, L, R) * lights->operator[](i)->Radiance(record)  * NoL;
            if (radiance.r > max)
            {
                max = radiance.r;
            }
        }
    }

    return radiance;
}

/// --------------------------------------------------------------------------- EOF