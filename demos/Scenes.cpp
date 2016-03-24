
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
    shape = new Plane(Vector(0.0f, -125.0f, 0.0f), Vector(0.0f, 1.0f, 0.f));
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

    AreaLight* area = new SphereAreaLight(Vector(0.f, 150.0f, 200.f), 25.f, new PureRandom(256));
    world->PushLight(area);
    world->PushObject(area->GetObject());
    //Light* light = new PointLight(Vector(0.0f, 75.0f, 200.0f), Color::White(), 1000.f, 2.0f);
    //light->CastShadows(true);
    //world->PushLight(light);

    //light = new DirectionalLight(Vector(0.0f, 0.f, -1.0f), Color::White(), 0.5f);
    //light->CastShadows(false);
    //world->PushLight(light);
}

void 
Scene_AreaLightShapes2(World* world)
{
    real z = -200.f;
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
    shape = new Plane(Vector(0.0f, -125.0f, 0.0f), Vector(0.0f, 1.0f, 0.f));
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(7.f, 7.f);

    material = new Matte(checker);
    shape = new Sphere(Vector(-250.0f, -50.0f, z), 75.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.0f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(9.f, 9.f);
    checker->SetOffset(0.0f, 0.1f);

    material = new Matte(checker);
    shape = new Cylinder(Vector(0.0f, -50.0f, z), -75.0f, 125.f, 75.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.0f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(3.f, 3.f);

    material = new Matte(checker);
    shape = new Rectangle(Vector(175.0f, 25.0f, z), 150.f, 150.f);
    material->SetDiffuse(Color::White(), 0.8f);
    material->SetAmbient(Color::White(), 0.0f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    AreaLight* area = new SphereAreaLight(Vector(0.f, 250.0f, -1000.f), 65.f, new PureRandom(256));
    world->PushLight(area);
    //world->PushObject(area->GetObject());
    //Light* light = new PointLight(Vector(0.0f, 75.0f, 200.0f), Color::White(), 1000.f, 2.0f);
    //light->CastShadows(true);
    //world->PushLight(light);

    //light = new DirectionalLight(Vector(0.0f, 0.f, -1.0f), Color::White(), 0.5f);
    //light->CastShadows(false);
    //world->PushLight(light);
}

void
Scene_EnvironmentShapes(World* world)
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
    shape = new Plane(Vector(0.0f, -125.0f, 0.0f), Vector(0.0f, 1.0f, 0.f));
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

    Emmisive* emmisive01 = new Emmisive();
    emmisive01->SetEmmisive(Color::White(), 0.5f);

    ConvexSphere* csphere = new ConvexSphere(Vector(0.0f, 0.0f, 0.0f), 10000.f);
    csphere->SetMaterial(emmisive01);

    EnvironmentLight* env = new EnvironmentLight();
    env->SetMaterial(emmisive01);

    world->PushLight(env);
    world->PushObject(csphere);

    AreaLight* area = new SphereAreaLight(Vector(0.f, 250.0f, 250.f), 20.f, new PureRandom(256));
    world->PushLight(area);
}

void 
Scene_Reflections(World* world)
{
    Reflective* material;
    Matte* matte;
    Object* shape;

    Grid* grid = new Grid();
    grid->SetColors(Color::White(), Color(0.0f, 1.0f, 1.0f), Color::Black());
    grid->SetScale(7.f, 7.f);
    grid->SetLinePercentage(0.05f);

    Checker2D* checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(2.f, 2.f);

    matte = new Matte(grid);
    matte->SetDiffuse(Color::White(), 1.0f);
    matte->SetAmbient(Color::White(), 0.0f);
    shape = new Plane(Vector(0.0f, -125.0f, 0.0f), Vector(0.0f, 1.0f, 0.f));
    shape->SetMaterial(matte);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(7.f, 7.f);

    material = new Reflective();
    shape = new Sphere(Vector(-250.0f, -50.0f, -100.0f), 75.f);
    material->SetDiffuse(Color::White(), 0.5f);
    material->SetAmbient(Color::White(), 0.0f);
    material->SetReflective(Color::White(), 1.0f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    matte = new Matte(checker);
    shape = new Sphere(Vector(0.0f, -50.0f, -150.0f), 75.f);
    matte->SetDiffuse(Color::Red(), 0.9f);
    matte->SetAmbient(Color::White(), 0.1f);
    shape->SetMaterial(matte);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(9.f, 9.f);
    checker->SetOffset(0.0f, 0.1f);

    //material = new Reflective();
    //shape = new Cylinder(Vector(0.0f, -50.0f, -150.0f), -75.0f, 125.f, 75.f);
    //material->SetDiffuse(Color::Green(), 0.8f);
    //material->SetAmbient(Color::White(), 0.1f);
    //material->SetReflective(Color::White(), 0.1f);
    //shape->SetMaterial(material);
    //world->PushObject(shape);

    material = new Reflective();
    shape = new Sphere(Vector(250.0f, -50.0f, -100.0f), 75.f);
    material->SetDiffuse(Color::White(), 0.5f);
    material->SetAmbient(Color::White(), 0.0f);
    material->SetReflective(Color::White(), 1.0f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(3.f, 3.f);

    material = new Reflective();
    shape = new Rectangle(Vector(-600.0f, 200.0f, -350.0f), 600.f, 300.f);
    material->SetDiffuse(Color::White(), 0.2f);
    material->SetAmbient(Color::White(), 0.0f);
    material->SetReflective(Color::White(), 1.0f);
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
Scene_Glossy(World* world)
{
    Glossy* material;
    Matte* matte;
    Object* shape;

    Grid* grid = new Grid();
    grid->SetColors(Color::White(), Color(0.0f, 1.0f, 1.0f), Color::Black());
    grid->SetScale(7.f, 7.f);
    grid->SetLinePercentage(0.05f);

    Checker2D* checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(2.f, 2.f);

    matte = new Matte(grid);
    matte->SetDiffuse(Color::White(), 1.0f);
    matte->SetAmbient(Color::White(), 0.0f);
    shape = new Plane(Vector(0.0f, -125.0f, 0.0f), Vector(0.0f, 1.0f, 0.f));
    shape->SetMaterial(matte);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(7.f, 7.f);

    material = new Glossy();
    shape = new Sphere(Vector(-250.0f, -50.0f, -100.0f), 75.f);
    material->SetDiffuse(Color::White(), 0.5f);
    material->SetAmbient(Color::White(), 0.0f);
    material->SetGlossy(Color::White(), 1.0f, 0.f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    matte = new Matte(checker);
    shape = new Sphere(Vector(0.0f, -50.0f, -150.0f), 75.f);
    matte->SetDiffuse(Color::Red(), 0.9f);
    matte->SetAmbient(Color::White(), 0.1f);
    shape->SetMaterial(matte);
    world->PushObject(shape);

    material = new Glossy();
    shape = new Sphere(Vector(250.0f, -50.0f, -100.0f), 75.f);
    material->SetDiffuse(Color::White(), 0.5f);
    material->SetAmbient(Color::White(), 0.0f);
    material->SetGlossy(Color::White(), 1.0f, 0.f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(3.f, 3.f);

    Reflective* material0;

    material0 = new Reflective();
    shape = new Rectangle(Vector(-600.0f, 200.0f, -350.0f), 600.f, 300.f);
    material0->SetDiffuse(Color::White(), 0.2f);
    material0->SetAmbient(Color::White(), 0.0f);
    material0->SetReflective(Color::White(), 1.0f);
    shape->SetMaterial(material0);
    world->PushObject(shape);

    Light* light = new PointLight(Vector(0.0f, 75.0f, 200.0f), Color::White(), 1000.f, 2.0f);
    light->CastShadows(true);
    world->PushLight(light);

    light = new DirectionalLight(Vector(0.0f, 0.f, -1.0f), Color::White(), 0.5f);
    light->CastShadows(false);
    world->PushLight(light);
}

void 
Scene_PathShader(World* world)
{
    Matte* material;
    Object* shape;

    Emmisive* emmisive01 = new Emmisive();
    Emmisive* emmisive02 = new Emmisive();
    Emmisive* emmisive03 = new Emmisive();
    Emmisive* emmisive04 = new Emmisive();
    Emmisive* emmisive05 = new Emmisive();
    Emmisive* emmisive06 = new Emmisive();
    emmisive01->SetEmmisive(Color::White(), 2.75f);
    emmisive02->SetEmmisive(Color::White(), 2.75f);
    emmisive03->SetEmmisive(Color::White(), 2.75f);
    emmisive04->SetEmmisive(Color::White(), 2.75f);
    emmisive05->SetEmmisive(Color::White(), 30.f);
    emmisive06->SetEmmisive(Color::White(), 0.75f);

    Grid* grid = new Grid();
    grid->SetColors(Color::White(), Color(0.0f, 1.0f, 1.0f), Color::Black());
    grid->SetScale(7.f, 7.f);
    grid->SetLinePercentage(0.05f);

    Checker2D* checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(2.f, 2.f);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(7.f, 7.f);

    material = new Matte(checker);
    shape = new Sphere(Vector(-250.0f, -50.0f, -100.0f), 75.f);
    material->SetDiffuse(Color::White(), 0.9f);
    material->SetAmbient(Color::White(), 0.1f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(9.f, 9.f);
    checker->SetOffset(0.0f, 0.1f);

    material = new Matte(checker);
    shape = new Cylinder(Vector(0.0f, -50.0f, -100.0f), -75.0f, 125.f, 75.f);
    material->SetDiffuse(Color::White(), 0.9f);
    material->SetAmbient(Color::White(), 0.1f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    checker = new Checker2D();
    checker->SetColors(Color::White(), Color::Red());
    checker->SetScale(3.f, 3.f);

    material = new Matte(checker);
    shape = new Rectangle(Vector(175.0f, 25.0f, -100.0f), 150.f, 150.f);
    material->SetDiffuse(Color::White(), 0.9f);
    material->SetAmbient(Color::White(), 0.1f);
    shape->SetMaterial(material);
    world->PushObject(shape);

    Rectangle* rect;

    //material = new Matte();
    //rect = new Rectangle(Vector(-300.f, 0.f, 550.0f), Vector(0.0f, -200.f, 0.0f), Vector(200.f, 0.0f, 0.0f));
    //rect->SetMaterial(emmisive03);
    //world->PushObject(rect);

    //material = new Matte();
    //rect = new Rectangle(Vector( 100.f, 0.f, 550.0f), Vector(0.0f, -200.f, 0.0f), Vector(200.f, 0.0f, 0.0f));
    //rect->SetMaterial(emmisive04);
    //world->PushObject(rect);

    //material = new Matte(checker);
    //shape = new Sphere(Vector(0.0f, -100.0f, 200.0f), 25.f);
    //material->SetDiffuse(Color::White(), 1.0f);
    //material->SetAmbient(Color::White(), 0.0f);
    //shape->SetMaterial(emmisive05);
    //world->PushObject(shape);

    /// top
    material = new Matte();
    rect = new Rectangle(Vector(-400.f, 200.f, 600.0f), Vector(0.0f, 0.f, -1200.0f), Vector(1200.f, 0.0f, 0.0f));
    material->SetDiffuse(Color::White(), 1.0f);
    material->SetAmbient(Color::White(), 0.0f);
    rect->SetMaterial(material);
    world->PushObject(rect);

    /// bot
    material = new Matte();
    rect = new Rectangle(Vector(-400.f, -125.f, 600.0f), Vector(0.0f, 0.f, -1200.0f), Vector(1200.f, 0.0f, 0.0f));
    material->SetDiffuse(Color::White(), 1.0f);
    material->SetAmbient(Color::White(), 0.0f);
    rect->SetMaterial(material);
    rect->FlipNormal();
    world->PushObject(rect);

    /// left
    material = new Matte();
    rect = new Rectangle(Vector(-400.f, -125.f, -300.0f), Vector(0.0f, 0.f, 1200.0f), Vector(0.f, 1200.0f, 0.0f));
    material->SetDiffuse(Color::White(), 1.0f);
    material->SetAmbient(Color::White(), 0.0f);
    rect->SetMaterial(material);
    rect->FlipNormal();
    world->PushObject(rect);

    /// right
    material = new Matte();
    rect = new Rectangle(Vector(400.f, 200.f, 600.0f), Vector(0.0f, 0.f, -1200.0f), Vector(0.f, -1200.0f, 0.0f));
    material->SetDiffuse(Color::White(), 1.0f);
    material->SetAmbient(Color::White(), 0.0f);
    rect->SetMaterial(material);
    world->PushObject(rect);

    /// back
    material = new Matte();
    rect = new Rectangle(Vector(-400.f, 200.f, -300.0f), Vector(0.0f, -1200.0f, 0.f), Vector(1200.f, 0.0f, 0.0f));
    material->SetDiffuse(Color::White(), 1.0f);
    material->SetAmbient(Color::White(), 0.0f);
    rect->SetMaterial(material);
    world->PushObject(rect);

    /// front
    material = new Matte();
    rect = new Rectangle(Vector(-400.f, 200.f, 501.0f), Vector(0.0f, -1200.0f, 0.f), Vector(1200.f, 0.0f, 0.0f));
    material->SetDiffuse(Color::White(), 1.0f);
    material->SetAmbient(Color::White(), 0.0f);
    rect->SetMaterial(emmisive06);
    world->PushObject(rect);
}

void 
Scene_CornellBox(World* world)
{
    Matte* material;
    Object* shape;


    real width = 50.f;
    real height = 50.f;
    real width2 = width*2.f;
    real height2 = height*2.f;

    Rectangle* rect;
    Emmisive* emmisive = new Emmisive();
    emmisive->SetEmmisive(Color(1.0f, 0.73f, 0.4f), 50.f);
    rect = new Rectangle(Vector(-12.5f, 49.9f, 386.0f), Vector(0.0f, 0.f, -15.f), Vector(25.f, 0.0f, 0.0f));
    rect->SetMaterial(emmisive);
    world->PushObject(rect);

    /// top
    material = new Matte();
    material->SetDiffuse(Color::White(), 1.0f);
    rect = new Rectangle(Vector(-width, 50.f, 501.0f), Vector(0.0f, 0.f, -150.f), Vector(width2, 0.0f, 0.0f));
    rect->SetMaterial(material);
    world->PushObject(rect);

    /// bot
    material = new Matte();
    material->SetDiffuse(Color::White(), 1.0f);
    rect = new Rectangle(Vector(-width, -50.f, 501.0f), Vector(0.0f, 0.f, -150.f), Vector(width2, 0.0f, 0.0f));
    rect->SetMaterial(material);
    rect->FlipNormal();
    world->PushObject(rect);

    /// left
    material = new Matte();
    rect = new Rectangle(Vector(-width, 50.f, 501.0f), Vector(0.0f, 0.f, -150.f), Vector(0.0f, -width2, 0.0f));
    material->SetDiffuse(Color(0.5f, 0.0f, 0.0f), 1.0f);
    rect->SetMaterial(material);
    rect->FlipNormal();
    world->PushObject(rect);

    /// right
    material = new Matte();
    rect = new Rectangle(Vector( width, 50.f, 501.0f), Vector(0.0f, 0.f, -150.f), Vector(0.0f, -width2, 0.0f));
    material->SetDiffuse(Color(0.0f, 0.5f, 0.0f), 1.0f);
    rect->SetMaterial(material);
    //rect->FlipNormal();
    world->PushObject(rect);;

    /// back
    material = new Matte();
    rect = new Rectangle(Vector(-width, 50.f, 351.0f), Vector(0.0f, -width2, 0.f), Vector(width2, 0.0f, 0.0f));
    material->SetDiffuse(Color::White(), 1.0f);
    rect->SetMaterial(material);
    world->PushObject(rect);

    ///// front
    material = new Matte();
    rect = new Rectangle(Vector(-width, 50.f, 501.0f), Vector(0.0f, -width2, 0.f), Vector(width2, 0.0f, 0.0f));
    material->SetDiffuse(Color::White(), 1.0f);
    rect->SetMaterial(material);
    world->PushObject(rect);
}