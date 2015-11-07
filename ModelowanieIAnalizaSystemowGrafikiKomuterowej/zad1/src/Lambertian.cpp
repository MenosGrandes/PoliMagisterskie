#include "Lambertian.h"

Colour Lambertian::f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const
{
    return (kd*cd*INV_PI);
}
Colour Lambertian::sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const
{

//    Vector3D w = sr.normal;
//    Vector3D v = Vector3D(0.0034, 1, 0.0071) ^ w;
//    v.normalize();
//    Vector3D u = v ^ w;
//
//    Point3D sp = sampler_ptr->sample_hemisphere();
//    wi = sp.x * u + sp.y * v + sp.z * w;
//    wi.normalize();
//
//    pdf = sr.normal * wi * invPI;
//
//    return (kd * cd * invPI);
}
Colour Lambertian::rho(const Info& info,const Vector3Bf &wo) const
{
    return (kd*cd);
}

Lambertian::Lambertian()
{

}

Lambertian::~Lambertian()
{

}
