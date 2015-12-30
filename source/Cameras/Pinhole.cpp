
#include "Cameras\Pinhole.h"
#include "Samplers\sampler.h"


Pinhole::Pinhole()
    : Camera()
    , m_distance(100.f)
    , m_zoom(1.f)
{}


Pinhole::Pinhole(const Pinhole& pinhole)
    : Camera(pinhole)
    , m_distance(pinhole.m_distance)
    , m_zoom(pinhole.m_zoom)
{}


Pinhole::~Pinhole() {} 


Pinhole&
Pinhole::operator=(Pinhole pinhole)
{
    Camera::operator=(pinhole);

    Swap<real>(m_distance, pinhole.m_distance);
    Swap<real>(m_zoom, pinhole.m_zoom);

    return *this;
}


Camera*
Pinhole::Clone() const
{
    return static_cast<Camera*>(new Pinhole(*this));
}


Vector 
Pinhole::ComputeRayDirection(const Vector& point) const
{
    /// direction = p.x*u  +  p.y*v  + dist*w
    return Normalize(m_u*point.x + m_v*point.y - m_w*m_distance);
}


void
Pinhole::Render(const World& world)
{
    const Raytracer* tracer = world.GetRaytracer();
    Color background = world.GetBackground();
    ViewingPlane plane = world.GetViewingPlane();
    Sampler* sampler = plane.GetSampler();
    real size = plane.GetPizelSize() / m_zoom;
    int samples = plane.GetSampleCount();
    int height = plane.GetHeight();
    int width = plane.GetWidth();

    Vector direction;
    Vector sample;
    Vector point;
    Color pixel;
    Ray ray;
    ray.origin = m_eye;

    ColorBuffer buffer(width, height, background);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            /// set the pixel as the background color
            pixel = background;
            for (int s = 0; s < samples; ++s)
            {
                    /// sample point
                    sample = sampler->SampleUnitSquare();

                    /// get the pixel point to shoot the ray
                    point.x = size * (x - 0.5f * width  + sample.x);
                    point.y = size * (y - 0.5f * height + sample.y);

                    /// get the ray direction
                    ray.direction = this->ComputeRayDirection(point);

                    /// trace the ray and accumulate the pixel color
                    pixel += tracer->TraceRay(ray, 0);
            }

            /// average the pixel over the number of samples and the cameras exposure time
            pixel /= samples;
            pixel *= m_exposure;

            /// set the color of the color buffer
            buffer.SetColor(x, y, pixel);
        }
    }

    /// output the buffer according to the worlds output options
    world.Render(buffer);
}