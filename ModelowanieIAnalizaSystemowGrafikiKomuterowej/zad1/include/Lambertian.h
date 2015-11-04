#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H
#include "BRDF.h"

class Lambertian : public BRDF
{
    public:
        Lambertian();
        virtual ~Lambertian();
     Colour f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const ;
     Colour sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const;
     Colour rho(const Info& info,const Vector3Bf &wo) const ;
    private:
        d_type::Bfloat kd;
        Colour cd;
};

#endif // LAMBERTIAN_H
