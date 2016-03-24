
#include "Cameras\Pinhole.h"
#include "Samplers\sampler.h"
#include "World\World.h"


Pinhole::Pinhole()
    : Camera()
    , m_distance(500.f)
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
Pinhole::Render(const World* world, const OutputOptions& options)
{
    /// get the needed vars
    const Raytracer* tracer = world->GetRaytracer();
    Color background = world->GetBackground();
    ViewingPlane plane = world->GetViewingPlane();
    Sampler* sampler = plane.GetSampler();
    real size = plane.GetPizelSize() / m_zoom;
    int samples = plane.GetSampleCount();
    int height = plane.GetHeight();
    int width = plane.GetWidth();

    Vector sample; /// the initialize sample point from the sampler
    Vector point;  /// the sampled point on the pixel
    Color pixel;   /// the color of the pixel
    Ray ray;       /// the ray being traced
    ray.origin = m_eye;

    /// create the color buffer used for the output image
    ColorBuffer buffer(width, height, background);

    real pixels = (real)(height * width);
    real count = 0.f;
    real display = 0.01f;

    /// loop over each pixel
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
                    pixel += tracer->TraceRay(world, ray, 0);
            }

            /// average the pixel over the number of samples and the cameras exposure time
            pixel /= (real)samples;
            pixel *= m_exposure;

            /// set the color of the color buffer
            buffer.SetColor(x, y, plane.RemapColor(pixel));
            count += 1.f;

            if (((real)count / (real)pixels) > display)
            {
                printf("%.1f\n", display * 100.f);
                display += 0.01f;
            }

        }
    }

    /// export the color buffer according to the output options
    world->Export(buffer, options);
    printf("Export successful!\n\n\n");
}