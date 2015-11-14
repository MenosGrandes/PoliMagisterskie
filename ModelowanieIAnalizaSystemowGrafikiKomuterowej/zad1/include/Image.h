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
protected:
private:
    Colour *m_pixels;
};

#endif // IMAGE_H
