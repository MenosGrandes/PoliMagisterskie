#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include "ILight.h"

class PointLight : public ILight
{
    public:
        PointLight();
         Vector3Bf getDirection(Info &info)
         {
             Vector3Bf v(m_location-info.m_hitPoint);
             Vector3Bf::normalize(v);
             return v;
         }
         Colour L(Info &info)
         {
             return(m_ls*m_colour);
         }
        virtual ~PointLight();

d_type::Bfloat m_ls;
Colour m_colour;
Vector3Bf m_location;
};

#endif // POINTLIGHT_H
