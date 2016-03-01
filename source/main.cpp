
/// ***************************************************************************************
/// @TODO: Make sure all constructors call BASE CLASS constructors when cleaining up code!
///        A lot of copy constructors missed calling base class constructors!
/// ***************************************************************************************

#include "World\World.h"
#include "Cameras\Pinhole.h"
#include "Samplers\Simple.h"
#include "Raytracers\PureColor.h"
#include "Raytracers\Shaded.h"
#include "Raytracers\Whitted.h"
#include "Raytracers\PathTracer.h"
#include "Samplers\PureRandom.h"
#include "Samplers\Hammersley.h"
#include "Samplers\Jittered.h"
#include "Samplers\MultiJittered.h"
#include "Samplers\NRooks.h"
#include "Objects\Sphere.h"
#include "Objects\ConvexSphere.h"
#include "Objects\Cylinder.h"
#include "Objects\Rectangle.h"
#include "Objects\Plane.h"
#include "Materials\Matte.h"
#include "Materials\Phong.h"
#include "Materials\Reflective.h"
#include "Materials\CookTorrance.h"
#include "Materials\Emmisive.h"
#include "Textures\Checker2D.h"
#include "Lights\DirectionalLight.h"
#include "Lights\PointLight.h"
#include "Lights\EnvironmentLight.h"
#include "Objects\SphereLight.h"
#include "Lights\AreaLight.h"
#include "Raytracers\AreaLighting.h"

//int 
//main(void)
//{
//    shadowEpsilon = 1e-1f;

//    CookTorrance* material1 = new CookTorrance();
//    material1->SetAmbient(Color::Red());
//    material1->SetDiffuse(Color::Red());
//    material1->SetRoughness(0.4f);
//    material1->SetIncidence(0.018f);

//    Reflective* material01 = new Reflective();
//    material01->SetAmbient(Color::White(), 1.0f);
//    material01->SetDiffuse(Color::Red());
//    material01->SetRoughness(0.5f);
//    material01->SetIncidence(0.118f);
//    material01->SetReflective(Color::White(), 1.f);

//    Sphere* sphere1 =  new Sphere(Vector(0,-50,100), 50.f);

//    sphere1->SetMaterial(material1);

//    Matte* material5 = new Matte();
//    material5->SetAmbient(Color::White());
//    material5->SetDiffuse(Color::White());

//    Plane* plane = new Plane(Vector(0.f, -100.f, 0.f), Vector(0.f, 1.0f, 0.0f));
//    plane->SetMaterial(material5);

//    //DirectionalLight* light = new DirectionalLight(Normalize(Vector(0.f, -1.f, 0.f)), Color::White(), 0.0f);
//    //PointLight* point = new PointLight(Vector(-100.0f, 100.f, 400.0f), Color::White(), 2500.f, 1.5f);

//    World world;
//    world.PushObject(sphere1);
//    world.PushObject(plane);

//    world.SetCamera(new Pinhole());
//    world.SetSampler(new Hammersley(64));
//    world.SetRaytracer(new Whitted());
//    world.SetBackground(Color::Black());
//    world.GetViewingPlane().SetMaxDepth(1);

//    world.Render(Options(EXPORT_BMP, "world.bmp"));

//    fprintf(stdout, "complete!");

//    while (1) {}

//    return 0;
//}

int 
main(void)
{
    shadowEpsilon = 1e-1f;

    CookTorrance* material1 = new CookTorrance();
    material1->SetAmbient(Color::Red(), 0.5f);
    material1->SetDiffuse(Color::Red());
    material1->SetRoughness(0.4f);
    material1->SetIncidence(0.018f);

    CookTorrance* material2 = new CookTorrance();
    material2->SetAmbient(Color::Green(), 0.5f);
    material2->SetDiffuse(Color::Green());
    material2->SetRoughness(0.2f);
    material2->SetIncidence(0.118f);

    CookTorrance* material3 = new CookTorrance();
    material3->SetAmbient(Color::Blue(), 0.5f);
    material3->SetDiffuse(Color::Blue());
    material3->SetRoughness(0.3f);
    material3->SetIncidence(0.018f);

    CookTorrance* material4 = new CookTorrance();
    material4->SetAmbient(Color(1.f, 1.f, 0.0f), 0.5f);
    material4->SetDiffuse(Color(1.f, 1.f, 0.0f));
    material4->SetRoughness(0.4f);
    material4->SetIncidence(0.018f);

    Reflective* material01 = new Reflective();
    material01->SetAmbient(Color::Red(), 0.5f);
    material01->SetDiffuse(Color::Red());
    material01->SetRoughness(0.5f);
    material01->SetIncidence(0.118f);
    material01->SetReflective(Color::White(), 0.3f);

    Reflective* material02 = new Reflective();
    material02->SetAmbient(Color::Red(), 0.7f);
    material02->SetDiffuse(Color::Red());
    material02->SetRoughness(0.2f);
    material02->SetIncidence(0.218f);
    material02->SetReflective(Color::White(), 1.0f);

    Reflective* material03 = new Reflective();
    material03->SetAmbient(Color::Green(), 0.7f);
    material03->SetDiffuse(Color::Green());
    material03->SetRoughness(0.1f);
    material03->SetIncidence(0.018f);
    material03->SetReflective(Color::White(), 1.0f);

    Reflective* material04 = new Reflective();
    material04->SetAmbient(Color(1.f, 1.f, 0.0f), 0.5f);
    material04->SetDiffuse(Color(1.f, 1.f, 0.0f));
    material04->SetRoughness(0.4f);
    material04->SetIncidence(0.018f);;
    material04->SetReflective(Color::White(), 0.05f);

    Checker2D* checker = new Checker2D();
    checker->SetColors(Color::Red(), Color::Green());
    checker->SetScale(2.f, 2.f);

    Matte* matte01 = new Matte();
    matte01->SetAmbient(Color::Red(), 0.5f);
    matte01->SetDiffuse(Color::Red());

    Matte* matte03 = new Matte(checker);
    matte03->SetAmbient(Color::Green(), 0.7f);
    matte03->SetDiffuse(Color::Green());

    Emmisive* emmisive01 = new Emmisive();
    emmisive01->SetEmmisive(Color::White(), 1.0f);

    Matte* material5 = new Matte();
    material5->SetAmbient(Color::White(), 0.5f);
    material5->SetDiffuse(Color::White());

    Sphere* sphere1 =  new Sphere(Vector( 150.0f,-50.0f, 125.f),  50.f);
    //Sphere* sphere1 =  new Sphere(Vector(0.f),  100.f);
    Sphere* sphere2 =  new Sphere(Vector(   0.0f,-50.0f,  50.f),  50.f);
    Sphere* sphere3 =  new Sphere(Vector(-150.0f,-50.0f,  50.f),  50.f);
    Sphere* sphere4 =  new Sphere(Vector(0.0f,100.0f, 200.f),  50.f);
    Cylinder* cylinder = new Cylinder(Vector(0.f), 100.f, 50.f);
    Rectangle* rect = new Rectangle(Vector(0.f), 100.f, 100.f);
    ConvexSphere* csphere = new ConvexSphere(Vector(0.0f, 0.0f, 0.0f), 10000.f);

    sphere1->SetMaterial(matte03);
    sphere2->SetMaterial(matte01);
    sphere3->SetMaterial(matte03);
    sphere4->SetMaterial(matte01);
    cylinder->SetMaterial(matte03);
    rect->SetMaterial(matte03);
    csphere->SetMaterial(emmisive01);

    Plane* plane = new Plane(Vector(0.f, -100.f, 0.f), Vector(0.f, 1.0f, 0.0f));
    plane->SetMaterial(material5);

    DirectionalLight* light = new DirectionalLight(Normalize(Vector(-1.f, -1.f, 0.f)), Color::Blue(), 0.3f);
    PointLight* point = new PointLight(Vector(-100.0f, 100.f, 400.0f), Color::White(), 2500.f, 1.5f);

    AreaLight* area = new SphereAreaLight(Vector(0.f, 0.0f, 300.f), 10.f, new PureRandom(256));
    EnvironmentLight* env = new EnvironmentLight();
    env->SetMaterial(emmisive01);

    World world;
    //world.PushObject(sphere1);
    //world.PushObject(sphere2);
    //world.PushObject(sphere3);
    //world.PushObject(cylinder);
    world.PushObject(rect);
    world.PushObject(csphere);
    //world.PushObject(sphere4);
    world.PushObject(plane);
    //world.PushObject(area->GetObject());
    //world.PushLight(light);
    world.PushLight(point);
    //world.PushLight(area);
    //world.PushLight(env);

    world.SetCamera(new Pinhole());
    world.SetSampler(new Hammersley(16));
    world.SetRaytracer(new Shaded());
    //world.SetRaytracer(new PathTracer());
    //world.SetRaytracer(new AreaLighting());
    //world.SetRaytracer(new Whitted());
    world.SetBackground(Color::Black());
    world.GetViewingPlane().SetMaxDepth(1);

    world.Render(Options(EXPORT_BMP, "world2.bmp"));

    fprintf(stdout, "complete!");

    while (1) {}

    return 0;
}