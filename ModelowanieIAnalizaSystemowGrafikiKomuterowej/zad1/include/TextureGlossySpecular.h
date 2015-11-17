#ifndef TEXTUREGLOSSYSPECULAR_H
#define TEXTUREGLOSSYSPECULAR_H
#include "Texture.h"
#include "BRDF.h"

class TextureGlossySpecular : public BRDF
{
public:
    TextureGlossySpecular():BRDF() {}
    virtual ~TextureGlossySpecular();
    virtual Colour f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const ;
    virtual Colour sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const;
    virtual Colour rho(const Info& info,const Vector3Bf &wo) const ;

    d_type::Bfloat m_ks,m_exp;
    Texture* m_cs;
};

#endif // TEXTUREGLOSSYSPECULAR_H
