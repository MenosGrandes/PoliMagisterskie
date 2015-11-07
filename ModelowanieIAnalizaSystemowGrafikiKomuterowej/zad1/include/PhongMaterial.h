#ifndef PHONGMATERIAL_H
#define PHONGMATERIAL_H
#include "IMaterial.h"
#include "Lambertian.h"
#include "GlossySpecular.h"
#include "RayTracer.h"

class PhongMaterial: public IMaterial
{
public:
    PhongMaterial();
    virtual ~PhongMaterial();
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
            {
                L+=(m_diffuse->f(info,wo,wi)+m_specular->f(info,wi,wo))*lights[i]->L(info)*ndotwi;
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
