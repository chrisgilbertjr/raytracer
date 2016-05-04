
#include "Demos.h"

void 
Demo_Sampler(const char* output, Array<Vector>& positions, Sampler* sampler, int samples)
{
    World world(samples);
    world.SetResolution(400, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new PureColor());
    world.SetSampler(new Hammersley(64));
    world.SetCamera(new Pinhole());

    Matte* material;
    Sphere* sphere;

    for (int i = 0; i < sampler->GetSampleCount(); ++i)
    {
        material = new Matte();
        material->SetColor(Color::Red());

        sphere = new Sphere((sampler->m_samples[i]*395.f) - Vector(195.f, 195.f, 0.0f), 4.0f);
        sphere->SetMaterial(material);

        world.PushObject(sphere);
    }

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_BareBones(const char* output, int samples)
{
    World world(samples);
    world.SetResolution(800, 800);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new PureColor());
    if (samples == 1)
    {
        world.SetSampler(new Simple(samples));
    }
    else
    {
        world.SetSampler(new Hammersley(samples));
    }
    world.SetCamera(new Pinhole());

    Scene_Barebones(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_Shapes(const char* output, int samples)
{
    World world(samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new PureColor());
    if (samples == 1)
    {
        world.SetSampler(new Simple(samples));
    }
    else
    {
        world.SetSampler(new Hammersley(samples));
    }
    world.SetCamera(new Pinhole());

    Scene_Shapes(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_ShapesMatte(const char* output, int samples)
{
    World world(samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new Shaded());
    if (samples == 1)
    {
        world.SetSampler(new Simple(samples));
    }
    else
    {
        world.SetSampler(new Hammersley(samples));
    }
    world.SetCamera(new Pinhole());

    Scene_Shapes(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_SpecularSpheres(const char* output, int samples)
{
    World world(new AmbientLight(Color::White(), 1.0f), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new Shaded());
    if (samples == 1)
    {
        world.SetSampler(new Simple(samples));
    }
    else
    {
        world.SetSampler(new Hammersley(samples));
    }
    world.SetCamera(new Pinhole());

    Scene_SpecularSpheres(&world, false);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_ShadowSpheres(const char* output, int samples)
{
    World world(new AmbientLight(Color::White(), 1.0f), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new Shaded());
    if (samples == 1)
    {
        world.SetSampler(new Simple(samples));
    }
    else
    {
        world.SetSampler(new Hammersley(samples));
    }
    world.SetCamera(new Pinhole());

    Scene_SpecularSpheres(&world, true);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_TexturedShapes(const char* output, int samples)
{
    World world(new AmbientLight(Color::White(), 1.f), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new Shaded());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());

    Scene_TexturedShapes(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_OccluderShapes(const char* output, int samples)
{
    World world(new AmbientOccluder(), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new Shaded());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());

    Scene_TexturedShapes(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_AreaLightShapes(const char* output, int samples)
{
    World world(new AmbientOccluder(), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new AreaLighting());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());

    Scene_AreaLightShapes(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_AreaLightShapes2(const char* output, int samples)
{
    World world(new AmbientOccluder());
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new AreaLighting());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());

    Scene_AreaLightShapes2(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_EnvironmentLight(const char* output, int samples)
{
    World world(new AmbientOccluder(), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new AreaLighting());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());

    Scene_EnvironmentShapes(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_Reflections(const char* output, int samples)
{
    World world(new AmbientOccluder(), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new Whitted());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());
    world.SetDepth(4);

    Scene_Reflections(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_Glossy(const char* output, int samples)
{
    World world(new AmbientOccluder(), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new Whitted());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());
    world.SetDepth(2);

    Scene_Glossy(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_PathShader(const char* output, int samples)
{
    World world(new AmbientOccluder(), samples);
    world.SetResolution(800, 400);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new PathTracer());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());
    world.SetDepth(3);

    Scene_PathShader(&world);

    world.Render(Options(EXPORT_BMP, output));
}

void 
Demo_CornellBox(const char* output, int samples)
{
    World world(new AmbientOccluder(), samples);
    world.SetResolution(512, 512);
    world.SetBackground(Color::Black());
    world.SetRaytracer(new PathTracer());
    world.SetSampler(new Hammersley(samples));
    world.SetCamera(new Pinhole());
    world.SetDepth(10);

    Scene_CornellBox(&world);

    world.Render(Options(EXPORT_BMP, output));
}
