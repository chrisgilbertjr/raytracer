
#ifndef WORLD_H
#define WORLD_H

#include "Objects\Object.h"
#include "Core\Array.h"
#include "World\ViewingPlane.h"
#include "Raytracers\Raytracer.h"
#include "ColorBuffer.h"
#include "..\Cameras\Camera.h"
#include "Output.h"

/// @defgroup World World
/// @{

/// the world class contains everything needed for the raytracer
class World
{
private:
    ViewingPlane m_viewingPlane; /// world view plane
    Array<Object*> m_objects;    /// array of geometric objects in the world
    Raytracer* m_tracer;         /// ray tracer 
    Camera* m_camera;            /// camera used to render a scene
    Color m_background;          /// background color

public:
    /// default constructor
    World();

    /// copy constructor
    World(const World& world);

    /// destructor
    ~World();

    /// copy assignment operator
    World& operator=(World world);

    /// render a color buffer into an image
    void Render(const OutputOptions& options) const;

    /// export the rendered image
    void Export(const ColorBuffer& buffer, const OutputOptions& options) const;

    /// query all objects in the world given a ray
    ShadeRecord QueryObjects(const Ray& ray) const;

    /// inline member functions -----------------------------------------------

    /// set the worlds camera
    inline void SetCamera(Camera* camera)              { Assert(camera); m_camera = camera; }

    /// push an object into the list
    inline void PushObject(Object* object)             { Assert(object); m_objects.Push(object); }

    /// remove and object from the list
    inline void RemoveObject(Object* object)           { Assert(object); m_objects.Remove(object); }

    /// get the viewing plane
    inline ViewingPlane GetViewingPlane() const        { return m_viewingPlane; }

    /// get a pointer to the list of objects in the world
    inline const Array<Object*>* GetObjects() const    { return &m_objects; }

    /// get a pointer to the raytracer being used
    inline const Raytracer* GetRaytracer() const       { return m_tracer; }

    /// get the background color of the world
    Color GetBackground() const                        { return m_background; }
};

/// @}

#endif