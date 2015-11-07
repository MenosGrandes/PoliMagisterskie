#include "IMaterial.h"



IMaterial::~IMaterial()
{
    //dtor
}
Colour IMaterial::shade(Info& info)
{
    return Colour::Black;
}

Colour IMaterial::areaLightShade(Info& info)
{
    return Colour::Black;
}

Colour IMaterial::pathShade(Info& info)
{
    return Colour::Black;
}
