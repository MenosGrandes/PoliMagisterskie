#include "Image.h"

//Default Constructor
TGAImage::TGAImage()
{

}

//Overridden Constructor
TGAImage::TGAImage(d_type::Bshort width, d_type::Bshort height)
{
    m_size.x = width;
    m_size.y = height;
    m_pixels = new d_type::c::Colour[getSizePixels()];
}
TGAImage::TGAImage(d_type::Vector2Bs size)
{
    m_size=size;

    m_pixels = new d_type::c::Colour[getSizePixels()];
}
//Set all pixels at once
void TGAImage::setAllPixels(d_type::c::Colour *pixels)
{
    m_pixels = pixels;
}

//Set indivdual pixels
void TGAImage::setPixel(d_type::c::Colour inputcolor, d_type::Bint x, d_type::Bint y)
{
    m_pixels[convert2dto1d(x,y)] = inputcolor;
}

//Convert 2d array indexing to 1d indexing
d_type::Bint TGAImage::convert2dto1d(d_type::Bint x, d_type::Bint y)
{
    return m_size.x * x + y;
}
d_type::Bint TGAImage::convert2dto1d(d_type::Vector2Bi size)
{
    return m_size.x * size.x + size.y;
}


void TGAImage::setWidth(d_type::Bshort width)
{
    m_size.x=width;
}

void TGAImage::setHeight(d_type::Bshort height)
{
    m_size.y=height;
}

d_type::Bshort TGAImage::getWidth()
{
    return m_size.x;
}

d_type::Bshort TGAImage::getHeight()
{
    return m_size.y;
}

d_type::Vector2Bs TGAImage::getSize()
{
    return m_size;
}
d_type::Bint TGAImage::getSizePixels()
{

    return m_size.x * m_size.y;
}

void TGAImage::WriteImage(std::string filename)
{

    //Error checking
    if (m_size.x <= 0 || m_size.y <= 0)
    {
        std::cout << "Image size is not set properly\n";
        return;
    }

    std::ofstream o(filename.c_str(), std::ios::out | std::ios::binary);

    //Write the header
    o.put(0);
    o.put(0);
    o.put(2);                         /* uncompressed RGB */
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);
    o.put(0);           /* X origin */
    o.put(0);
    o.put(0);           /* y origin */
    o.put((m_size.x  & 0x00FF));
    o.put((m_size.x & 0xFF00) / 256);
    o.put((m_size.y  & 0x00FF));
    o.put((m_size.y  & 0xFF00) / 256);
    o.put(32);                        /* 24 bit bitmap */
    o.put(0);

    //Write the pixel data
    for (d_type::Bint i=0; i<getSizePixels() ; i++)
    {
        o.put(m_pixels[i].b);
        o.put(m_pixels[i].g);
        o.put(m_pixels[i].r);
        o.put(m_pixels[i].a);
    }

    //close the file
    o.close();

}
