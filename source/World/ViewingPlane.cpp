
#include "World\ViewingPlane.h"
#include "Core\MathUtils.h"


ViewingPlane::ViewingPlane()
    : m_width(800)
    , m_height(600)
    , m_sampleCount(1)
    , m_gamma(1.0f)
    , m_gammaInv(0.0f)
    , m_pixelSize(1.0f)
{}


ViewingPlane::ViewingPlane(const ViewingPlane& plane)
    : m_width(plane.m_width)
    , m_height(plane.m_height)
    , m_sampleCount(plane.m_sampleCount)
    , m_gamma(plane.m_gamma)
    , m_gammaInv(plane.m_gammaInv)
    , m_pixelSize(plane.m_pixelSize)
{}


ViewingPlane::ViewingPlane(const int width, const int height)
    : m_width(width)
    , m_height(height)
    , m_sampleCount(1)
    , m_gamma(1.0f)
    , m_gammaInv(0.0f)
    , m_pixelSize(1.0f)
{}


ViewingPlane::ViewingPlane(const int width, const int height, const int sampleCount)
    : m_width(width)
    , m_height(height)
    , m_sampleCount(sampleCount)
    , m_gamma(1.0f)
    , m_gammaInv(0.0f)
    , m_pixelSize(1.0f)
{}


ViewingPlane::ViewingPlane(const int width, const int height, const real gamma, const real pizelSize)
    : m_width(width)
    , m_height(height)
    , m_gamma(gamma)
    , m_gammaInv((gamma > 0.0f) ? (1.f/gamma) : (0.0f))
    , m_pixelSize(1.0f)
{}


ViewingPlane::~ViewingPlane() {}


ViewingPlane& 
ViewingPlane::operator=(ViewingPlane plane)
{
    Swap<int>(m_width, plane.m_width);
    Swap<int>(m_height, plane.m_height);
    Swap<real>(m_gamma, plane.m_gamma);
    Swap<real>(m_gammaInv, plane.m_gammaInv);
    Swap<real>(m_pixelSize, plane.m_pixelSize);

    return *this;
}

Color 
ViewingPlane::RemapColor(const Color& color) const
{
    Color remapped = color;

    /// TODO: out of gamut colors

    if (!Equal(this->m_gamma, 1.f))
    {
        remapped.pow(this->m_gammaInv);
    }

    return remapped;
}