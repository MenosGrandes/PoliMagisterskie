#ifndef IMATERIAL_H
#define IMATERIAL_H
#include "PointLight.h"
class IMaterial
{
public:
    IMaterial();
    virtual ~IMaterial();

    virtual Colour radiance(PointLight pl,const Vector3Bf &hitPoint, const Vector3Bf &normal)=0;

protected:

};

#endif // IMATERIAL_H
