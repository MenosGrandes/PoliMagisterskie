#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H
#include "BRDF.h"

class Lambertian : public BRDF
{
public:
    Lambertian();
    virtual ~Lambertian();
    virtual Colour f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const ;
    virtual Colour sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const;
    virtual Colour rho(const Info& info,const Vector3Bf &wo) const ;

    d_type::Bfloat m_kd;
    Colour m_cd;
};

#endif // LAMBERTIAN_H
