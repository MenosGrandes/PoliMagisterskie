#ifndef ILIGHT_H
#define ILIGHT_H
#include "Vector3.h"
#include "Colour.h"

class ILight
{
public:
    ILight(Colour c);
    virtual ~ILight();
    Colour getColor() const
    {
        return m_color;
    }
    void setColor(const Colour &c)
    {
        this->m_color=c;
    }
protected:
    mutable Colour m_color;

};

#endif // ILIGHT_H
