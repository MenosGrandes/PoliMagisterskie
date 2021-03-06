#ifndef MATTEMATERIAL_H
#define MATTEMATERIAL_H
#include "IMaterial.h"
#include "Lambertian.h"
#include "RayTracer.h"
class MatteMaterial : public IMaterial
{
public:
    MatteMaterial():IMaterial(),m_ambient(new Lambertian()),m_diffuse(new Lambertian()) {m_type=MATERIAL_TYPE::MATTE;}
    virtual ~MatteMaterial();
    void setKa(const d_type::Bfloat k )
    {
        m_ambient->m_kd=k;
    }
    void setKd(const d_type::Bfloat k )
    {
        m_diffuse->m_kd=k;
    }
    void setCd(const Colour &c)
    {
        m_diffuse->m_cd=c;
        m_ambient->m_cd=c;
    }
    virtual Colour shade(Info&info)
    {
        Vector3Bf wo= -info.m_ray.getDirection();
        Colour L=m_ambient->rho(info,wo)*info.m_rayTracer->getAmbientLight()->L(info);
        const std::vector<ILight*> &lights = info.m_rayTracer->getLights();
        const d_type::Buint lightSize= lights.size();

        for(d_type::Bsize i=0; i<lightSize; ++i)
        {
            Vector3Bf wi = lights[i]->getDirection(info);
            d_type::Bfloat ndotwi=Vector3Bf::dotProduct(info.m_normal,wi);
            if(ndotwi > 0.0)
            {
                d_type::BBool shadow=false;
                if(lights[i]->castShadows())
                {
                    Ray shadowRay(info.m_hitPoint,wi,DIRECTION);
                    shadow=lights[i]->inShadow(shadowRay,info);
                }
                if(!shadow)
                {
                    L+=m_diffuse->f(info,wo,wi)*lights[i]->L(info)*ndotwi;
                }
            }
        }
        return L;
    };
    Lambertian * m_ambient;
    Lambertian * m_diffuse;
};

#endif // MATTEMATERIAL_H
