#include "PerfectTransmitter.h"

PerfectTransmitter::PerfectTransmitter():m_indexOdRef(1.0f),m_transmissionCoof(0.0f)
{
    //ctor
}

PerfectTransmitter::~PerfectTransmitter()
{
    //dtor
}
Colour PerfectTransmitter::f(const Info& info, const Vector3Bf& wi, const Vector3Bf& wo) const
{
return Colour::Black;
}

Colour PerfectTransmitter::sample_f(const Info& info, const Vector3Bf& wo, Vector3Bf& wt) const
{
        Vector3Bf n(info.m_normal);
        d_type::Bfloat cos_thetai = Vector3Bf::dotProduct(n , wo);
        d_type::Bfloat eta = m_indexOdRef;

        if (cos_thetai < 0.0) {                 // transmitted ray is outside
                cos_thetai = -cos_thetai;
                n = -n;                                         // reverse direction of normal
                eta = 1.0 / eta;                        // invert ior
        }

        d_type::Bfloat temp = 1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta);
        d_type::Bfloat cos_theta2 = sqrt(temp);
        wt = -wo / eta - (cos_theta2 - cos_thetai / eta) * n;

        return (m_transmissionCoof / (eta * eta) * Colour::White / fabs(Vector3Bf::dotProduct(info.m_normal , wt)));

}

Colour PerfectTransmitter::rho(const Info& info, const Vector3Bf& wo) const
{
return Colour::Black;
}

void PerfectTransmitter::setIndexRef(const d_type::Bfloat k)
{
    m_indexOdRef=k;
}

void PerfectTransmitter::setTransmissionCoof(const d_type::Bfloat k)
{
    m_transmissionCoof=k;
}
d_type::BBool PerfectTransmitter::tir(const Info& info) const
{
        Vector3Bf wo(-info.m_ray.getDirection());
        d_type::Bfloat cos_thetai = Vector3Bf::dotProduct(info.m_normal , wo);
        d_type::Bfloat eta = m_indexOdRef;

        if (cos_thetai < 0.0)
                eta = 1.0 / eta;

        return (1.0 - (1.0 - cos_thetai * cos_thetai) / (eta * eta) < 0.0);

}
