#include "GlossySpecular.h"

GlossySpecular::GlossySpecular()
{
    //ctor
}

GlossySpecular::~GlossySpecular()
{
    //dtor
}
Colour GlossySpecular::f(const Info& info, const Vector3Bf& wi, const Vector3Bf& wo) const
{
    Colour L;
    d_type::Bfloat  nDOTwi = Vector3Bf::dotProduct(info.m_normal,wi);
    Vector3Bf r(-wi+2.0f*info.m_normal*nDOTwi);
    d_type::Bfloat rDOTwo=Vector3Bf::dotProduct(r,wo);
    if(rDOTwo>0.0)
    {
        L=m_ks*m_cs*pow(rDOTwo,m_exp);
    }
    return L;
}

Colour GlossySpecular::sample_f(const Info& info, Vector3Bf& wi, const Vector3Bf& wo) const
{

}

Colour GlossySpecular::rho(const Info& info, const Vector3Bf& wo) const
{
    return Colour::Black;
}
