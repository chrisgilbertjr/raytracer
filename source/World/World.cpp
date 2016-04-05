
#include "Samplers\PureRandom.h"
#include "Lights\AmbientLight.h"
#include "World\World.h"
#include "BRDFs\BRDF.h"
#include "qdbmp.h"

/// --------------------------------------------------------------------------- ExportBMP

void 
ExportBMP(const ColorBuffer& buffer, const char* filename)
{
    unsigned height = buffer.GetHeight();
    unsigned width = buffer.GetWidth();

    /// create the BMP image
    BMP* bmp = BMP_Create(width, height, 32);

    /// loop through the color buffer and write each pixel
    for (unsigned y = 0; y < height; ++y)
    {
        for (unsigned x = 0; x < width; ++x)
        {
            Color255 color = MapColor255(buffer.GetColor(x, (height-y-1)));
            BMP_SetPixelRGB(bmp, x, y, color.r, color.g, color.b);
        }
    }

    /// write the bitmap
    BMP_WriteFile(bmp, filename);

    /// free all data used by the bitmap
    BMP_Free(bmp);
}

/// --------------------------------------------------------------------------- constructor

World::World(int samples)
    : m_viewingPlane(samples)
    , m_objects(8)
    , m_lights(8)
    , m_ambient(new AmbientOccluder())
    , m_tracer(NULL)
    , m_camera(NULL)
    , m_background(0.f, 0.f, 0.f)
{
    g_samples = samples;
    g_pathSampler = new PureRandom(1);
    g_pathSampler->MapSamplesToHemisphere();
}

/// --------------------------------------------------------------------------- constructor

World::World(Light* ambient, int samples)
    : m_viewingPlane(samples)
    , m_objects(8)
    , m_lights(8)
    , m_ambient(ambient)
    , m_tracer(NULL)
    , m_camera(NULL)
    , m_background(0.f, 0.f, 0.f)
{
    g_samples = samples;
    g_pathSampler = new PureRandom(samples);
    g_pathSampler->MapSamplesToHemisphere();
}

/// --------------------------------------------------------------------------- copy Constructor

World::World(const World& world)
{
    /// world objects should not be copied
    Assert(false);
}

/// --------------------------------------------------------------------------- destructor

World::~World() { this->Free(); }

/// --------------------------------------------------------------------------- copy Assignment operator

World& 
World::operator=(World world)
{
    /// world objects should not be copied
    Assert(false);
    return *this;
}

/// --------------------------------------------------------------------------- Render

void 
World::Render(const OutputOptions& options) const
{
    if (m_camera)
    {
        m_camera->RenderThreads(this, options);
    }
}

/// --------------------------------------------------------------------------- Export

void
World::Export(const ColorBuffer& buffer, const OutputOptions& options) const
{
    if (options.output == EXPORT_BMP)
    {
        ExportBMP(buffer, options.filename.c_str());
    }
}

/// --------------------------------------------------------------------------- QueryObjects

ShadeRecord 
World::QueryObjects(const Ray& ray) const
{
    ShadeRecord record = ShadeRecordConstruct(this, ray);
    ShadeRecord result = ShadeRecordConstruct(this, ray);

    float tmin = 1e5;
    int count = m_objects.GetSize();

    for (int i = 0; i < count; ++i)
    {
        Object* object = m_objects[i];

        /// do the raycast
        Raycast raycast = object->Query(ray, record);
        Matrix m_transform = object->GetTransform();

        /// check if this is the earliest raycast collision
        if (raycast.hit && raycast.t < tmin)
        {
            /// its the earliest collision so far, init the result
            tmin = raycast.t;

            /// copy the shade record to the result record
            result = ShadeRecordCopy(record);
            result.worldPoint = ray.origin + tmin * ray.direction;
            result.material = object->GetMaterial();
            result.hit = true;
        }
    }

    /// return the result
    return result;
}

/// --------------------------------------------------------------------------- Free

void 
World::Free()
{
    /// release all resources

    if (m_ambient)
    {
        delete m_ambient;
    }

    if (m_camera)
    {
        delete m_camera;
    }

    if (m_tracer)
    {
        delete m_tracer;
    }

    for (int i = 0; i < (int)m_objects.GetSize(); ++i)
    {
        delete m_objects[i];
    }

    for (int i = 0; i < (int)m_lights.GetSize(); ++i)
    {
        delete m_lights[i];
    }
}

/// --------------------------------------------------------------------------- EOF