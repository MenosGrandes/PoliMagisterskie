#ifndef IMATERIAL_H
#define IMATERIAL_H
#include "Colour.h"

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
};

#endif // IMATERIAL_H
