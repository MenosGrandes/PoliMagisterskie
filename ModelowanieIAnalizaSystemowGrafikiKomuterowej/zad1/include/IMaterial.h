#ifndef IMATERIAL_H
#define IMATERIAL_H
#include "PointLight.h"
class IMaterial
{
public:
    IMaterial(Colour c);
        IMaterial();

    virtual ~IMaterial();

    virtual Colour radiance(PointLight pl,const Vector3Bf &hitPoint, const Vector3Bf &normal)=0;
    Colour getColor()
    {
        return m_color;
    }
    void setColor(Colour c)
    {
        m_color=c;
    }
protected:
    Colour m_color;

};

#endif // IMATERIAL_H
