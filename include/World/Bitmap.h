
#ifndef BITMAP_IMAGE_H
#define BITMAP_IMAGE_H

#include "qdbmp.h"

class Bitmap
{
private:
    BMP* m_bmp;

public:
    Bitmap();

    ~Bitmap();
};

#endif