#ifndef IMAGETEXTURE_H
#define IMAGETEXTURE_H
#include "Texture.h"
#include "IMapping.h"
#include "Image.h"
class ImageTexture : public Texture
{
    public:
        ImageTexture();
        virtual ~ImageTexture();
        virtual Colour getColour(const Info&info )const
        {
            d_type::Buint row,column;
            if(m_mapping)
            {
               // m_mapping->getTexelCoord(info.m_localHitPoint,m_width,m_height,row,column);
            }
            else
            {
               // row=(int)(info.m_textCoord.x*(m_height-1));
                // column=(int)(info.m_textCoord.y*(m_width-1));

            }
//            return m_image->getColour(row,column);
        }
    protected:
    private:
        d_type::Buint m_width,m_height;
        Image* m_image;
        IMapping *m_mapping;
};

#endif // IMAGETEXTURE_H
