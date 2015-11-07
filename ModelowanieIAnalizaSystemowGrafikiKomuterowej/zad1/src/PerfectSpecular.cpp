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
    return Colour::Black;
}

Colour PerfectSpecular::sample_f(const Info& info, Vector3Bf& wi, const Vector3Bf& wo) const
{

}

Colour PerfectSpecular::rho(const Info& info, const Vector3Bf& wo) const
{
    return Colour::Black;
}
