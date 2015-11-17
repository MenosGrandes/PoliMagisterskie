#ifndef IMAGETEXTURE_H
#define IMAGETEXTURE_H
#include "Texture.h"
#include "IMapping.h"
#include "Image.h"
class ImageTexture : public Texture
{
public:
    ImageTexture():m_image(nullptr),m_mapping(nullptr){};
        ImageTexture(Image* img,IMapping * mappi):m_image(img),hres(img->getHres()),vres(img->getVres()),m_mapping(mappi)
        {}

    virtual ~ImageTexture();
    virtual Colour getColour(const Info&info )const
    {
        d_type::Bint row,column;
        if(m_mapping!=nullptr)
        {
            //std::cout<<"~~~~~~~~~~~~~\nrow "<<row<<" column"<<column<<"\n";
             m_mapping->getTexelCoord(info.m_hitPoint,hres, vres, row, column);
            //std::cout<<"row "<<row<<" column"<<column<<"\n";

        }
        else
        {
             row=(int)(info.uv.x*(hres-1));
             column=(int)(info.uv.y*(vres-1));

        }
        if (row < 0 || column < 0 || row > vres - 1 || column > hres - 1)
        {
return (Colour::Red);

        }

            return m_image->getColour(row,column);
    }
protected:
private:
    d_type::Bint hres,vres;
    Image* m_image;
    IMapping *m_mapping;
};

#endif // IMAGETEXTURE_H
