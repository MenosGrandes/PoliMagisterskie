#include "Image.h"




//Default Constructor
TGAImage::TGAImage():RenderTarget()
{

}
TGAImage::TGAImage(d_type::Bshort width, d_type::Bshort height, std::string filename):RenderTarget(width,height),m_filename(filename)
{
}


TGAImage::TGAImage(Vector2Bs size, std::string filename):RenderTarget(size),m_filename(filename)
{

}
void TGAImage::draw(const Drawable & drawable)
{
 std::cout<<"TGATargetDrawDrawable\n";
drawable.draw(*this);


}
           void TGAImage::draw(const Vertex2<d_type::Bfloat>*,d_type::Bsize vertexCount,PrimitiveType type)
           {
 std::cout<<"TGATargetDrawVertex\n";

           }

void TGAImage::draw()
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
        o.put(m_pixels[i].b);
        o.put(m_pixels[i].g);
        o.put(m_pixels[i].r);
        o.put(m_pixels[i].a);
    }

    //close the file
    o.close();

}
