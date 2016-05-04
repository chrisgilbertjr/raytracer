
#ifndef SCENES_H
#define SCENES_H

class World;

void Scene_Barebones(World* world);
void Scene_Shapes(World* world);
void Scene_SpecularSpheres(World* world, bool shadows);
void Scene_TexturedShapes(World* world);
void Scene_AreaLightShapes(World* world);
void Scene_AreaLightShapes2(World* world);
void Scene_EnvironmentShapes(World* world);
void Scene_Reflections(World* world);
void Scene_Glossy(World* world);
void Scene_PathShader(World* world);
void Scene_CornellBox(World* world);

#endif