#ifndef RENDERTARGET_H
#define RENDERTARGET_H

#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Vertex3.h"

class RenderTarget : public sf::Drawable
{
public:
    RenderTarget();
    RenderTarget(Vector2Bi size);
    ~RenderTarget();
    void draw();
    void drawToFile( std::string m_filename);
    void clear();

    //set Width of RenderTarget
    void setWidth(const d_type::Bfloat &width);
    //set height of RenderTarget
    void setHeight(const d_type::Bfloat &height);
    //get width
    d_type::Bint getWidth() const;
    //get height
    d_type::Bint getHeight() const;
    //get size in Vector2Bs
    Vector2Bi getSize() const;
    //get amount of pixel stored in RenderTarget
    d_type::Bint getSizePixels() const;
    //Set all pixels at once
    void setAllPixels(Colour *pixels);
    //set individual pixels
    void setPixel(ColorDepth colorDepth, const d_type::Bint &xposition,const  d_type::Bint &yposition);
    void setPixel(Colour inputcolor, const d_type::Bint &x,const  d_type::Bint &y);

    d_type::Bfloat getDepthBuffer() const;
    Colour getCleanColour() const;
    void setCleanColour(const Colour&c);
    void clearPixel(const d_type::Bint &x,const  d_type::Bint &y);
    Colour * getColorPixels();
    void rewritePixelForTexture(d_type::Bubyte * pixels);
    void drawToFile(Colour * colors);



    void triangle(Vertex3Bf a,Vertex3Bf b,Vertex3Bf c);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
        target.draw(m_sprite, states);

    }
    void clear(d_type::Buint8 shade);
    void drawPixel(d_type::Buint x,d_type::Buint y,d_type::Buint8 a,d_type::Buint8 r,d_type::Buint8 g,d_type::Buint8 b);
    void swapBuffers();
    sf::Sprite  m_sprite;


private:
    //convert 2D to 1D indexing
    d_type::Bint convert2dto1d(d_type::Bint x, d_type::Bint y);
    d_type::Bint convert2dto1d(Vector2Bi size);

    //ColorBuffer
    Colour *m_pixels;
    //DepthBuffer
    d_type::Bfloat *m_dBuffer;
    //Size of pizxel table, so size of picture
    Vector2Bi m_size;

    Colour m_cleanColour;

    sf::Texture m_texture;
    sf::Uint8 *m_pixelsU8;
    d_type::Bint m_width,m_height;
};

#endif // RENDERTARGET_H
