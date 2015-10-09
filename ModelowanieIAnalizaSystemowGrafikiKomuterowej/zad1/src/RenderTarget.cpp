#include "RenderTarget.h"
RenderTarget::RenderTarget() {}
RenderTarget::RenderTarget(d_type::Bshort width, d_type::Bshort height)
{
    m_size.x = width;
    m_size.y = height;
    m_pixels = new c::Colour[getSizePixels()];
}


RenderTarget::RenderTarget(Vector2Bs size):m_size(size)
{
    m_pixels = new c::Colour[getSizePixels()];
}
//Set all pixels at once
void RenderTarget::setAllPixels(c::Colour *pixels)
{
    m_pixels = pixels;
}

//Set indivdual pixels
void RenderTarget::setPixel(c::Colour inputcolor, d_type::Bint x, d_type::Bint y)
{
    m_pixels[convert2dto1d(x,y)] = inputcolor;
}

//Convert 2d array indexing to 1d indexing
d_type::Bint RenderTarget::convert2dto1d(d_type::Bint x, d_type::Bint y)
{
    return m_size.x * x + y;
}
d_type::Bint RenderTarget::convert2dto1d(Vector2Bi size)
{
    return m_size.x * size.x + size.y;
}


void RenderTarget::setWidth(d_type::Bshort width)
{
    m_size.x=width;
}

void RenderTarget::setHeight(d_type::Bshort height)
{
    m_size.y=height;
}

d_type::Bshort RenderTarget::getWidth()
{
    return m_size.x;
}

d_type::Bshort RenderTarget::getHeight()
{
    return m_size.y;
}

Vector2Bs RenderTarget::getSize()
{
    return m_size;
}
d_type::Bint RenderTarget::getSizePixels()
{

    return m_size.x * m_size.y;
}

void RenderTarget::draw(const Drawable& drawable)
{
    //drawable.
}

void RenderTarget::clear(const Colour& color)
{

    for(d_type::Buint x=0; x<m_size.x; x++)
        for(d_type::Buint y=0; y<m_size.y; y++)
        {
            setPixel(color,x,y);
        }
}
