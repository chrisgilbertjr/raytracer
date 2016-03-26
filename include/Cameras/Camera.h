
#ifndef CAMERA_H
#define CAMERA_H

#include "..\Core\MathUtils.h"
#include "..\World\Output.h"

/// @defgroup Camera Camera
/// @{

/// forward declaration
class World;

/// base camera class
class Camera
{
protected:
    Vector m_view;   /// view point
    Vector m_eye;    /// eye point
    Vector m_up;     /// up vector
    Vector m_u;      /// basis x vector
    Vector m_v;      /// basis y vector
    Vector m_w;      /// basis z vector
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

    /// render the world from this cameras POV
    virtual void Render(const World* world, const OutputOptions& output);

    /// render the world using multiple threads
    virtual void RenderThreads(const World* world, const OutputOptions& output);

    /// compute the cameras orthonormal basis
    void ComputeBasis();

    /// set the camera view point
    void SetView(const Vector& point);

    /// set the camera view point
    void SetView(const real x, const real y, const real z);

    /// set the camera eye point
    void SetEye(const Vector& point);

    /// set the camera eye point
    void SetEye(const real x, const real y, const real z);

    /// set the camera up vector
    void SetUp(const Vector& point);

    /// set the camera up vector
    void SetUp(const real x, const real y, const real z);

    /// set the cameras roll angle
    void SetRoll(const float angle);
    
    /// set the cameras exposure time
    void SetExposure(const float time);
};

/// --------------------------------------------------------------------------- SetView

inline void
Camera::SetView(const Vector& point)
{
    m_view = point;
}

/// --------------------------------------------------------------------------- SetView

inline void 
Camera::SetView(const real x, const real y, const real z)  
{ 
    m_view = Vector(x, y, z); 
}

/// --------------------------------------------------------------------------- SetEye

inline void 
Camera::SetEye(const Vector& point)                        
{ 
    m_eye = point; 
}

/// --------------------------------------------------------------------------- SetEye

inline void 
Camera::SetEye(const real x, const real y, const real z)   
{ 
    m_eye = Vector(x, y, z); 
}

/// --------------------------------------------------------------------------- SetUp

inline void 
Camera::SetUp(const Vector& point)                         
{ 
    m_up = point; 
}

/// --------------------------------------------------------------------------- SetUp

inline void 
Camera::SetUp(const real x, const real y, const real z)    
{ 
    m_up = Vector(x, y, z); 
}

/// --------------------------------------------------------------------------- SetRoll

inline void 
Camera::SetRoll(const float angle)                         
{ 
    m_roll = angle; 
}

/// --------------------------------------------------------------------------- SetExposure

inline void 
Camera::SetExposure(const float time)                      
{ 
    m_exposure = time; 
}

/// --------------------------------------------------------------------------- EOF

/// @}

#endif