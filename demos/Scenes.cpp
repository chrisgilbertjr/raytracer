
#include "RaytracerAPI.h"

static Color 
RandomColor()
{
    return Color(RandReal(0.f, 1.f), RandReal(0.f, 1.f), RandReal(0.f, 1.f), 1.f);
}

static Color 
RandomColor(real scale)
{
    Color pastel(1.0f, 1.0f, 1.0f);
    Color color = RandomColor();
    color.r = (pastel.r + color.r) * scale;
    color.g = (pastel.g + color.g) * scale;
    color.b = (pastel.b + color.b) * scale;
    return color;
}

void 
Scene_Barebones(World* world)
{
    Sphere* sphere;
    Matte* material;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            real x = -250.f + ((real)i * 250.f);
            real y =  250.f - ((real)j * 250.f);
            real r = (i == 0) ? 1.f * ((real)(3-j)/4.f) : 0.f;
            real g = (i == 1) ? 1.f * ((real)(3-j)/4.f) : 0.f;
            real b = (i == 2) ? 1.f * ((real)(3-j)/4.f) : 0.f;

            material = new Matte();
            material->SetColor(Color(r, g, b));

            sphere = new Sphere(Vector(x, y, 0.f), 100.f);
            sphere->SetMaterial(material);

            world->PushObject(sphere);
        }
    }
}

void 
Scene_Shapes(World* world)
{
    CookTorrance* material;
    Object* shape;

    material = new CookTorrance();
    material->SetColor(Color::White());
    material->SetDiffuse(Color::White(), 1.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(1.0f);
    shape = new Plane(Vector(0.0f, -75.0f, 0.0f), Vector(0.0f, 1.0f, 0.f));
    shape->SetMaterial(material);

    world->PushObject(shape);

    material = new CookTorrance();
    material->SetColor(Color::Red());
    material->SetDiffuse(Color::Red(), 1.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(1.0f);
    material->SetIncidence(0.001f);
    shape = new Sphere(Vector(-250.0f, 0.0f, 0.0f), 75.f);
    shape->SetMaterial(material);

    world->PushObject(shape);

    material = new CookTorrance();
    material->SetColor(Color::Green());
    material->SetDiffuse(Color::Green(), 1.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(1.0f);
    shape = new Cylinder(Vector(0.0f, 0.0f, 0.0f), -75.0f, 125.f, 75.f);
    shape->SetMaterial(material);

    world->PushObject(shape);

    material = new CookTorrance();
    material->SetColor(Color::Blue());
    material->SetDiffuse(Color::Blue(), 1.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(1.0f);
    shape = new Rectangle(Vector(175.0f, 75.0f, 0.0f), 150.f, 150.f);
    shape->SetMaterial(material);

    world->PushObject(shape);

    Light* light = new PointLight(Vector(0.0f, 75.0f, 200.0f), Color::White(), 1000.f, 2.0f);
    light->CastShadows(false);
    world->PushLight(light);

    light = new DirectionalLight(Vector(0.0f, 0.f, -1.0f), Color::White(), 0.5f);
    light->CastShadows(false);
    world->PushLight(light);
}

void 
Scene_SpecularSpheres(World* world, bool shadows)
{
    CookTorrance* material;
    Object* shape;

    material = new CookTorrance();
    material->SetColor(Color::White());
    material->SetDiffuse(Color::White(), 1.0f);
    material->SetAmbient(Color::White(), 0.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(1.0f);
    shape = new Plane(Vector(0.0f, -75.0f, 0.0f), Normalize(Vector(0.0f, 1.0f, 0.4f)));
    shape->SetMaterial(material);
    world->PushObject(shape);

    material = new CookTorrance();
    material->SetColor(Color::Red());
    material->SetDiffuse(Color::Red(), 1.0f);
    material->SetAmbient(Color::Red(), 0.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(0.15f);
    material->SetIncidence(0.15f);
    shape = new Sphere(Vector(-275.0f, 0.0f, 0.0f), 65.f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    material = new CookTorrance();
    material->SetColor(Color::Red());
    material->SetDiffuse(Color::Red(), 1.0f);
    material->SetAmbient(Color::Red(), 0.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(0.2f);
    material->SetIncidence(0.2f);
    shape = new Sphere(Vector(-87.5f, 0.0f, 0.0f), 65.f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    material = new CookTorrance();
    material->SetColor(Color::Red());
    material->SetDiffuse(Color::Red(), 1.0f);
    material->SetAmbient(Color::Red(), 0.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(0.2f);
    material->SetIncidence(0.1f);
    shape = new Sphere(Vector(87.5f, 0.0f, 0.0f), 65.f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    material = new CookTorrance();
    material->SetColor(Color::Red());
    material->SetDiffuse(Color::Red(), 1.0f);
    material->SetAmbient(Color::Red(), 0.0f);
    material->SetSpecular(Color::White());
    material->SetRoughness(0.3f);
    material->SetIncidence(0.1f);
    shape = new Sphere(Vector(275.0f, 0.0f, 0.0f), 65.f);
    shape->SetMaterial(material);
    world->PushObject(shape);


    Light* light = new PointLight(Vector(200.0f, 50.0f, 600.0f), Color::White(), 1000.f, 2.0f);
    light->CastShadows(shadows);
    world->PushLight(light);

    light = new DirectionalLight(Vector(0.0f, 0.f, -1.0f), Color::White(), 0.0f);
    light->CastShadows(false);
    world->PushLight(light);
}

void 
Scene_TexturedShapes(World* world)
{
    Matte* material;
    Object* shape;

    Grid* grid = new Grid();
    grid->SetColors(Color::White(), Color(0.0f, 1.0f, 1.0f), Color::Black());
    grid->SetScale(7.f, 7.f);
    grid->SetLinePercentage(0.05f);

    Checker2D* checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(2.f, 2.f);

    material = new Matte(grid);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.2f);
    shape = new Plane(Vector(0.0f, -75.0f, 0.0f), Vector(0.0f, 1.0f, 0.f));
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(7.f, 7.f);

    material = new Matte(checker);
    shape = new Sphere(Vector(-250.0f, 0.0f, 0.0f), 75.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.2f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(9.f, 9.f);
    checker->SetOffset(0.0f, 0.1f);

    material = new Matte(checker);
    shape = new Cylinder(Vector(0.0f, 0.0f, 0.0f), -75.0f, 125.f, 75.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.2f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(3.f, 3.f);

    material = new Matte(checker);
    shape = new Rectangle(Vector(175.0f, 75.0f, 0.0f), 150.f, 150.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.2f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    Light* light = new PointLight(Vector(0.0f, 75.0f, 200.0f), Color::White(), 1000.f, 2.0f);
    light->CastShadows(true);
    world->PushLight(light);

    light = new DirectionalLight(Vector(0.0f, 0.f, -1.0f), Color::White(), 0.5f);
    light->CastShadows(false);
    world->PushLight(light);
}

void 
Scene_AreaLightShapes(World* world)
{
    Matte* material;
    Object* shape;

    Grid* grid = new Grid();
    grid->SetColors(Color::White(), Color(0.0f, 1.0f, 1.0f), Color::Black());
    grid->SetScale(7.f, 7.f);
    grid->SetLinePercentage(0.05f);

    Checker2D* checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(2.f, 2.f);

    material = new Matte(grid);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.0f);
    shape = new Plane(Vector(0.0f, -25.0f, 0.0f), Vector(0.0f, 1.0f, 0.f));
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(7.f, 7.f);

    material = new Matte(checker);
    shape = new Sphere(Vector(-250.0f, -50.0f, -100.0f), 75.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.0f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(9.f, 9.f);
    checker->SetOffset(0.0f, 0.1f);

    material = new Matte(checker);
    shape = new Cylinder(Vector(0.0f, -50.0f, -100.0f), -75.0f, 125.f, 75.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.0f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(3.f, 3.f);

    material = new Matte(checker);
    shape = new Rectangle(Vector(175.0f, 25.0f, -100.0f), 150.f, 150.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.0f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    AreaLight* area = new SphereAreaLight(Vector(0.f, 150.0f, 125.f), 25.f, new PureRandom(256));
    world->PushLight(area);
    world->PushObject(area->GetObject());
    //Light* light = new PointLight(Vector(0.0f, 75.0f, 200.0f), Color::White(), 1000.f, 2.0f);
    //light->CastShadows(true);
    //world->PushLight(light);

    //light = new DirectionalLight(Vector(0.0f, 0.f, -1.0f), Color::White(), 0.5f);
    //light->CastShadows(false);
    //world->PushLight(light);
}