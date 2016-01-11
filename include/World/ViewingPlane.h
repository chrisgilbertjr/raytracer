
#ifndef VIEWING_PLANE_H
#define VIEWING_PLANE_H

#include "..\Samplers\Sampler.h"
#include "Core\Color.h"

class ViewingPlane
{
private:
    int m_width;        /// width of the viewing plane
    int m_height;       /// height of the viewing plane
    int m_sampleCount;  /// number of samples per pixel
    real m_gamma;       /// gamma of the viewing plane
    real m_gammaInv;    /// inverse gamma of the viewing plane
    real m_pixelSize;   /// pixel size of the viewing plane
    Sampler* m_sampler; /// sampler pointer

public:
    /// default constructor
    ViewingPlane();

    /// copy constructor
    ViewingPlane(const ViewingPlane& plane);
    
    /// constructor
    ViewingPlane(const int width, const int height);

    /// constructor
    ViewingPlane(const int width, const int height, const int sampleCount);

    /// constructor
    ViewingPlane(const int width, const int height, const real gamma, const real pizelSize);

    /// destructor
    ~ViewingPlane();

    /// copy assignment operator
    ViewingPlane& operator=(ViewingPlane plane);

    /// remap a color by handling out of gamut colors and gamma correction
    Color RemapColor(const Color& color) const;

    //// inline member functions ----------------------------------------------

    /// set the width of the viewing plane
    void SetWidth(const int width)          { m_width = width; }

    /// set the height of the viewing plane
    void SetHeight(const int height)        { m_height = height; }

    /// set the samples per pixel
    void SetSampleCount(const int samples)  { m_sampleCount = samples; }

    /// set the gamma of the viewing plane
    void SetGamma(const real gamma)         { m_gamma = gamma; m_gammaInv = (gamma > 0.f) ? (1.f / gamma) : (0.f); }

    /// set the pizel size of the viewing plane
    void SetPizelSize(const real pixelSize) { m_pixelSize = pixelSize; }

    /// set the sampler of the viewing plane
    inline void SetSampler(Sampler* sampler){ Assert(sampler); m_sampler = sampler; m_sampleCount = sampler->GetSampleCount(); }

    /// get a copy of the width of the viewing plane
    int GetWidth() const                    { return m_width; }

    /// get a copy of the height of the viewing plane
    int GetHeight() const                   { return m_height; }

    /// get the sample count per pixel
    int GetSampleCount() const              { return m_sampleCount; }

    /// get a copy of the gamma of the viewing plane
    real GetGamma() const                   { return m_gamma; }

    /// get a copy of the inverse gamma of the viewing plane
    real GetGammaInv() const                { return m_gammaInv; }

    /// get a copy of the pizel size of the viewing plane
    real GetPizelSize() const               { return m_pixelSize; }

    /// get the sampler of the viewing plane
    Sampler* GetSampler() const             { return m_sampler; }
};

#endif