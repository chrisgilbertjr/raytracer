
#ifndef WORLD_H
#define WORLD_H

#include "Objects\Object.h"
#include "Core\Array.h"
#include "World\ViewingPlane.h"
#include "Raytracers\Raytracer.h"
#include "ColorBuffer.h"
#include "..\Cameras\Camera.h"
#include "Output.h"
#include "..\Lights\Light.h"
#include "..\Lights\AmbientOccluder.h"

/// @defgroup World World
/// @{

/// the world class contains everything needed for the raytracer
class World
{
private:
    ViewingPlane m_viewingPlane; /// world view plane
    Array<Object*> m_objects;    /// array of geometric objects in the world
    Array<Light*> m_lights;      /// array of lights in the world
    Light* m_ambient;            /// ambient world lighting
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

    /// free all objects in the world
    void Free();

    /// inline member functions -----------------------------------------------

    /// set the viewing planes sampler
    inline void SetSampler(Sampler* sampler)                   { Assert(sampler); m_viewingPlane.SetSampler(sampler); }

    /// set the worlds camera
    inline void SetCamera(Camera* camera)                      { Assert(camera); m_camera = camera; }

    /// set the worlds ratracer
    inline void SetRaytracer(Raytracer* raytracer)             { Assert(raytracer); m_tracer = raytracer; }

    /// set the background of the world
    inline void SetBackground(const Color& color)              { m_background = color; }

    /// push an object into the list
    inline void PushObject(Object* object)                     { Assert(object); m_objects.Push(object); }

    /// remove and object from the list
    inline void RemoveObject(Object* object)                   { Assert(object); m_objects.Remove(object); }

    /// push an object into the list
    inline void PushLight(Light* light)                        { Assert(light); m_lights.Push(light); }

    /// remove and object from the list
    inline void RemoveLight(Light* light)                      { Assert(light); m_lights.Remove(light); }

    /// get the viewing plane
    inline ViewingPlane GetViewingPlane() const                { return m_viewingPlane; }

    /// get a pointer to the list of objects in the world
    inline const Array<Object*>* GetObjects() const            { return &m_objects; }

    /// get a pointer to the list of objects in the world
    inline const Array<Light*>* GetLights() const              { return &m_lights; }

    /// get a pointer to the raytracer being used
    inline const Raytracer* GetRaytracer() const               { return m_tracer; }

    /// get the ambient lighting of the world
    inline Color GetAmbientRadiance(ShadeRecord& record) const { return m_ambient->Radiance(record); } 
    /// get the background color of the world
    inline Color GetBackground() const                         { return m_background; }
};

/// @}

#endif