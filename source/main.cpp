
#include "World\World.h"

int 
main(void)
{
    int x = 64;
    int y = 64;
    ColorBuffer cb(x, y);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            cb.SetColor(i, j, Color::Red());
        }
    }
    cb.SetColor(0, 0, Color::Black());

    OutputOptions options = Options(EXPORT_BMP, "test.bmp");

    //ExportBMP(cb, options);

    while (1) {}

    return 0;
}