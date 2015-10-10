#ifndef RENDERTARGET_H
#define RENDERTARGET_H
#include "PrimitiveType.h"
#include "Colour.h"
#include "Vector2.h"
#include "Drawable.h"
using namespace c;

class Drawable;
class RenderTarget
{
    public:
        RenderTarget();


        void draw(const Drawable& drawable);
        void clear(const Colour & color= Colour::White);

    //set Width of RenderTarget
    void setWidth(d_type::Bshort width);
     //set height of RenderTarget
    void setHeight(d_type::Bshort height);
    //get width
    d_type::Bshort getWidth();
    //get height
    d_type::Bshort getHeight();
    //get size in Vector2Bs
    Vector2Bs getSize();
    //get amount of pixel stored in RenderTarget
    d_type::Bint getSizePixels();
    //Set all pixels at once
    void setAllPixels(c::Colour *pixels);
    //set individual pixels
    void setPixel(c::Colour inputcolor, d_type::Bint xposition, d_type::Bint yposition);



    protected:
        RenderTarget(d_type::Bshort width, d_type::Bshort height);
        RenderTarget(Vector2Bs size);
        //convert 2D to 1D indexing
    d_type::Bint convert2dto1d(d_type::Bint x, d_type::Bint y);
    d_type::Bint convert2dto1d(Vector2Bi size);

      //All pizels
    c::Colour *m_pixels;
    //Size of pizxel table, so size of picture
    Vector2Bs m_size;

    private:

};

#endif // RENDERTARGET_H
