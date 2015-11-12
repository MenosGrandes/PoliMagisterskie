#include "RenderTarget.h"
RenderTarget::RenderTarget() {}
RenderTarget::RenderTarget(d_type::Bshort width, d_type::Bshort height)
{
    m_size.x = width;
    m_size.y = height;
    m_pixels = new Colour[getSizePixels()];
    m_dBuffer=new d_type::Bfloat[getSizePixels()];
    for(d_type::Bint i=0; i<getSizePixels(); i++)
    {
        m_dBuffer[i]=100000.0f;

    }


}

RenderTarget::~RenderTarget()
{
    delete m_pixels;
}

RenderTarget::RenderTarget(Vector2Bs size):m_size(size)
{
    m_pixels = new Colour[getSizePixels()];
    m_dBuffer=new d_type::Bfloat[getSizePixels()];
    for(d_type::Bint i=0; i<getSizePixels(); i++)
    {
        m_dBuffer[i]=100000.0f;

    }
}
//Set all pixels at once
void RenderTarget::setAllPixels(Colour *pixels)
{
    m_pixels = pixels;
}

//Set indivdual pixels
void RenderTarget::setPixel(Colour inputcolor, const d_type::Bint &x, const d_type::Bint &y)
{
    m_pixels[convert2dto1d(x,y)] = inputcolor;
}
void RenderTarget::setPixel(ColorDepth colorDepth, const d_type::Bint &x, const d_type::Bint &y)
{

//std::cout<<colorDepth.depth<<" "<<m_dBuffer[convert2dto1d(x,y)]<<"\n";
    if(colorDepth.depth < m_dBuffer[convert2dto1d(x,y)])
    {
        m_pixels[convert2dto1d(x,y)] = colorDepth.color;
        m_dBuffer[convert2dto1d(x,y)]= colorDepth.depth;
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


void RenderTarget::setWidth(const d_type::Bshort &width)
{
    m_size.x=width;
}

void RenderTarget::setHeight(const d_type::Bshort &height)
{
    m_size.y=height;
}

d_type::Bshort RenderTarget::getWidth() const
{
    return m_size.x;
}

d_type::Bshort RenderTarget::getHeight() const
{
    return m_size.y;
}

Vector2Bs RenderTarget::getSize() const
{
    return m_size;
}
d_type::Bint RenderTarget::getSizePixels() const
{

    return m_size.x * m_size.y;
}

void RenderTarget::draw( render::TriangleFloat& triangle)
{

    for(Bfloat x =triangle.rect.x; x<triangle.rect.y; x++)
    {
        for(Bfloat y=triangle.rect.z; y<triangle.rect.w; y++)
        {
            if(triangle.calculate(x,y))
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
    o.put((m_size.x  & 0x00FF));
    o.put((m_size.x & 0xFF00) / 256);
    o.put((m_size.y  & 0x00FF));
    o.put((m_size.y  & 0xFF00) / 256);
    o.put(32);                        /* 24 bit bitmap */
    o.put(0);

    //Write the pixel data
    for (d_type::Bint i=0; i<getSizePixels() ; i++)
    {
        //std::cout<<(float)m_pixels[i].b <<" "<<(float)m_pixels[i].g<<" "<<(float)m_pixels[i].r<<" "<<(float)m_pixels[i].a<<"\n";
        o.put(m_pixels[i].b*255);
        o.put(m_pixels[i].g*255);
        o.put(m_pixels[i].r*255);
        o.put(m_pixels[i].a*255);
    }

    //close the file
    o.close();
}

void RenderTarget::clear()
{

    for(d_type::Buint x=0; x<m_size.x; x++)
        for(d_type::Buint y=0; y<m_size.y; y++)
        {
            setPixel(m_cleanColour,x,y);
        }
}


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
void RenderTarget::rewritePixelForTexture(d_type::Bubyte* pixels)
{
    for (d_type::Bint i=0; i<m_size.x*m_size.y ; i++)
    {
        d_type::Bint k=i*4;
        pixels[k+3]=m_pixels[i].a*255;
        pixels[k+2]=m_pixels[i].r*255;
        pixels[k+1]=m_pixels[i].g*255;
        pixels[k]  =m_pixels[i].b*255;

    }

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
    o.put((m_size.x  & 0x00FF));
    o.put((m_size.x & 0xFF00) / 256);
    o.put((m_size.y  & 0x00FF));
    o.put((m_size.y  & 0xFF00) / 256);
    o.put(32);                        /* 24 bit bitmap */
    o.put(0);

    //Write the pixel data
    for (d_type::Bint i=0; i<getSizePixels() ; i++)
    {
        //std::cout<<(float)m_pixels[i].b <<" "<<(float)m_pixels[i].g<<" "<<(float)m_pixels[i].r<<" "<<(float)m_pixels[i].a<<"\n";
        o.put(colors[i].b*255);
        o.put(colors[i].g*255);
        o.put(colors[i].r*255);
        o.put(colors[i].a*255);
    }

    //close the file
    o.close();
}
