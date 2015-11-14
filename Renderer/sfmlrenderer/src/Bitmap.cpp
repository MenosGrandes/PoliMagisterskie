#include "Bitmap.h"

Bitmap::Bitmap(d_type::Bint width,d_type::Bint height):m_width(width),m_height(height)
{
    m_pixels=new sf::Uint8[m_width*m_height*4];

    for(d_type::Buint i=0; i<m_width; i++)
    {
        for(d_type::Buint j=0; j<m_height; j++)
        {
            drawPixel(i,j,255,255,255,255);
        }
    }
    if(!m_texture.create(m_width,m_height))
    {
        std::cout<<("Texture error");
    }
    m_texture.update(m_pixels);

    m_sprite.setTexture(m_texture);
}

Bitmap::~Bitmap()
{
    delete [] m_pixels;
}
void Bitmap::clear(d_type::Buint8 shade)
{
    for(d_type::Bsize i=0; i<m_width*m_height*4; ++i)
    {
        m_pixels[i]=shade;
    }
}
void Bitmap::drawPixel(d_type::Buint x,d_type::Buint y,d_type::Buint8 r,d_type::Buint8 g,d_type::Buint8 b,d_type::Buint8 a)
{
    d_type::Buint index=(y*m_width+x)*4;
    m_pixels[index]=r;
    m_pixels[index+1]=g;
    m_pixels[index+2]=b;
    m_pixels[index+3]=a;//
}
void Bitmap::swapBuffers()
{
    m_texture.update(m_pixels);
}
