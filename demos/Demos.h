
#ifndef DEMOS_H
#define DEMOS_H

#include "..\include\RaytracerAPI.h"
#include "Scenes.h"

void Demo_BareBones(const char* output, int samples);

void Demo_Shapes(const char* output, int samples);

void Demo_ShapesMatte(const char* output, int samples);

void Demo_SpecularSpheres(const char* output, int samples);

void Demo_ShadowSpheres(const char* output, int samples);

void Demo_TexturedShapes(const char* output, int samples);

void Demo_OccluderShapes(const char* output, int samples);

void Demo_AreaLightShapes(const char* output, int samples);

void Demo_AreaLightShapes2(const char* output, int samples);

void Demo_EnvironmentLight(const char* output, int samples);

void Demo_Reflections(const char* output, int samples);

void Demo_Glossy(const char* output, int samples);

void Demo_PathShader(const char* output, int samples);

void Demo_CornellBox(const char* output, int samples);

#endif