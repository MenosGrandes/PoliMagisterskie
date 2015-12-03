#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H
#include "ILight.h"

class DirectionalLight : public ILight
{
    public:
        DirectionalLight();
        virtual ~DirectionalLight();
        DirectionalLight(Vector3Bf pos);
        virtual Colour calculate( const Fragment &f) const ;


};

#endif // DIRECTIONALLIGHT_H
