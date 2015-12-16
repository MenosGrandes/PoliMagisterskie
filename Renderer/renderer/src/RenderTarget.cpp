#include "RenderTarget.h"
RenderTarget::RenderTarget() {}


RenderTarget::~RenderTarget()
{
}

RenderTarget::RenderTarget(Vector2Bi size):m_size(size)
{
    m_pixels=new Colour[size.x*size.y];
    m_pixelsU8=new sf::Uint8[size.x*size.y*4];
    m_dBuffer=new d_type::Bfloat[getSizePixels()];
    for(d_type::Bint i=0; i<getSizePixels(); i++)
    {
        m_dBuffer[i]=100000.0f;

    }
    for(d_type::Bint i=0; i<getSizePixels()*4; i++)
    {
        m_pixelsU8[i]=0;

    }
    if (!m_texture.create(size.x, size.y))
    {
        std::cout<<"Cannot create sf::Texture\n";
    }
    m_sprite.setTexture(m_texture);

    //m_sprite.rotate(45);

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

d_type::Bint RenderTarget::getWidth() const
{
    return m_size.x;
}

d_type::Bint RenderTarget::getHeight() const
{
    return m_size.y;
}

Vector2Bi RenderTarget::getSize() const
{
    return m_size;
}
d_type::Bint RenderTarget::getSizePixels() const
{

    return m_size.x * m_size.y;
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


void RenderTarget::triangle(Vertex3Bf a, Vertex3Bf b, Vertex3Bf c) const
{

    d_type::Bfloat minX = Min(Min(a.m_position.x, b.m_position.x), c.m_position.x);
    d_type::Bfloat maxX = Max(Max(a.m_position.x, b.m_position.x), c.m_position.x);
    d_type::Bfloat minY = Min(Min(a.m_position.y, b.m_position.y), c.m_position.y);
    d_type::Bfloat maxY = Max(Max(a.m_position.y, b.m_position.y), c.m_position.y);

    d_type::Bint minXPrim = (d_type::Bint)Max((d_type::Bint)((minX + 1) * m_size.x * 0.5f),0);
    d_type::Bint maxXPrim = (d_type::Bint)Min((d_type::Bint) ((maxX + 1) * m_size.x * 0.5f),m_size.x-1);
    d_type::Bint minYPrim = (d_type::Bint)Max((d_type::Bint) ((minY + 1) * m_size.y * 0.5f),0);
    d_type::Bint maxYPrim = (d_type::Bint)Min((d_type::Bint)((maxY + 1) * m_size.y * 0.5f),m_size.y-1);


//    minXPrim = Max(minXPrim, 0);
//    maxXPrim = Min(maxXPrim, m_size.x-1);
//    minYPrim = Max(minYPrim, 0);
//    maxYPrim = Min(maxYPrim, m_size.y-1);


    d_type::Bfloat dx12 = a.m_position.x - b.m_position.x;
    d_type::Bfloat dx23 = b.m_position.x - c.m_position.x;
    d_type::Bfloat dx31 = c.m_position.x - a.m_position.x;
    d_type::Bfloat dx13 = a.m_position.x - c.m_position.x;
    d_type::Bfloat dx32 = c.m_position.x - b.m_position.x;
    d_type::Bfloat dy12 = a.m_position.y - b.m_position.y;
    d_type::Bfloat dy23 = b.m_position.y - c.m_position.y;
    d_type::Bfloat dy31 = c.m_position.y - a.m_position.y;
    d_type::Bfloat dy13 = a.m_position.y - c.m_position.y;

    // Top - left
    d_type::BBool tl1 = false, tl2 = false, tl3 = false;
    if (dy12 < 0 || (dy12 == 0 && dx12>0))
        tl1 = true;
    if (dy23 < 0 || (dy23 == 0 && dx23>0))
        tl2 = true;
    if (dy31 < 0 || (dy31 == 0 && dx31>0))
        tl3 = true;





    for (d_type::Bint i = minXPrim; i <= maxXPrim; ++i)
    {
        const d_type::Bfloat tmpX = i / (m_size.x * 0.5f) - 1.0f;
        for (d_type::Bint j = minYPrim; j <= maxYPrim; ++j)
        {
            const d_type::Bfloat  tmpY = j / (m_size.y * 0.5f) - 1.0f;
            const d_type::Bfloat lambda1 = (dy23* (tmpX - c.m_position.x) + dx32 * (tmpY - c.m_position.y)) /
                      (dy23 *dx13 + dx32*dy13);
            const d_type::Bfloat lambda2 = (dy31* (tmpX - c.m_position.x) + dx13 * (tmpY - c.m_position.y)) /
                      (dy31 *dx23 + dx13*dy23);
            const d_type::Bfloat lambda3 = 1 - lambda1 - lambda2;

            if (
                ((tl1 && (dx12 * (tmpY - a.m_position.y) - dy12 * (tmpX - a.m_position.x) > 0.0f)) || (dx12 * (tmpY - a.m_position.y) - dy12 * (tmpX - a.m_position.x) >= 0.0f)) &&
                ((tl2 && (dx23 * (tmpY - b.m_position.y) - dy23 * (tmpX - b.m_position.x) > 0.0f)) || (dx23 * (tmpY - b.m_position.y) - dy23 * (tmpX - b.m_position.x) >= 0.0f)) &&
                ((tl3 && (dx31 * (tmpY - c.m_position.y) - dy31 * (tmpX - c.m_position.x) > 0.0f)) || (dx31 * (tmpY - c.m_position.y) - dy31 * (tmpX - c.m_position.x) >= 0.0f))
            )
            {
                 d_type::Bfloat depth = lambda1 * a.m_position.z + lambda2 * b.m_position.z + lambda3 * c.m_position.z;

/////////////////////////////////////////


/////////////////////////////////////////

                if (depth >= -1.f && depth <= 1.f && depth < m_dBuffer[m_size.x * j + i])
                {



                    m_pixels[m_size.x * j + i] = a.m_color * lambda1 + b.m_color * lambda2 + c.m_color * lambda3;
                    m_dBuffer[m_size.x * j + i]= depth;

                }
            }
        }
    }
}

void RenderTarget::swapBuffers()
{
    for(int i=getSizePixels(); i>0; --i)
    {
        const Colour c= m_pixels[i];

        m_pixelsU8[i*4]=c.r*255;
        m_pixelsU8[i*4+1]=c.g*255;
        m_pixelsU8[i*4+2]=c.b*255;
        m_pixelsU8[i*4+3]=255;


    }

    m_texture.update(m_pixelsU8);

}
void RenderTarget::clear()
{
//memset(m_pixels,getSizePixels()*sizeof(Colour));
//memset(m_dBuffer,1000,getSizePixels()*sizeof(d_type::Bfloat));
//

//for(int i=0;i<getSizePixels();i++)
//{
//    m_pixels[i]=m_cleanColour;
//    m_dBuffer[i]=10000.0f;
//}
    std::fill(m_pixels, m_pixels+getSizePixels(), m_cleanColour);
    std::fill(m_dBuffer, m_dBuffer+getSizePixels(), 100000.0f);

}
