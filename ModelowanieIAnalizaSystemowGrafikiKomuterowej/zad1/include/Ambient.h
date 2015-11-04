#ifndef AMBIENT_H
#define AMBIENT_H
#include "ILight.h"

class Ambient : public ILight
{
    public:
        Ambient();
        virtual ~Ambient();
         Vector3Bf getDirection(Info &info)
         {
             return Vector3Bf(0,0,0);
         }
         Colour L(Info &info)
         {
             return (m_ls *m_colour);
         }

    d_type::Bfloat m_ls;
    Colour m_colour;
};

#endif // AMBIENT_H
