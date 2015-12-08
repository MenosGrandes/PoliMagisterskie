#ifndef TEXTUREPHONG_H
#define TEXTUREPHONG_H

#include "IMaterial.h"
#include "TextureLambertian.h"
#include "GlossySpecular.h"
#include "RayTracer.h"
class TexturePhong : public IMaterial
{
    public:
    TexturePhong():IMaterial(),m_ambient(new TextureLambertian()),m_diffuse(new TextureLambertian()),m_specular(new GlossySpecular()) {m_type=MATERIAL_TYPE::TEXTURE_PHONG;}
    virtual ~TexturePhong() {}
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
    void setCd(Texture*texture)
    {
        m_diffuse->m_texture=texture;
        m_ambient->m_texture=texture;

    }
    void setCs(const Colour &c)
    {
        m_specular->m_cs=c;
    }
    void setExponent(const d_type::Bfloat k)
    {
        m_specular->m_exp=k;
    }
    virtual Colour shade(Info&info)
    {
        Vector3Bf wo=-info.m_ray.getDirection();
        Colour L= m_ambient->rho(info,wo)*info.m_rayTracer->getAmbientLight()->L(info);
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
                    L+=(m_diffuse->f(info,wo,wi)+m_specular->f(info,wo,wi))*lights[i]->L(info)*ndotwi;

                }
            }
        }
        return L;
    }
private:
    TextureLambertian * m_ambient;
    TextureLambertian *m_diffuse;
    GlossySpecular * m_specular;
};

#endif // TEXTUREPHONG_H
