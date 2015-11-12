#ifndef TEXTUREMATTE_H
#define TEXTUREMATTE_H
#include "IMaterial.h"
#include "TextureLambertian.h"
#include "RayTracer.h"

class TextureMatte : public IMaterial
{
public:
    TextureMatte();
    virtual ~TextureMatte();
    void setCd( Texture*texture)
    {
        m_ambient->m_texture=texture;
        m_diffuse->m_texture=texture;
    }
    virtual Colour shade(Info&info)
    {
        Vector3Bf wo= -info.ray.getDirection();
        Colour L=m_ambient->rho(info,wo)*info.m_rayTracer->getAmbientLight()->L(info);
        const std::vector<ILight*> &lights = info.m_rayTracer->getLights();
        const d_type::Buint lightSize= lights.size();

        for(d_type::Bsize i=0; i<lightSize; ++i)
        {
            Vector3Bf wi = lights[i]->getDirection(info);
            //Vector3Bf::normalize(wi);
            d_type::Bfloat ndotwi=Vector3Bf::dotProduct(info.m_normal,wi);
            d_type::Bfloat ndotwo=Vector3Bf::dotProduct(info.m_normal,wo);

            if(ndotwi > 0.0&&ndotwo> 0 )
            {
                L+=m_diffuse->f(info,wo,wi)*lights[i]->L(info)*ndotwi;
            }
        }

    }
private :
    TextureLambertian * m_diffuse;
    TextureLambertian * m_ambient;

};

#endif // TEXTUREMATTE_H
