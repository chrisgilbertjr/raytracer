
#include "Lights\AmbientOccluder.h"
#include "Samplers\Hammersley.h"
#include "Samplers\PureRandom.h"
#include "Samplers\MultiJittered.h"
#include "BRDFs\ShadeRecord.h"
#include "World\World.h"

// ---------------------------------------------------------------------------- Constructor

AmbientOccluder::AmbientOccluder()
    : m_sampler(new PureRandom(256))
    , m_minAmount(Color::Black())
    , m_color(Color::White())
    , m_u(Vector::Y())
    , m_v(Vector::X())
    , m_w(Vector::Z())
    , m_intensity(1.0f)
{
    m_sampler->MapSamplesToHemisphere();
}

// ---------------------------------------------------------------------------- Copy constructor

AmbientOccluder::AmbientOccluder(const AmbientOccluder& occluder)
    : m_sampler(occluder.m_sampler ? occluder.m_sampler->Clone() : NULL)
    , m_minAmount(occluder.m_minAmount)
    , m_color(occluder.m_color)
    , m_u(occluder.m_u)
    , m_v(occluder.m_v)
    , m_w(occluder.m_w)
    , m_intensity(occluder.m_intensity)
{
}

// ---------------------------------------------------------------------------- Destructor

AmbientOccluder::~AmbientOccluder()
{
    if (m_sampler)
    {
        delete m_sampler;
    }
}

// ---------------------------------------------------------------------------- Copy assignment operator

AmbientOccluder& 
AmbientOccluder::operator=(AmbientOccluder occluder)
{
    Light::operator=(occluder);
    Swap<Sampler*>(m_sampler, occluder.m_sampler);
    Swap<Color>(m_minAmount, occluder.m_minAmount);
    Swap<Color>(m_color, occluder.m_color);
    Swap<Vector>(m_u, occluder.m_u);
    Swap<Vector>(m_v, occluder.m_v);
    Swap<Vector>(m_w, occluder.m_w);
    Swap<real>(m_intensity, occluder.m_intensity);

    return *this;
}

// ---------------------------------------------------------------------------- SetSampler

void 
AmbientOccluder::SetSampler(Sampler* sampler)
{
    if (m_sampler)
    {
        delete m_sampler;
    }

    m_sampler = sampler;
    m_sampler->MapSamplesToHemisphere();
}

// ---------------------------------------------------------------------------- Clone

Light* 
AmbientOccluder::Clone() const
{
    return static_cast<Light*>(new AmbientOccluder(*this));
}

// ---------------------------------------------------------------------------- GetDirection

Vector 
AmbientOccluder::GetDirection(ShadeRecord& record)
{
    Vector point = m_sampler->SampleHemisphere();
    return point.x*m_u + point.y*m_v + point.z*m_w;
}

// ---------------------------------------------------------------------------- Radiance

Color 
AmbientOccluder::Radiance(ShadeRecord& record)
{
    m_w = record.normal;
    m_v = Normalize(Cross(m_w, Vector(0.0072f, 1.f, 0.0034f)));
    m_u = Cross(m_w, m_v);

    Ray shadowRay = Ray(record.worldPoint, this->GetDirection(record));

    if (this->InShadow(shadowRay, record))
    {
        return m_minAmount * m_color * m_intensity;
    }
    else
    {
        return m_color * m_intensity;
    }
}

// ---------------------------------------------------------------------------- CastsShadow

bool 
AmbientOccluder::CastsShadow() const
{
    return true;
}

// ---------------------------------------------------------------------------- InShadow

bool 
AmbientOccluder::InShadow(const Ray& ray, ShadeRecord& record) const
{
    float t;
    const Array<Object*>* objects = record.world->GetObjects();
    int objectCount = objects->GetSize();

    for (int i = 0; i < objectCount; ++i)
    {
        Object* object = objects->operator[](i);

        if (object->ShadowHit(ray, t))
        {
            return true;
        }
    }
    return false;
}

// ---------------------------------------------------------------------------- EOF