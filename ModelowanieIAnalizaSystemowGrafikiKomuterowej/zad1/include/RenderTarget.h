#ifndef RENDERTARGET_H
#define RENDERTARGET_H
#include "Triangle.h"

#include <iostream>
#include <fstream>
using namespace c;


class RenderTarget
{
public:
    RenderTarget();
    RenderTarget(d_type::Bshort width, d_type::Bshort height);
    RenderTarget(Vector2Bs size);
    ~RenderTarget();
    void draw();
    void draw( TriangleFloat& drawable);
    void drawToFile( std::string m_filename);
    void clear(const Colour & color= Colour::White);

    //set Width of RenderTarget
    void setWidth(const d_type::Bshort &width);
    //set height of RenderTarget
    void setHeight(const d_type::Bshort &height);
    //get width
    d_type::Bshort getWidth() const;
    //get height
    d_type::Bshort getHeight() const;
    //get size in Vector2Bs
    Vector2Bs getSize() const;
    //get amount of pixel stored in RenderTarget
    d_type::Bint getSizePixels() const;
    //Set all pixels at once
    void setAllPixels(c::Colour *pixels);
    //set individual pixels
    void setPixel(ColorDepth colorDepth, const d_type::Bint &xposition,const  d_type::Bint &yposition);
    void setPixel(c::Colour inputcolor, const d_type::Bint &x,const  d_type::Bint &y);

d_type::Bfloat getDepthBuffer() const;




    private:
    //convert 2D to 1D indexing
    d_type::Bint convert2dto1d(d_type::Bint x, d_type::Bint y);
    d_type::Bint convert2dto1d(Vector2Bi size);

    //ColorBuffer
    c::Colour *m_pixels;
    //DepthBuffer
    d_type::Bfloat *m_dBuffer;
    //Size of pizxel table, so size of picture
    Vector2Bs m_size;




};

#endif // RENDERTARGET_H
