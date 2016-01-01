
#include "World\World.h"
#include "qdbmp.h"

/// --------------------------------------------------------------------------- ExportBMP

static void 
ExportBMP(const ColorBuffer& buffer, const OutputOptions& options)
{
    unsigned height = buffer.GetHeight();
    unsigned width = buffer.GetWidth();

    BMP* bmp = BMP_Create(width, height, 8);

    for (unsigned y = 0; y < height; ++y)
    {
        for (unsigned x = 0; x < width; ++x)
        {
            Color255 color = MapColor255(buffer.GetColor(x, y));
            BMP_SetPixelRGB(bmp, x, y, color.r, color.g, color.b);
        }
    }

    BMP_WriteFile(bmp, options.filename.c_str());

    BMP_Free(bmp);
}

/// --------------------------------------------------------------------------- Constructor

World::World()
    : m_viewingPlane()
    , m_objects(8)
    , m_tracer(NULL)
    , m_background(0.f, 0.f, 0.f)
{}

/// --------------------------------------------------------------------------- Copy Constructor

World::World(const World& world)
    : m_viewingPlane(world.m_viewingPlane)
    , m_objects(world.m_objects)
    , m_tracer(world.m_tracer)
    , m_background(world.m_background)
{}

/// --------------------------------------------------------------------------- Destructor

World::~World() {}

/// --------------------------------------------------------------------------- Copy Assignment operator

World& World::operator=(World world)
{
    Swap<ViewingPlane>(m_viewingPlane, world.m_viewingPlane);
    Swap<Array<Object*> >(m_objects, world.m_objects);
    Swap<Raytracer*>(m_tracer, world.m_tracer);
    Swap<Color>(m_background, world.m_background);

    return *this;
}

/// --------------------------------------------------------------------------- Render

void 
World::Render(const ColorBuffer& buffer) const
{
    /// @TODO:
}

/// --------------------------------------------------------------------------- Query Objects

void 
World::QueryObjects(const Ray& ray) const
{
    ShadeRecord record;

    int objectCount = m_objects.GetSize();
}

/// --------------------------------------------------------------------------- EOF