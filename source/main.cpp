
#include "World\World.h"
#include "Cameras\Pinhole.h"
#include "Samplers\Simple.h"
#include "Raytracers\PureColor.h"
#include "Raytracers\Shaded.h"
#include "Samplers\PureRandom.h"
#include "Samplers\Hammersley.h"
#include "Objects\Sphere.h"
#include "Objects\Cylinder.h"
#include "Objects\Plane.h"
#include "Materials\Matte.h"
#include "Materials\Phong.h"
#include "Materials\CookTorrance.h"
#include "Lights\DirectionalLight.h"
#include "Lights\PointLight.h"

int 
main(void)
{
    Phong* material = new Phong();
    material->SetDiffuse(Color::Blue(), 1.0f);
    material->SetSpecular(Color::White(), 6.0f, 0.5f);

    CookTorrance* material1 = new CookTorrance();
    material1->SetDiffuse(Color::Red());
    material1->SetRoughness(0.3f);
    material1->SetIncidence(0.018f);

    Matte* material2 = new Matte();
    material2->SetDiffuse(Color::White());

    DirectionalLight* light = new DirectionalLight(Normalize(Vector(0.f, -1.f, 0.f)), Color::White(), 0.5f);
    PointLight* point = new PointLight(Vector(0.0f, 0.f, 200.0f), Color::White(), 5000.f, 1.f);

    Sphere* sphere =  new Sphere(Vector(  0.0f, 0.0f, 0.f),  50.f);
    sphere->SetMaterial(material1);

    Sphere* sphere1 = new Sphere(Vector(-200.0f, -50.0f, 0.f),  50.f);
    sphere1->SetMaterial(material);

    Sphere* sphere2 = new Sphere(Vector( 200.0f, 0.0f, 0.f),  50.0f);
    sphere2->SetMaterial(material);

    Plane* plane = new Plane(Vector(0.f, -100.f, 0.f), Vector(0.f, 1.0f, 0.0f));
    plane->SetMaterial(material2);

    Plane* plane2 = new Plane(Vector(-250.f, 0.f, 0.f), Vector(1.f, 0.0f, 0.0f));
    plane2->SetMaterial(material2);

    World world;
    world.PushObject(sphere);
    world.PushObject(sphere1);
    world.PushObject(sphere2);
    world.PushObject(plane);
    //world.PushObject(plane2);
    world.PushLight(light);
    world.PushLight(point);

    world.SetCamera(new Pinhole());
    world.SetSampler(new Hammersley(8));
    world.SetRaytracer(new Shaded());
    world.SetBackground(Color::Black());

    world.Render(Options(EXPORT_BMP, "world.bmp"));

    fprintf(stdout, "complete!");

    while (1) {}

    return 0;
}