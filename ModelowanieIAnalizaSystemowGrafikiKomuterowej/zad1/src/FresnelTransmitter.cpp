#include "FresnelTransmitter.h"

FresnelTransmitter::FresnelTransmitter():m_refractionIN(1.0f),m_refractionOUT(1.0f)
{
    //ctor
}

FresnelTransmitter::~FresnelTransmitter()
{
    //dtor
}
void FresnelTransmitter::setRefIN(d_type::Bfloat k)
{
    this->m_refractionIN=k;
}

void FresnelTransmitter::setRefOUT(d_type::Bfloat k)
{
    this->m_refractionOUT=k;
}

Colour FresnelTransmitter::f(const Info& info, const Vector3Bf& wi, const Vector3Bf& wo) const
{
    return Colour::Black;
}

Colour FresnelTransmitter::sample_f(const Info& info, const Vector3Bf& wo, Vector3Bf& wt) const
{

        Vector3Bf n(info.m_normal);
        d_type::Bfloat cos_thetai = Vector3Bf::dotProduct(n , wo);
        d_type::Bfloat eta;// = ior;

        if (cos_thetai < 0.0) {                 // transmitted ray is outside
                cos_thetai = -cos_thetai;
                n = -n;                                         // reverse direction of normal
                eta = m_refractionOUT / m_refractionIN;
                //eta = 1.0 / eta;                      // invert ior
        }
        else
                eta = m_refractionIN / m_refractionOUT;

        d_type::Bfloat temp = 1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta);
        d_type::Bfloat cos_theta2 = sqrt(temp);
        wt = -wo / eta - (cos_theta2 - cos_thetai / eta) * n;

        //return (kt / (eta * eta) * white / fabs(sr.normal * wt));
        // fresnel(sr) returns kr, kt = 1 - kr per conservation of energy
        return ((1 - fresnel(info)) / (eta * eta)  * Colour::White / fabs(Vector3Bf::dotProduct(info.m_normal , wt)));




}

Colour FresnelTransmitter::rho(const Info& info, const Vector3Bf& wo) const
{
    return Colour::Black;
}

d_type::BBool FresnelTransmitter::tir(const Info& info) const
{

    Vector3Bf wo(-info.m_ray.getDirection());
    d_type::Bfloat cos_thetai = Vector3Bf::dotProduct(info.m_normal ,wo);
    d_type::Bfloat eta;

    if (cos_thetai < 0.0)                   // transmitted ray is outside
    {
                                      // reverse direction of normal
        eta = m_refractionOUT / m_refractionIN;
    }
    else
    {
        eta = m_refractionIN / m_refractionOUT;
    }

    return (1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta) < 0.0);



}

d_type::Bfloat FresnelTransmitter::fresnel(const Info& info) const
{
        Vector3Bf normal=Vector3Bf(info.m_normal);
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
