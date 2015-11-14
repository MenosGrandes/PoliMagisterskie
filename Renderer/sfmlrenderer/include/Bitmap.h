#ifndef BITMAP_H
#define BITMAP_H
#include <SFML/Graphics.hpp>
#include "structs.hpp"
class Bitmap : public sf::Drawable
{
public:
    Bitmap(d_type::Bint width,d_type::Bint height);
    virtual ~Bitmap();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // You can draw other high-level objects
        target.draw(m_sprite, states);

    }
    void clear(d_type::Buint8 shade);
    void drawPixel(d_type::Buint x,d_type::Buint y,d_type::Buint8 a,d_type::Buint8 r,d_type::Buint8 g,d_type::Buint8 b);
    void swapBuffers();

d_type::Bint getWidth()
{
    return m_width;
}
d_type::Bint getHeight()
{
    return m_height;
}
protected:
        sf::Texture m_texture;
    sf::Sprite  m_sprite;
    sf::Uint8* m_pixels ;
    d_type::Bint m_width,m_height;
private:

};

#endif // BITMAP_H
