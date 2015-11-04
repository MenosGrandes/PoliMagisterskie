#include "Lambertian.h"

     Colour Lambertian::f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const
     {
        return (kd*cd*INV_PI);
     }
     Colour Lambertian::sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const
     {

     }
     Colour Lambertian::rho(const Info& info,const Vector3Bf &wo) const
     {
            return (kd*cd);
     }

