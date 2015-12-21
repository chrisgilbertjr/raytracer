
#include "Cameras\Camera.h"

Camera::Camera()
    : m_view(0.f, 0.f, 0.f)
    , m_eye(0.f, 0.f, 500.f)
    , m_up(0.f, 1.f, 0.f)
    , m_u(1.f, 0.f, 0.f)
    , m_v(0.f, 1.f, 0.f)
    , m_w(0.f, 0.f, 1.f)
    , m_roll(0.f)
    , m_exposure(1.f)
{}

Camera::Camera(const Camera& camera)
    : m_view(camera.m_view)
    , m_eye(camera.m_eye)
    , m_up(camera.m_up)
    , m_u(camera.m_u)
    , m_v(camera.m_v)
    , m_w(camera.m_w)
    , m_roll(camera.m_roll)
    , m_exposure(camera.m_exposure)
{}

Camera::~Camera() {}

Camera& 
Camera::operator=(Camera camera)
{
    Swap<Vector>(m_view, camera.m_view);
    Swap<Vector>(m_eye, camera.m_eye);
    Swap<Vector>(m_up, camera.m_up);
    Swap<Vector>(m_u, camera.m_u);
    Swap<Vector>(m_v, camera.m_v);
    Swap<Vector>(m_w, camera.m_w);
    Swap<real>(m_roll, camera.m_roll);
    Swap<real>(m_exposure, camera.m_exposure);

    return *this;
}

Camera* 
Camera::Clone() const
{
    Assert(false);
    return NULL;
}

void 
Camera::Render(const World& world)
{
    /// @TODO:
}

void 
Camera::ComputeBasis()
{
    /// @TODO:
}