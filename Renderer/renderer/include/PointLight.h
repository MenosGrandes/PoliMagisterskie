#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include "ILight.h"

class PointLight:public ILight
{
    public:
        PointLight();
        virtual ~PointLight();
                PointLight(Vector3Bf pos);

virtual Colour calculate( const Fragment &f) const ;

};

#endif // POINTLIGHT_H
