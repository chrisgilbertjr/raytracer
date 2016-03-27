
#ifndef VIEWING_PLANE_H
#define VIEWING_PLANE_H

#include "..\Samplers\Sampler.h"
#include "Core\Color.h"

/// @defgroup ViewingPlane ViewingPlane
/// @{

/// viewing plane used for rendering
class ViewingPlane
{
private:
    int m_width;        /// width of the viewing plane
    int m_height;       /// height of the viewing plane
    int m_sampleCount;  /// number of samples per pixel
    int m_maxDepth;     /// maximum number of recursive rays to trace
    real m_gamma;       /// gamma of the viewing plane
    real m_gammaInv;    /// inverse gamma of the viewing plane
    real m_pixelSize;   /// pixel size of the viewing plane
    Sampler* m_sampler; /// sampler pointer

public:
    /// default constructor
    ViewingPlane(int samples = 1);

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

    /// set the width of the viewing plane
    void SetWidth(const int width);

    /// set the height of the viewing plane
    void SetHeight(const int height);

    /// set the samples per pixel
    void SetSampleCount(const int samples);

    /// set the number of recursive rays to trace
    void SetMaxDepth(const int depth);

    /// set the gamma of the viewing plane
    void SetGamma(const real gamma);

    /// set the pizel size of the viewing plane
    void SetPixelSize(const real pixelSize);

    /// set the sampler of the viewing plane
    inline void SetSampler(Sampler* sampler);

    /// get a copy of the width of the viewing plane
    int GetWidth() const;

    /// get a copy of the height of the viewing plane
    int GetHeight() const;

    /// get the sample count per pixel
    int GetSampleCount() const;

    /// get the max depth of recursive rays to trace
    int GetMaxDepth() const;

    /// get a copy of the gamma of the viewing plane
    real GetGamma() const;

    /// get a copy of the inverse gamma of the viewing plane
    real GetGammaInv() const;

    /// get a copy of the pizel size of the viewing plane
    real GetPizelSize() const;

    /// get the sampler of the viewing plane
    Sampler* GetSampler() const;
};

/// --------------------------------------------------------------------------- SetWidth

inline void 
ViewingPlane::SetWidth(const int width)          
{ 
    m_width = width; 
}

/// --------------------------------------------------------------------------- SetHeight

inline void 
ViewingPlane::SetHeight(const int height)        
{ 
    m_height = height; 
}

/// --------------------------------------------------------------------------- SetSampleCount

inline void 
ViewingPlane::SetSampleCount(const int samples)  
{
    m_sampleCount = samples; 
}

/// --------------------------------------------------------------------------- SetMaxDepth

inline void 
ViewingPlane::SetMaxDepth(const int depth)       
{ 
    m_maxDepth = depth; 
}

/// --------------------------------------------------------------------------- SetGamma

inline void 
ViewingPlane::SetGamma(const real gamma)         
{ 
    m_gamma = gamma; m_gammaInv = (gamma > 0.f) ? (1.f / gamma) : (0.f); 
}

/// --------------------------------------------------------------------------- SetPixelSize

inline void
ViewingPlane::SetPixelSize(const real pixelSize) 
{ 
    m_pixelSize = pixelSize; 
}

/// --------------------------------------------------------------------------- SetSampler

inline void 
ViewingPlane::SetSampler(Sampler* sampler)
{ 
    Assert(sampler); m_sampler = sampler; m_sampleCount = sampler->GetSampleCount(); 
}

/// --------------------------------------------------------------------------- GetWidth

inline int 
ViewingPlane::GetWidth() const                    
{ 
    return m_width; 
}

/// --------------------------------------------------------------------------- GetHeight

inline int 
ViewingPlane::GetHeight() const                   
{ 
    return m_height; 
}

/// --------------------------------------------------------------------------- GetSampleCount

inline int 
ViewingPlane::GetSampleCount() const              
{ 
    return m_sampleCount; 
}

/// --------------------------------------------------------------------------- GetMaxDepth

inline int 
ViewingPlane::GetMaxDepth() const                 
{ 
    return m_maxDepth; 
}

/// --------------------------------------------------------------------------- GetGamma

inline real 
ViewingPlane::GetGamma() const                   
{ 
    return m_gamma; 
}

/// --------------------------------------------------------------------------- GetGammaInv

inline real 
ViewingPlane::GetGammaInv() const                
{ 
    return m_gammaInv; 
}

/// --------------------------------------------------------------------------- GetPixelSize

inline real 
ViewingPlane::GetPizelSize() const               
{ 
    return m_pixelSize; 
}

/// --------------------------------------------------------------------------- GetSampler

inline Sampler* 
ViewingPlane::GetSampler() const             
{ 
    return m_sampler; 
}

/// --------------------------------------------------------------------------- EOF

/// @{

#endif