#include "TransparentMaterial.h"

TransparentMaterial::TransparentMaterial():m_transmitter(new PerfectTransmitter()),m_specular(new PerfectSpecular())
{
    //ctor
}

TransparentMaterial::~TransparentMaterial()
{
    //dtor
}
void TransparentMaterial::setExp(const d_type::Bfloat ks)
{
    PhongMaterial::setExponent(ks);
}

void TransparentMaterial::setCr(const Colour& c)
{
m_specular->setCr(c);
}

void TransparentMaterial::setIndexRef(const d_type::Bfloat k)
{
m_transmitter->setIndexRef(k);
}

void TransparentMaterial::setTransmissionCoof(const d_type::Bfloat k)
{
m_transmitter->setTransmissionCoof(k);
}

Colour TransparentMaterial::shade(Info& info)
{
        Colour L(PhongMaterial::shade(info));

        Vector3Bf wo = -info.m_ray.getDirection();
        Vector3Bf wi;
        Colour fr = m_specular->sample_f(info, wi, wo);
        Ray reflected_ray(info.m_hitPoint, wi,DIRECTION);

        if(m_transmitter->tir(info))
               {
                   L += info.m_rayTracer->shadeRay(reflected_ray, info.m_depth +1);
               }
        else {
                Vector3Bf wt;
                Colour ft = m_transmitter->sample_f(info, wo, wt);
                Ray transmitted_ray(info.m_hitPoint, wt,DIRECTION);

                L += fr * info.m_rayTracer->shadeRay(reflected_ray, info.m_depth +1) * fabs(Vector3Bf::dotProduct(info.m_normal , wi));
                L += ft * info.m_rayTracer->shadeRay(transmitted_ray, info.m_depth +1) * fabs(Vector3Bf::dotProduct(info.m_normal ,wt));
        }

        return (L);


}

void TransparentMaterial::setKs(const d_type::Bfloat k)
{
PhongMaterial::setKs(k);
}


void TransparentMaterial::setKr(const d_type::Bfloat k)
{
    m_specular->setKr(k);
}
