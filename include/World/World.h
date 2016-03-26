
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

    World(Light* ambient);

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

    /// set the viewing planes sampler
    void SetSampler(Sampler* sampler);

    /// set the worlds camera
    void SetCamera(Camera* camera);

    /// set the worlds ratracer
    void SetRaytracer(Raytracer* raytracer);

    /// set the background of the world
    void SetBackground(const Color& color);

    /// push an object into the list
    void PushObject(Object* object);

    /// remove and object from the list
    void RemoveObject(Object* object);

    /// push an object into the list
    void PushLight(Light* light);

    /// remove and object from the list
    void RemoveLight(Light* light);

    /// get the viewing plane
    ViewingPlane GetViewingPlane() const;

    /// get a pointer to the list of objects in the world
    const Array<Object*>* GetObjects() const;

    /// get a pointer to the list of objects in the world
    const Array<Light*>* GetLights() const;

    /// get a pointer to the raytracer being used
    const Raytracer* GetRaytracer() const;

    /// get the ambient lighting of the world
    Color GetAmbientRadiance(ShadeRecord& record) const;

    /// get the background color of the world
    Color GetBackground() const;

    /// set the output image resolution
    void SetResolution(const int width, const int height);

    /// set the ray tracing recursion depth
    void SetDepth(const int depth);
};

/// --------------------------------------------------------------------------- SetSampler

inline void 
World::SetSampler(Sampler* sampler)                   
{ 
    Assert(sampler); m_viewingPlane.SetSampler(sampler); 
}

/// --------------------------------------------------------------------------- SetCamera

inline void 
World::SetCamera(Camera* camera)                      
{ 
    Assert(camera); m_camera = camera; 
}

/// --------------------------------------------------------------------------- SetRaytracer

inline void 
World::SetRaytracer(Raytracer* raytracer)             
{ 
    Assert(raytracer); m_tracer = raytracer; 
}

/// --------------------------------------------------------------------------- SetBackground

inline void 
World::SetBackground(const Color& color)              
{ 
    m_background = color; 
}

/// --------------------------------------------------------------------------- PushObject

inline void 
World::PushObject(Object* object)                     
{ 
    Assert(object); m_objects.Push(object); 
}

/// --------------------------------------------------------------------------- RemoveObject

inline void 
World::RemoveObject(Object* object)                   
{ 
    Assert(object); m_objects.Remove(object); 
}

/// --------------------------------------------------------------------------- PushLight

inline void 
World::PushLight(Light* light)                        
{ 
    Assert(light); m_lights.Push(light); 
}

/// --------------------------------------------------------------------------- RemoveLight

inline void 
World::RemoveLight(Light* light)                      
{ 
    Assert(light); m_lights.Remove(light); 
}

/// --------------------------------------------------------------------------- GetViewingPlane

inline ViewingPlane 
World::GetViewingPlane() const                
{ 
    return m_viewingPlane; 
}

/// --------------------------------------------------------------------------- GetObjects

inline const Array<Object*>* 
World::GetObjects() const            
{ 
    return &m_objects; 
}

/// --------------------------------------------------------------------------- GetLights

inline const Array<Light*>* 
World::GetLights() const              
{ 
    return &m_lights; 
}

/// --------------------------------------------------------------------------- GetRaytracer

inline const Raytracer* 
World::GetRaytracer() const               
{ 
    return m_tracer; 
}

/// --------------------------------------------------------------------------- GetAmbientRadiance

inline Color 
World::GetAmbientRadiance(ShadeRecord& record) const 
{ 
    return m_ambient->Radiance(record); 
} 

/// --------------------------------------------------------------------------- GetBackground

inline Color
World::GetBackground() const                         
{ 
    return m_background; 
}

/// --------------------------------------------------------------------------- SetResolution

inline void 
World::SetResolution(const int width, const int height) 
{ 
    m_viewingPlane.SetHeight(height); m_viewingPlane.SetWidth(width); 
}

/// --------------------------------------------------------------------------- SetDepth

inline void 
World::SetDepth(const int depth) 
{
    m_viewingPlane.SetMaxDepth(depth); 
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif