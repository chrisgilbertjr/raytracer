
#include "World\ViewingPlane.h"

ViewingPlane::ViewingPlane()
    : m_width(800)
    , m_height(600)
    , m_gamma(1.0f)
    , m_gammaInv(0.0f)
    , m_pixelSize(1.0f)
{
}

ViewingPlane::ViewingPlane(const ViewingPlane& plane)
{
    /// @TODO:
}

ViewingPlane::ViewingPlane(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_gamma(1.0f)
    , m_gammaInv(0.0f)
    , m_pixelSize(1.0f)
{
}

ViewingPlane::ViewingPlane(int width, int height, real gamma, real pizelSize)
    : m_width(width)
    , m_height(height)
    , m_gamma(gamma)
    , m_gammaInv((gamma > 0.0f) ? (1.f/gamma) : (0.0f))
    , m_pixelSize(1.0f)
{
}

ViewingPlane::~ViewingPlane() {}

void 
ViewingPlane::SetWidth(int width)
{
    m_width = width;
}

void 
ViewingPlane::SetHeight(int height)
{
    m_height = height;
}

void 
ViewingPlane::SetGamma(real gamma)
{
    m_gamma = gamma;
    m_gammaInv = (gamma > 0.0f) ? (1.f/gamma) : (0.0f);
}

void 
ViewingPlane::SetPizelSize(real pizelSize)
{
    m_pixelSize = pizelSize;
}

int 
ViewingPlane::GetWidth() const
{
    return m_width;
}

int 
ViewingPlane::GetHeight() const
{
    return m_height;
}

real 
ViewingPlane::GetGamma() const
{
    return m_gamma;
}

real 
ViewingPlane::GetGammaInv() const
{
    return m_gammaInv;
}

real 
ViewingPlane::GetPizelSize() const
{
    return m_pixelSize;
}