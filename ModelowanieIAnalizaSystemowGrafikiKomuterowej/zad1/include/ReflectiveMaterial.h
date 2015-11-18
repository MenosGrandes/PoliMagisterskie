#ifndef REFLECTIVEMATERIAL_H
#define REFLECTIVEMATERIAL_H

#include "PhongMaterial.h"
#include "RayTracer.h"
#include "PerfectSpecular.h"
class ReflectiveMaterial : public PhongMaterial
{
    public:
        ReflectiveMaterial():m_reflective(new PerfectSpecular()){};
        virtual ~ReflectiveMaterial();
        void setKr(const d_type::Bfloat kr)
        {
            m_reflective->setKr(kr);
        }
         virtual Colour shade(Info&info)
        {
        Colour L(PhongMaterial::shade(info)); // direct illumination

        Vector3Bf wo = -info.m_ray.getDirection();
        Vector3Bf wi= Vector3Bf(0,0,0);
        Colour fr = m_reflective->sample_f(info, wi, wo);
        Ray reflected_ray=Ray(info.m_hitPoint, wi,DIRECTION);

        L += fr * info.m_rayTracer->shadeRay(reflected_ray,info.m_depth+1)* Vector3Bf::dotProduct(info.m_normal,wi);
        return (L);

    }
    protected:
    private:
        PerfectSpecular * m_reflective;
};

#endif // REFLECTIVEMATERIAL_H
