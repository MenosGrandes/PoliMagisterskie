#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Colour.h"
class Image
{
public:
    Image(char * filename);
    virtual ~Image();
    Colour * getPixels()
    {
        return m_pixels;
    }
    d_type::Bint getHres() const
    {
        return hres;
    }
    d_type::Bint getVres() const
    {
        return vres;
    }

    Colour getColour(const int row, const int column) const
    {
        int index = column+(row*hres);//column + hres * (vres - row - 1);
        int pixels_size = hres*vres;

        if (index < pixels_size)
                return (m_pixels[index]);
        else
                return (Colour::Red);



}

protected:
private:
    Colour *m_pixels;
    d_type::Bint hres,vres;
};

#endif // IMAGE_H
