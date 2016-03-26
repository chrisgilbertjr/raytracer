
#ifndef PINHOLE_H
#define PINHOLE_H

#include "Cameras\Camera.h"

class ColorBuffer;

/// simple pinhole camera (perspective projection)
class Pinhole : public Camera
{
private:
    real m_distance; /// view plane distance
    real m_zoom;     /// camera zoom

public:
    /// default constructor
    Pinhole();

    /// copy constructor
    Pinhole(const Pinhole& pinhole);

    /// destructor
    virtual ~Pinhole();

    /// copy assignment operator
    Pinhole& operator=(Pinhole pinhole);

    /// clone this pinhold, deep copy
    virtual Camera* Clone() const;

    /// get the direction of the camera
    Vector ComputeRayDirection(const Vector& point) const;

    /// render the world 
    virtual void Render(const World* world, const OutputOptions& output);

    /// render the world 
    virtual void RenderThreads(const World* world, const OutputOptions& output);

    void ComputePixel(const World* world, ColorBuffer* buffer, const OutputOptions& options, int x, int y);

    /// set the camera zoom
    void SetZoom(const real zoom);

    /// set the cameras view distance from thje pinhole
    void SetViewDistance(const real distance);
};

/// --------------------------------------------------------------------------- SetZoom

inline void 
Pinhole::SetZoom(const real zoom)
{
    m_zoom = zoom;
}

/// --------------------------------------------------------------------------- SetViewDistance

inline void 
Pinhole::SetViewDistance(const real distance) 
{ 
    m_distance = distance; 
}

/// --------------------------------------------------------------------------- EOF

#endif