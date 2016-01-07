
#ifndef PINHOLE_H
#define PINHOLE_H

#include "Cameras\Camera.h"

/// simple pinhole camera
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

    /// render the world through the pinhole camera
    virtual void Render(const World* world, const OutputOptions& output);

    /// inline member functions -----------------------------------------------

    inline void SetZoom(const real zoom)             { m_zoom = zoom; }

    inline void SetViewDistance(const real distance) { m_distance = distance; }
};

#endif