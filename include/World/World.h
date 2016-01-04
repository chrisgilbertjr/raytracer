
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

/// output of the raytraced image
enum Output
{
    EXPORT_BMP = 0,
};

/// output options for the raytraced image
typedef struct OutputOptions
{
    Output output;        /// the raytraced image output
    std::string filename; /// the filename of the output
} OutputOptions;

/// the world class contains everything needed for the raytracer
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

    /// render a color buffer into an image
    void Render(const ColorBuffer& buffer) const;

    /// query all objects in the world given a ray
    ShadeRecord QueryObjects(const Ray& ray) const;

    /// inline member functions -----------------------------------------------

    /// push an object into the list
    inline void PushObject(Object* object)             { m_objects.Push(object); }

    /// remove and object from the list
    inline void RemoveObject(Object* object)           { m_objects.Remove(object); }

    /// get the viewing plane
    inline ViewingPlane GetViewingPlane() const        { return m_viewingPlane; }

    /// get a pointer to the list of objects in the world
    inline const Array<Object*>* GetObjects() const    { return &m_objects; }

    /// get a pointer to the raytracer being used
    inline const Raytracer* GetRaytracer() const       { return m_tracer; }

    /// get the background color of the world
    Color GetBackground() const                        { return m_background; }
};

void ExportBMP(const ColorBuffer& buffer, const OutputOptions& options);

/// @}

#endif