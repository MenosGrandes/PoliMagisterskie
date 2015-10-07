#ifndef __IMAGE_SAVER__
#define __IMAGE_SAVER__

//includes
#include <string>
#include <fstream>
#include <iostream>
#include "structs.hpp"

//data structures


class TGAImage
{

public:

    //Constructor
    TGAImage();

    //Overridden Constructor
    TGAImage(d_type::Bshort width, d_type::Bshort height);

    TGAImage(d_type::Vector2Bs size);

    //Set all pixels at once
    void setAllPixels(d_type::c::Colour *pixels);

    //set individual pixels
    void setPixel(d_type::c::Colour inputcolor, d_type::Bint xposition, d_type::Bint yposition);

    void WriteImage(std::string filename);

//General getters and setters

    void setWidth(d_type::Bshort width);
    void setHeight(d_type::Bshort height);

    d_type::Bshort getWidth();
    d_type::Bshort getHeight();
    d_type::Vector2Bs getSize();
    d_type::Bint getSizePixels();
private:

    //store the pixels
    d_type::c::Colour *m_pixels;
    d_type::Vector2Bs m_size;


    //convert 2D to 1D indexing
    d_type::Bint convert2dto1d(d_type::Bint x, d_type::Bint y);
    d_type::Bint convert2dto1d(d_type::Vector2Bi size);



};


#endif
