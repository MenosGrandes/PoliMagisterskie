#ifndef PHONGMATERIAL_H
#define PHONGMATERIAL_H
#include "IMaterial.h"
#include "Lambertian.h"
#include "GlossySpecular.h"
#include "RayTracer.h"

class PhongMaterial: public IMaterial
{
public:
    PhongMaterial():IMaterial(),m_ambient(new Lambertian()),m_diffuse(new Lambertian()),m_specular(new GlossySpecular()){}
    virtual ~PhongMaterial(){}
     void setKa(const d_type::Bfloat k )
    {
        m_ambient->m_kd=k;
    }
    void setKd(const d_type::Bfloat k )
    {
        m_diffuse->m_kd=k;
    }
    void setKs(const d_type::Bfloat k )
    {
        m_specular->m_ks=k;
    }
    void setCd(const Colour &c)
    {
        m_diffuse->m_cd=c;
        m_ambient->m_cd=c;
        m_specular->m_cs=c;
    }
    void setExponent(const d_type::Bfloat k)
    {
        m_specular->m_exp=k;
    }
    virtual Colour shade(Info&info)
    {
        Vector3Bf wo=-info.ray.getDirection();
        Colour L= m_ambient->rho(info,wo)*info.m_rayTracer->getAmbientLight()->L(info);
        const std::vector<ILight*> &lights = info.m_rayTracer->getLights();
        const d_type::Buint lightSize= lights.size();

        for(d_type::Bsize i=0; i<lightSize; ++i)
        {
            Vector3Bf wi = lights[i]->getDirection(info);
            d_type::Bfloat ndotwi=Vector3Bf::dotProduct(info.m_normal,wi);
            if(ndotwi > 0.0)
            {   d_type::BBool shadow=false;
//                if(lights[i]->castShadows())
//                {
//                    Ray shadowRay(info.m_hitPoint,wi,DIRECTION)
//                    shadow=lights[i]->inShadow(shadowRay,info);
//                }
                if(!shadow)
                {
                  L+=(m_diffuse->f(info,wo,wi)+m_specular->f(info,wo,wi))*lights[i]->L(info)*ndotwi;

                }
            }
        }
        return L;
    }
private:
    Lambertian * m_ambient;
    Lambertian *m_diffuse;
    GlossySpecular * m_specular;
};

#endif // PHONGMATERIAL_H
