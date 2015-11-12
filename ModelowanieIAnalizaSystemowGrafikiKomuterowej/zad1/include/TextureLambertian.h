#ifndef TEXTURELAMBERTIAN_H
#define TEXTURELAMBERTIAN_H
#include "BRDF.h"
#include "Texture.h"

class TextureLambertian:public BRDF
{
public:
    TextureLambertian();
    virtual ~TextureLambertian();
    virtual Colour f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const
    {
        return  m_kd*m_texture->getColour(info)*INV_PI;
    }
    virtual Colour sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const
    {

    }
    virtual Colour rho(const Info& info,const Vector3Bf &wo) const
    {
        return  m_kd*m_texture->getColour(info);
    }

    d_type::Bfloat m_kd;
    Texture * m_texture;

};

#endif // TEXTURELAMBERTIAN_H
