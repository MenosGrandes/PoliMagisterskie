#ifndef AMBIENT_H
#define AMBIENT_H
#include "ILight.h"

class Ambient : public ILight
{
public:
    Ambient():ILight(),m_ls(1.0f),m_colour(Colour::White) {}
    Ambient(d_type::Bfloat ls,Colour c):ILight(),m_ls(ls),m_colour(c) {}

    ~Ambient()
    {

    }
    Vector3Bf getDirection(Info &info)
    {
        return Vector3Bf(0,0,0);
    }
    Colour L(Info &info)
    {
        return (m_ls *m_colour);
    }
        virtual d_type::BBool inShadow(const Ray&ray, const Info&info)
        {

        }
    d_type::Bfloat m_ls;
    Colour m_colour;
};

#endif // AMBIENT_H
