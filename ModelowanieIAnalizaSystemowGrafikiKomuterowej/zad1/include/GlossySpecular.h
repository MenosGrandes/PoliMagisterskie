#ifndef GLOSSYSPECULAR_H
#define GLOSSYSPECULAR_H
#include "BRDF.h"
#include "Sampler.h"
#include "Colour.h"
class GlossySpecular : public BRDF
{
public:
    GlossySpecular():BRDF(),m_ks(1.0f),m_exp(1.0f),m_cs(Colour::White) {}
    virtual ~GlossySpecular();
    virtual Colour f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const ;
    virtual Colour sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const;
    virtual Colour rho(const Info& info,const Vector3Bf &wo) const ;

    d_type::Bfloat m_ks,m_exp;
    Colour m_cs;
};

#endif // GLOSSYSPECULAR_H
