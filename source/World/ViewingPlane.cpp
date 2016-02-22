
#include "World\ViewingPlane.h"
#include "Core\MathUtils.h"


ViewingPlane::ViewingPlane()
    : m_width(1200)
    , m_height(800)
    //: m_width(800)
    //, m_height(600)
    , m_sampleCount(1)
    , m_maxDepth(1)
    , m_gamma(1.0f)
    , m_gammaInv(0.0f)
    , m_pixelSize(1.0f)
    , m_sampler(NULL)
{}


ViewingPlane::ViewingPlane(const ViewingPlane& plane)
    : m_width(plane.m_width)
    , m_height(plane.m_height)
    , m_sampleCount(plane.m_sampleCount)
    , m_maxDepth(plane.m_maxDepth)
    , m_gamma(plane.m_gamma)
    , m_gammaInv(plane.m_gammaInv)
    , m_pixelSize(plane.m_pixelSize)
    , m_sampler(plane.m_sampler)
{}


ViewingPlane::ViewingPlane(const int width, const int height)
    : m_width(width)
    , m_height(height)
    , m_sampleCount(1)
    , m_maxDepth(1)
    , m_gamma(1.0f)
    , m_gammaInv(0.0f)
    , m_pixelSize(1.0f)
    , m_sampler(NULL)
{}


ViewingPlane::ViewingPlane(const int width, const int height, const int sampleCount)
    : m_width(width)
    , m_height(height)
    , m_sampleCount(sampleCount)
    , m_maxDepth(1)
    , m_gamma(1.0f)
    , m_gammaInv(0.0f)
    , m_pixelSize(1.0f)
    , m_sampler(NULL)
{}


ViewingPlane::ViewingPlane(const int width, const int height, const real gamma, const real pizelSize)
    : m_width(width)
    , m_height(height)
    , m_gamma(gamma)
    , m_sampleCount(0)
    , m_maxDepth(1)
    , m_gammaInv((gamma > 0.0f) ? (1.f/gamma) : (0.0f))
    , m_pixelSize(1.0f)
    , m_sampler(NULL)
{}


ViewingPlane::~ViewingPlane() {}


ViewingPlane& 
ViewingPlane::operator=(ViewingPlane plane)
{
    Swap<int>(m_width, plane.m_width);
    Swap<int>(m_height, plane.m_height);
    Swap<int>(m_sampleCount, plane.m_sampleCount);
    Swap<int>(m_maxDepth, plane.m_maxDepth);
    Swap<real>(m_gamma, plane.m_gamma);
    Swap<real>(m_gammaInv, plane.m_gammaInv);
    Swap<real>(m_pixelSize, plane.m_pixelSize);
    Swap<Sampler*>(m_sampler, plane.m_sampler);

    return *this;
}

Color 
ViewingPlane::RemapColor(const Color& color) const
{
    Color remapped = color;

    remapped.clamp01();

    if (!Equal(this->m_gamma, 1.f))
    {
        remapped.pow(this->m_gammaInv);
    }

    return remapped;
}