#ifndef REFLECTIVEMATERIAL_H
#define REFLECTIVEMATERIAL_H

#include "PhongMaterial.h"
#include "RayTracer.h"
#include "PerfectSpecular.h"
class ReflectiveMaterial : public PhongMaterial
{
    public:
        ReflectiveMaterial():m_reflective(new PerfectSpecular()){m_type=MATERIAL_TYPE::REFLECTIVE;};
        virtual ~ReflectiveMaterial();
        void setKr(const d_type::Bfloat kr)
        {
            m_reflective->setKr(kr);
        }
        void setCr(const Colour & c)
        {
            //std::cout<<"SET CR"<<c<<"\n";
            m_reflective->setCr(c);
        }
          Colour shade(Info&info)
        {
        Colour L(PhongMaterial::shade(info)); // direct illumination
//std::cout<<"reflective "<<m_reflective->getCr()<<"\n";
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
