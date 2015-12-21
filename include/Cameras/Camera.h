
#ifndef CAMERA_H
#define CAMERA_H

#include "World\World.h"

/// base camera class
class Camera
{
protected:
    Vector m_view;   /// view point
    Vector m_eye;    /// eye point
    Vector m_up;     /// up vector
    Vector m_u;      /// basis x vector
    Vector m_v;      /// basis y vector
    Vector m_w;      /// basis z vector (-z)
    real m_roll;     /// roll angle
    real m_exposure; /// exposure time

public:
    /// default constructor
    Camera();

    /// copy constructor
    Camera(const Camera& camera);

    /// destructor
    virtual ~Camera();

    /// copy assignment operator
    Camera& operator=(Camera camera);

    /// deep copy, clones a camera object
    virtual Camera* Clone() const;

    /// render  the world from this cameras POV
    virtual void Render(const World& world);

    /// compute the cameras orthonormal basis
    void ComputeBasis();

    /// inline member functions -----------------------------------------------

    /// set the camera view point
    inline void SetView(const Vector& point)                       { m_view = point; }

    /// set the camera view point
    inline void SetView(const real x, const real y, const real z)  { m_view = Vector(x, y, z); }

    /// set the camera eye point
    inline void SetEye(const Vector& point)                        { m_eye = point; }

    /// set the camera eye point
    inline void SetEye(const real x, const real y, const real z)   { m_eye = Vector(x, y, z); }

    /// set the camera up vector
    inline void SetUp(const Vector& point)                         { m_up = point; }

    /// set the camera up vector
    inline void SetUp(const real x, const real y, const real z)    { m_up = Vector(x, y, z); }

    /// set the cameras roll angle
    inline void SetRoll(const float angle)                         { m_roll = angle; }
    
    /// set the cameras exposure time
    inline void SetExposure(const float time)                      { m_exposure = time; }
};

#endif