
#ifndef WORLD_H
#define WORLD_H

#include "Objects\Object.h"
#include "ViewingPlane.h"
#include "Raytracer.h"
#include "Array.h"

class World
{
private:
    ViewingPlane m_viewingPlane;
    Array<Object*> m_objects;
    Raytracer* m_tracer;
    Color m_background;

public:
    World();

    ~World();

    void SetBackgroundColor(const Color& color);

    const ViewingPlane* GetViewingPlane() const;

    const Array<Object*>* GetObjects() const;

    const Raytracer* GetRaytracer() const;

    Color GetBackgroundColor() const;

    void PushObject(Object* object);

    void RemoveObject(Object* object);
};

#endif