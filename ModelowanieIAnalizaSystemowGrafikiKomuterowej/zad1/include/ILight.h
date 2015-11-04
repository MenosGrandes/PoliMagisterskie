#ifndef ILIGHT_H
#define ILIGHT_H
#include "Vector3.h"
#include "Colour.h"
#include "Info.h"
class ILight
{
    public:
        ILight();
        virtual ~ILight();
        virtual Vector3Bf getDirection(Info &info) =0;
        virtual Colour L(Info &info) = 0 ;
    protected:
    d_type::BBool m_shadows;
};

#endif // ILIGHT_H
