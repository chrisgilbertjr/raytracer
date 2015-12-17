
#ifndef VIEWING_PLANE_H
#define VIEWING_PLANE_H

#include "Core\Color.h"

class ViewingPlane
{
private:
    int m_width;
    int m_height;
    real m_gamma;
    real m_gammaInv;
    real m_pixelSize;

public:
    /// default constructor
    ViewingPlane();
    
    /// constructor
    ViewingPlane(int width, int height);

    /// constructor
    ViewingPlane(int width, int height, real gamma, real pizelSize);

    /// destructor
    ~ViewingPlane();

    /// set the width of the viewing plane
    void SetWidth(int width);

    /// set the height of the viewing plane
    void SetHeight(int height);

    /// set the gamma of the viewing plane
    void SetGamma(real gamma);

    /// set the pizel size of the viewing plane
    void SetPizelSize(real pizelSize);

    /// get a copy of the width of the viewing plane
    int GetWidth() const;

    /// get a copy of the height of the viewing plane
    int GetHeight() const;

    /// get a copy of the gamma of the viewing plane
    real GetGamma() const;

    /// get a copy of the inverse gamma of the viewing plane
    real GetGammaInv() const;

    /// get a copy of the pizel size of the viewing plane
    real GetPizelSize() const;
};

#endif