#ifndef IMATERIAL_H
#define IMATERIAL_H
#include "Colour.h"

class Info;
class IMaterial
{
public:
    IMaterial(Colour c):m_colour(c){ }
    IMaterial():m_colour(Colour::White){}
    void setColor(Colour c)
    {
        m_colour=c;
    }
    virtual ~IMaterial();
    Colour m_colour;

/////////////////////////////////////////////////////////
virtual Colour shade(Info&info);
virtual Colour areaLightShade(Info&info);
virtual Colour pathShade(Info&info);

};

#endif // IMATERIAL_H
