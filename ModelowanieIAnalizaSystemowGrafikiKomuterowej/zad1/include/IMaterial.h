#ifndef IMATERIAL_H
#define IMATERIAL_H
#include "Colour.h"
enum MATERIAL_TYPE
{
    MATTE,PHONG,REFLECTIVE,TRANSPARENT,DIELECTRIC,TEXTURE_MATT,TEXTURE_PHONG
};
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
MATERIAL_TYPE m_type;
};

#endif // IMATERIAL_H
