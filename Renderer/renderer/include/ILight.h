#ifndef ILIGHT_H
#define ILIGHT_H
#include "Fragment.h"

class ILight
{
    public:
    ILight();
        ILight(Vector3Bf position);
        virtual ~ILight();

Vector3Bf m_position,m_ambient,m_diffuse,m_specular;
d_type::Bfloat m_shininess;

virtual Colour calculate( const Fragment &f) const =0;
};

#endif // ILIGHT_H
