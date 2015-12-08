#include "DielectricMaterial.h"

DielectricMaterial::DielectricMaterial():m_fresnelBRDF(new FresnelReflector),m_fresnelBTDF(new FresnelTransmitter),m_in(Colour::White),m_out(Colour::White)
{
    m_type=MATERIAL_TYPE::DIELECTRIC;
    //ctor
}

DielectricMaterial::~DielectricMaterial()
{
    //dtor
}
void DielectricMaterial::setKs(const d_type::Bfloat k)
{
PhongMaterial::setKs(k);
}

void DielectricMaterial::setExp(const d_type::Bfloat exponent)
{
PhongMaterial::setExponent(exponent);
}

void DielectricMaterial::setRefractionIN(const d_type::Bfloat eta)
{
m_fresnelBRDF->setRefractionIN(eta);
m_fresnelBTDF->setRefIN(eta);
}

void DielectricMaterial::setRefractionOUT(const d_type::Bfloat eta)
{
m_fresnelBRDF->setRefractionOUT(eta);
m_fresnelBTDF->setRefOUT(eta);
}

void DielectricMaterial::setCfIn(const Colour& c)
{
m_in=c;
}

void DielectricMaterial::setCfOut(const Colour& c)
{
m_out=c;
}

Colour DielectricMaterial::shade(Info& info)
{
        Colour L(PhongMaterial::shade(info));

        Vector3Bf        wi;
        Vector3Bf        wo(-info.m_ray.getDirection());
        Colour      fr = m_fresnelBRDF->sample_f(info, wi, wo);        // computes wi
        Ray             reflected_ray(info.m_hitPoint, wi,DIRECTION);
        d_type::Bfloat          t;
        Colour      Lr, Lt;
        d_type::Bfloat           ndotwi =  Vector3Bf::dotProduct(info.m_normal ,wi);

        if(m_fresnelBTDF->tir(info)) {                                                             // total internal reflection
                if (ndotwi < 0.0) {
                        // reflected ray is inside
                        Lr = info.m_rayTracer->shadeRay(reflected_ray, t, info.m_depth + 1);
                        L += m_in.powc(t) * Lr;                                                // inside filter color
                }
                else {
                        // reflected ray is outside

                        Lr = info.m_rayTracer->shadeRay(reflected_ray, t, info.m_depth + 1);   // kr = 1
                        L += m_out.powc(t) * Lr;                                       // outside filter color
                }
        }
        else {                                                                                                  // no total internal reflection
                Vector3Bf wt;
                Colour ft = m_fresnelBTDF->sample_f(info, wo, wt);     // computes wt
                Ray transmitted_ray(info.m_hitPoint, wt,DIRECTION);
                d_type::Bfloat ndotwt = Vector3Bf::dotProduct(info.m_normal , wt);

                if (ndotwi < 0.0) {
                        // reflected ray is inside

                        Lr = fr * info.m_rayTracer->shadeRay(reflected_ray, t, info.m_depth + 1) * fabs(ndotwi);
                        L +=  m_in.powc(t) * Lr;                                        // inside filter color

                        // transmitted ray is outside

                        Lt = ft * info.m_rayTracer->shadeRay(transmitted_ray, t, info.m_depth + 1) * fabs(ndotwt);
                        L += m_out.powc(t) * Lt;                                       // outside filter color
                }
                else {
                        // reflected ray is outside

                        Lr = fr * info.m_rayTracer->shadeRay(reflected_ray, t, info.m_depth + 1) * fabs(ndotwi);
                        L += m_out.powc(t) * Lr;                                               // outside filter color

                        // transmitted ray is inside

                        Lt = ft * info.m_rayTracer->shadeRay(transmitted_ray, t, info.m_depth + 1) * fabs(ndotwt);
                        L +=  m_in.powc(t) * Lt;                                                // inside filter color
                }
        }

        return (L);

}

Colour DielectricMaterial::area_light_shade(Info& sr)
{

}

Colour DielectricMaterial::path_shade(Info& sr)
{

}
