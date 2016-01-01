
#ifndef WORLD_H
#define WORLD_H

#include <string>
#include "Objects\Object.h"
#include "Core\Array.h"
#include "World\ViewingPlane.h"
#include "Raytracers\Raytracer.h"
#include "ColorBuffer.h"

/// @defgroup World World
/// @{

enum Output
{
    EXPORT_BMP = 0,
};

typedef struct OutputOptions
{
    Output output;
    std::string filename;
} OutputOptions;

class World
{
private:
    ViewingPlane m_viewingPlane; /// world view plane
    Array<Object*> m_objects;    /// array of geometric objects in the world
    Raytracer* m_tracer;         /// ray tracer 
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

    void Render(const ColorBuffer& buffer) const;

    void QueryObjects(const Ray& ray) const;

    /// inline member functions -----------------------------------------------

    inline void PushObject(Object* object)             { m_objects.Push(object); }

    inline void RemoveObject(Object* object)           { m_objects.Remove(object); }

    inline ViewingPlane GetViewingPlane() const        { return m_viewingPlane; }

    inline const Array<Object*>* GetObjects() const    { return &m_objects; }

    inline const Raytracer* GetRaytracer() const       { return m_tracer; }

    /// get the background color of the world
    Color GetBackground() const                        { return m_background; }
};

/// @}

#endif