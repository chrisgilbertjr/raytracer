
#include "World\World.h"
#include "Cameras\Pinhole.h"
#include "Samplers\Simple.h"
#include "Raytracers\PureColor.h"
#include "Raytracers\Shaded.h"
#include "Samplers\PureRandom.h"
#include "Samplers\Hammersley.h"
#include "Objects\Sphere.h"
#include "Materials\Matte.h"
#include "Lights\DirectionalLight.h"

int 
main(void)
{
    Matte* material = new Matte();
    material->SetDiffuse(Color::Red());

    Matte* material1 = new Matte();
    material1->SetDiffuse(Color::Green());

    Matte* material2 = new Matte();
    material2->SetDiffuse(Color::Blue());

    DirectionalLight* light = new DirectionalLight(Normalize(Vector(0.f, 0.f, 1.f)), Color::White(), 1.0f);

    Sphere* sphere =  new Sphere(Vector(  0.0f, 0.0f, 0.f),  50.f);
    sphere->SetMaterial(material);

    Sphere* sphere1 = new Sphere(Vector(-200.0f, 0.0f, 0.f),  50.f);
    sphere1->SetMaterial(material1);

    Sphere* sphere2 = new Sphere(Vector( 250.0f, 0.0f, 0.f),  50.f);
    sphere2->SetMaterial(material2);

    World world;
    world.PushObject(sphere);
    world.PushObject(sphere1);
    world.PushObject(sphere2);
    world.PushLight(light);

    world.SetCamera(new Pinhole());
    world.SetSampler(new Hammersley(8));
    world.SetRaytracer(new Shaded());
    world.SetBackground(Color::Black());

    world.Render(Options(EXPORT_BMP, "world.bmp"));

    fprintf(stdout, "complete!");

    while (1) {}

    return 0;
}