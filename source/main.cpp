
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
    shadowEpsilon = 1e-1f;

    CookTorrance* material1 = new CookTorrance();
    material1->SetDiffuse(Color::Red());
    material1->SetRoughness(0.1f);
    material1->SetIncidence(0.118f);

    CookTorrance* material2 = new CookTorrance();
    material2->SetDiffuse(Color::Green());
    material2->SetRoughness(0.2f);
    material2->SetIncidence(0.118f);

    CookTorrance* material3 = new CookTorrance();
    material3->SetDiffuse(Color::Blue());
    material3->SetRoughness(0.3f);
    material3->SetIncidence(0.018f);

    CookTorrance* material4 = new CookTorrance();
    material4->SetDiffuse(Color(1.f, 1.f, 0.0f));
    material4->SetRoughness(0.4f);
    material4->SetIncidence(0.018f);

    Matte* material5 = new Matte();
    material5->SetDiffuse(Color::White());

    Sphere* sphere1 =  new Sphere(Vector( 150.0f,-50.0f, 125.f),  50.f);
    Sphere* sphere2 =  new Sphere(Vector(   0.0f,-50.0f,  75.f),  50.f);
    Sphere* sphere3 =  new Sphere(Vector(-150.0f,-50.0f,  25.f),  50.f);
    Sphere* sphere4 =  new Sphere(Vector(-300.0f,-50.0f, -25.f),  50.f);

    sphere1->SetMaterial(material1);
    sphere2->SetMaterial(material2);
    sphere3->SetMaterial(material3);
    sphere4->SetMaterial(material4);

    Plane* plane = new Plane(Vector(0.f, -100.f, 0.f), Vector(0.f, 1.0f, 0.0f));
    plane->SetMaterial(material5);

    DirectionalLight* light = new DirectionalLight(Normalize(Vector(0.f, -1.f, 0.f)), Color::White(), 0.0f);
    PointLight* point = new PointLight(Vector(-100.0f, 100.f, 400.0f), Color::White(), 2500.f, 1.f);

    World world;
    world.PushObject(sphere1);
    world.PushObject(sphere2);
    world.PushObject(sphere3);
    world.PushObject(sphere4);
    world.PushObject(plane);
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