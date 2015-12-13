#include "FresnelReflector.h"

FresnelReflector::FresnelReflector():m_refractionIN(1.0),m_refractionOUT(1.0)
{
    //ctor
}

FresnelReflector::~FresnelReflector()
{
    //dtor
}
d_type::Bfloat FresnelReflector::fresnel(const Info& info) const
{
        Vector3Bf normal(info.m_normal);
        d_type::Bfloat ndotd = Vector3Bf::dotProduct(-normal , info.m_ray.getDirection());
        d_type::Bfloat eta;

        if (ndotd < 0.0) {
                normal = -normal;
                eta = m_refractionOUT / m_refractionIN;
        }
        else
                eta = m_refractionIN / m_refractionOUT;

        d_type::Bfloat cos_theta_i               = ndotd;
        d_type::Bfloat temp                              = 1.0 - (1.0 - cos_theta_i * cos_theta_i) / (eta * eta);
        d_type::Bfloat cos_theta_t               = sqrt (1.0 - (1.0 - cos_theta_i * cos_theta_i) / (eta * eta));
        d_type::Bfloat r_parallel                = (eta * cos_theta_i - cos_theta_t) / (eta * cos_theta_i + cos_theta_t);
        d_type::Bfloat r_perpendicular   = (cos_theta_i - eta * cos_theta_t) / (cos_theta_i + eta * cos_theta_t);
        d_type::Bfloat kr                                = 0.5 * (r_parallel * r_parallel + r_perpendicular * r_perpendicular);


        return (kr);

}

void FresnelReflector::setRefractionIN(const d_type::Bfloat in)
{
 m_refractionIN=in;
}

void FresnelReflector::setRefractionOUT(const d_type::Bfloat out)
{
m_refractionOUT=out;
}

Colour FresnelReflector::f(const Info& sr, const Vector3Bf& wi, const Vector3Bf& wo) const
{
return Colour::Black;
}

Colour FresnelReflector::sample_f(const Info& info, Vector3Bf& wr, const Vector3Bf& wo) const
{
        d_type::Bfloat ndotwo = Vector3Bf::dotProduct(info.m_normal , wo);
        wr = -wo + 2.0f * info.m_normal * ndotwo;

        return (fresnel(info) * Colour::White / fabs(Vector3Bf::dotProduct(info.m_normal , wr)));


}
Colour FresnelReflector::rho(const Info& sr, const Vector3Bf& wo) const
{
    return Colour::Black;

}

