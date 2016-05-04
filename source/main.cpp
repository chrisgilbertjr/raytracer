
#include "..\demos\Demos.h"

int 
main()
{
    InitializeRandomSeed();
    shadowEpsilon = 1e-1f;

    //Demo_BareBones("01_Barebones.bmp", 1); 
    //Demo_BareBones("02_Anti-aliasing.bmp", 512); 
    //Demo_Shapes("03_Shapes.bmp", 512); 
    //Demo_ShapesMatte("04_ShapesMatte.bmp", 512); 
    //Demo_SpecularSpheres("05_SpecularSpheres.bmp", 512);
    //Demo_ShadowSpheres("06_ShadowSpheres.bmp", 512);
    //Demo_TexturedShapes("07_TexturedSphere.bmp", 512);
    //Demo_OccluderShapes("08_OccluderShapes.bmp", 512);
    //Demo_AreaLightShapes2("09_AreaLightShapes2.bmp", 2500);
    //Demo_EnvironmentLight("10_EnvironmentLightShapes.bmp", 2500);
    //Demo_Reflections("12_ReflectionShapes.bmp", 2500);
    //Demo_Glossy("11_RoughShapes.bmp", 2500);
    //Demo_PathShader("13_PathTracer.bmp", 5000);
    //Demo_CornellBox("14_CornellBox.bmp", 50000);

    Sampler* pr = new PureRandom(15*15, 1);

    Demo_Sampler("sampler_PureRandom.bmp", pr->m_samples, pr, 1);
}