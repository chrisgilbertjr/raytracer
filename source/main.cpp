
#include "..\demos\Demos.h"

int 
main()
{
    InitializeRandomSeed();
    shadowEpsilon = 1e-1f;

    //Demo_BareBones("01_Barebones.bmp", 1); 
    //Demo_BareBones("02_Anti-aliasing.bmp", 32); 
    //Demo_Shapes("03_Shapes.bmp", 32); 
    //Demo_ShapesMatte("04_ShapesMatte.bmp", 32); 
    //Demo_SpecularSpheres("05_SpecularSpheres.bmp", 4);
    //Demo_ShadowSpheres("06_ShadowSpheres.bmp", 4);
    //Demo_TexturedShapes("07_TexturedSphere.bmp", 64);
    //Demo_OccluderShapes("08_OccluderShapes.bmp", 64);
    //Demo_AreaLightShapes2("09_AreaLightShapes2.bmp", 128);
    //Demo_EnvironmentLight("10_EnvironmentLightShapes.bmp", 512);
    //Demo_Reflections("11_ReflectionShapes.bmp", 256);
    //Demo_Glossy("12_GlossyShapes.bmp", 32);
    //Demo_PathShader("13_PathTracer14.bmp", 5000);

    Demo_CornellBox("14_CornellBox50000_10.bmp", 50000);
    //Sampler* pr = new PureRandom(50, 1);
    //pr->MapSamplesToHemisphere();

    //for (int i = 0; i < 50; i++)
    //{
    //    fprintf(stdout, "%.7f, %.7f, %.7f\n", pr->m_hemiSamples[i].x, pr->m_hemiSamples[i].y, pr->m_hemiSamples[i].z);
    //}

    //Demo_Sampler("sampler.bmp", pr->m_hemiSamples, pr, 1);
    while (1) {};
}