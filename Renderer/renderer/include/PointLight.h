#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include "ILight.h"

class PointLight
{
    public:
        PointLight();
        virtual ~PointLight();
virtual Vector3Bf calculate(Fragment &f) const ;

};

#endif // POINTLIGHT_H
