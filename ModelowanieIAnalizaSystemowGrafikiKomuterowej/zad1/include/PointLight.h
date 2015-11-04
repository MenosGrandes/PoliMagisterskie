#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include "ILight.h"

class PointLight:public ILight
{
    public:
        PointLight():ILight(),m_ls(0),m_colour(Colour::White),m_location(){}
        PointLight(d_type::Bfloat ls,Colour color,Vector3Bf location):ILight(),m_ls(ls),m_colour(color),m_location(location){}

        virtual ~PointLight();
         Vector3Bf getDirection(Info &info)
         {
            Vector3Bf v(m_location-info.m_hitPoint);
            Vector3Bf::normalize(v);
             return v;
         }
         Colour L(Info &info)
         {
             return (m_ls *m_colour);
         }

    d_type::Bfloat m_ls;
    Colour m_colour;
    Vector3Bf m_location;
};

#endif // POINTLIGHT_H
