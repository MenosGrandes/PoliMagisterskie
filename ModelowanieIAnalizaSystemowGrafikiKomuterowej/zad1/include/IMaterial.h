#ifndef IMATERIAL_H
#define IMATERIAL_H
#include "Colour.h"

class Info;
class IMaterial
{
public:

    IMaterial() {}
    ~IMaterial();

/////////////////////////////////////////////////////////
    virtual Colour shade(Info&info);
    virtual Colour areaLightShade(Info&info);
    virtual Colour pathShade(Info&info);

};

#endif // IMATERIAL_H
