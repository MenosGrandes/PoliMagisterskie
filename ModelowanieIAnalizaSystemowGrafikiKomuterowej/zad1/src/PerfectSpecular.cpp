#include "PerfectSpecular.h"

PerfectSpecular::PerfectSpecular()
{
    //ctor
}

PerfectSpecular::~PerfectSpecular()
{
    //dtor
}
Colour PerfectSpecular::f(const Info& info, const Vector3Bf& wi, const Vector3Bf& wo) const
{
return (m_kr * m_cr * INV_PI);

}

Colour PerfectSpecular::sample_f(const Info& info, Vector3Bf& wi, const Vector3Bf& wo) const
{
        d_type::Bfloat ndotwo = Vector3Bf::dotProduct(info.m_normal ,wo);
        wi = -wo + 2.0d * info.m_normal * ndotwo;

//        return (m_kr * m_cr / (Vector3Bf::dotProduct(info.m_normal , wi)));
return (m_kr * m_cr / Vector3Bf::dotProduct(info.m_normal , wi));

}

Colour PerfectSpecular::rho(const Info& info, const Vector3Bf& wo) const
{
return (m_kr * m_cr);

}
