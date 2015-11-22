#include "RenderTarget.h"
RenderTarget::RenderTarget() {}
RenderTarget::RenderTarget(d_type::Bfloat width, d_type::Bfloat height)
{

//    m_pixels=new Colour[width*height];
//    m_size.x = width;
//    m_size.y = height;
//    m_dBuffer=new d_type::Bfloat[getSizePixels()];
//    for(d_type::Bint i=0; i<getSizePixels(); i++)
//    {
//        m_dBuffer[i]=100000.0f;
//
//    }
//    m_dBuffer=new d_type::Bfloat[getSizePixels()];
//    for(d_type::Bint i=0; i<getSizePixels(); i++)
//    {
//        m_dBuffer[i]=100000.0f;
//
//    }
//
//  m_pixelsUint8=new sf::Uint8[m_size.x*m_size.x*4];
//
//    for(d_type::Buint i=0; i<m_size.x; i++)
//    {
//        for(d_type::Buint j=0; j<m_size.y; j++)
//        {
//            drawPixel(i,j,255,255,255,255);
//        }
//    }
//    if(!m_texture.create(m_size.x,m_size.y))
//    {
//        std::cout<<("Texture error");
//    }
//    m_texture.update(m_pixelsUint8);
//
//    m_sprite.setTexture(m_texture);



}

RenderTarget::~RenderTarget()
{
    delete m_pixelsUint8;
}

RenderTarget::RenderTarget(Vector2Bf size):m_size(size)
{
        m_pixels=new Colour[(int)size.x*(int)size.y];

    m_dBuffer=new d_type::Bfloat[(int)getSizePixels()];
    for(d_type::Bint i=0; i<getSizePixels(); i++)
    {
        m_dBuffer[i]=100000.0f;

    }

// m_pixelsUint8=new sf::Uint8[m_size.x*m_size.x*4];
//
//    for(d_type::Buint i=0; i<m_size.x; i++)
//    {
//        for(d_type::Buint j=0; j<m_size.y; j++)
//        {
//            drawPixel(i,j,255,255,255,255);
//        }
//    }
//    if(!m_texture.create(m_size.x,m_size.y))
//    {
//        std::cout<<("Texture error");
//    }
//    m_texture.update(m_pixelsUint8);
//
//    m_sprite.setTexture(m_texture);


}


void RenderTarget::setPixel(ColorDepth colorDepth, const d_type::Bint &x, const d_type::Bint &y)
{

//std::cout<<colorDepth.depth<<" "<<m_dBuffer[convert2dto1d(x,y)]<<"\n";
    if(colorDepth.depth < m_dBuffer[convert2dto1d(x,y)])
    {
        m_pixels[convert2dto1d(x,y)] = colorDepth.color;
        m_dBuffer[convert2dto1d(x,y)]= colorDepth.depth;
//        drawPixel(x,y,colorDepth.color.r*255,colorDepth.color.g*255,colorDepth.color.b*255,colorDepth.color.a*255);
    }


}
//Convert 2d array indexing to 1d indexing
d_type::Bint RenderTarget::convert2dto1d(d_type::Bint x, d_type::Bint y)
{
    return m_size.x * y + x;
}
d_type::Bint RenderTarget::convert2dto1d(Vector2Bi size)
{
    return m_size.x * size.y + size.x;
}


void RenderTarget::setWidth(const d_type::Bfloat &width)
{
    m_size.x=width;
}

void RenderTarget::setHeight(const d_type::Bfloat &height)
{
    m_size.y=height;
}

d_type::Bfloat RenderTarget::getWidth() const
{
    return m_size.x;
}

d_type::Bfloat RenderTarget::getHeight() const
{
    return m_size.y;
}

Vector2Bf RenderTarget::getSize() const
{
    return m_size;
}
d_type::Bfloat RenderTarget::getSizePixels() const
{

    return m_size.x * m_size.y;
}

void RenderTarget::draw( render::Triangle& triangle)
{

    for(Bfloat x =triangle.rect.x; x<triangle.rect.y; x++)
    {
        for(Bfloat y=triangle.rect.z; y<triangle.rect.w; y++)
        {
            if(triangle.calculate(x,y)==true)
            {
                setPixel(triangle.calculateLambdaColor(x,y),x,y);


            }

        }


    }

}
d_type::Bfloat RenderTarget::getDepthBuffer() const
{

    for(d_type::Bint i=0; i<getSizePixels(); i++)
    {
        std::cout<<m_dBuffer[i]<<"\n";

    }
    return 0.0f;
}

void RenderTarget::drawToFile(std::string m_filename)
{
    //Error checking
    if (m_size.x <= 0 || m_size.y <= 0)
    {
        std::cout << "Image size is not set properly\n";
        return;
    }

    std::ofstream o(m_filename.c_str(), std::ios::out | std::ios::binary);

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
    o.put(((int)m_size.x  & 0x00FF));
    o.put(((int)m_size.x & 0xFF00) / 256);
    o.put(((int)m_size.y  & 0x00FF));
    o.put(((int)m_size.y  & 0xFF00) / 256);
    o.put(32);                        /* 24 bit bitmap */
    o.put(0);

    //Write the pixel data
    for (d_type::Bint i=0; i<getSizePixels() ; i++)
    {
        //std::cout<<(float)m_pixels[i].b <<" "<<(float)m_pixels[i].g<<" "<<(float)m_pixels[i].r<<" "<<(float)m_pixels[i].a<<"\n";
        o.put(m_pixels[i].b*255);
        o.put(m_pixels[i].g*255);
        o.put(m_pixels[i].r*255);
        o.put(255);
    }

    //close the file
    o.close();
}

//void RenderTarget::clear()
//{
//
//    for(d_type::Buint x=0; x<m_size.x; x++)
//        for(d_type::Buint y=0; y<m_size.y; y++)
//        {
//            setPixel(m_cleanColour,x,y);
//        }
//}


Colour RenderTarget::getCleanColour() const
{
    return m_cleanColour;
}

void RenderTarget::setCleanColour(const Colour& c)
{
    m_cleanColour=c;
}


void RenderTarget::clearPixel(const d_type::Bint& x, const d_type::Bint& y)
{
    m_pixels[convert2dto1d(x,y)] = m_cleanColour;

}


Colour * RenderTarget::getColorPixels()
{

    return m_pixels;
}


void RenderTarget::drawToFile(Colour* colors)
{
    //Error checking
    if (m_size.x <= 0 || m_size.y <= 0)
    {
        std::cout << "Image size is not set properly\n";
        return;
    }

    std::ofstream o("Wynikowy.tga", std::ios::out | std::ios::binary);

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
    o.put(((int)m_size.x  & 0x00FF));
    o.put(((int)m_size.x & 0xFF00) / 256);
    o.put(((int)m_size.y  & 0x00FF));
    o.put(((int)m_size.y  & 0xFF00) / 256);
    o.put(32);                        /* 24 bit bitmap */
    o.put(0);

    //Write the pixel data
    for (d_type::Bint i=0; i<getSizePixels() ; i++)
    {
        //std::cout<<(float)m_pixels[i].b <<" "<<(float)m_pixels[i].g<<" "<<(float)m_pixels[i].r<<" "<<(float)m_pixels[i].a<<"\n";
        o.put(colors[i].b*255);
        o.put(colors[i].g*255);
        o.put(colors[i].r*255);
        o.put(255);
    }

    //close the file
    o.close();
}

void RenderTarget::clear(d_type::Buint8 shade)
{
    for(d_type::Bsize i=0; i<m_size.x*m_size.y*4; ++i)
    {
        m_pixelsUint8[i]=shade;
    }
}
//void RenderTarget::drawPixel(d_type::Buint x,d_type::Buint y,d_type::Buint8 r,d_type::Buint8 g,d_type::Buint8 b,d_type::Buint8 a)
//{
//    d_type::Buint index=convert2dto1d(x,y)*4;
//    m_pixelsUint8[index]=r;
//    m_pixelsUint8[index+1]=g;
//    m_pixelsUint8[index+2]=b;
//    m_pixelsUint8[index+3]=a;//
//}
//void RenderTarget::swapBuffers()
//{
//    m_texture.update(m_pixelsUint8);
//
//}

