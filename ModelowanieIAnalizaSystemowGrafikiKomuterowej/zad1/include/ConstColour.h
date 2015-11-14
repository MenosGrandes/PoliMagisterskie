#ifndef CONSTCOLOUR_H
#define CONSTCOLOUR_H
#include "Texture.h"

class ConstColour : public Texture
{
public:
    ConstColour();
    virtual ~ConstColour();
    virtual Colour getColour(const Info&info )const
    {
        return m_colour;
    }
    void setColour(Colour &c)
    {
        m_colour=c;
    }
protected:
private:
    Colour m_colour;
};

#endif // CONSTCOLOUR_H
