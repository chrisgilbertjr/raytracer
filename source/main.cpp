
#include "World\World.h"
#include "Cameras\Pinhole.h"
#include "Samplers\Simple.h"
#include "Raytracers\PureColor.h"
#include "Samplers\PureRandom.h"
#include "Samplers\Hammersley.h"
#include "Objects\Sphere.h"

int 
main(void)
{
    Material material;
    material.SetColor(Color::Red());

    Sphere* sphere = new Sphere(Vector(0.0f, 0.0f, 0.f),  25.f);
    sphere->SetMaterial(&material);

    World world;
    world.PushObject(sphere);

    world.SetCamera(new Pinhole());
    //world.SetSampler(new Simple(1));
    world.SetSampler(new Hammersley(64));
    world.SetRaytracer(new PureColor());
    world.SetBackground(Color::Black());

    world.Render(Options(EXPORT_BMP, "world.bmp"));

    fprintf(stdout, "complete!");

    while (1) {}

    return 0;
}