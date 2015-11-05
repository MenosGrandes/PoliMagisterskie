#include "RayTracer.h"

RayTracer::RayTracer(ICamera *camera, RenderTarget *m_target,Sampler *sampler)
    :m_camera(camera),m_renderTanger(m_target),m_sampler(sampler),m_ambientLight(new Ambient(1,Colour::Black))
{

}
RayTracer::RayTracer(ICamera *camera, RenderTarget *m_target)
    :m_camera(camera),m_renderTanger(m_target),m_ambientLight(new Ambient(1,Colour::Black))
{

}
RayTracer::RayTracer(ICamera* camera, RenderTarget* m_target, Sampler* sampler, Ambient* ambient)
:m_camera(camera),m_renderTanger(m_target),m_ambientLight(ambient)
{

}

RayTracer::~RayTracer()
{
    delete m_camera;
    delete m_renderTanger;
    delete m_sampler;
}

void RayTracer::addObject(IRaycastable* ray)
{
    m_objectVector.push_back(ray);
}

//tutaj mozna pokombinowac z watkami
void RayTracer::rayTrace()
{
    Ray ray;
    Colour finalColour=Colour::Black;

    for(Bint x=0; x<m_renderTanger->getSize().x; x++)
    {
        for(Bint y=0; y<m_renderTanger->getSize().y; y++)
        {
            finalColour=Colour::Black;
//#define ADAPTIVE_AA
#ifdef ENABLE_AA
            {

#ifdef ADAPTIVE_AA
                for(d_type::Bint i=0; i<m_; i++)
                {
                }
#else
                for(d_type::Bint i=0; i<m_sampler->getSampleCount(); i++)
                {
                    Vector2Bf sample = m_sampler->single();
                    Vector2Bf picCoord(
                        ((x+sample.x) / m_renderTanger->getSize().x)*2 -1,
                        ((y+sample.y) / m_renderTanger->getSize().y)*2 -1
                    );

                    ray=m_camera->recalculateRay(picCoord);

                    finalColour+=shadeRay(ray)/(d_type::Bfloat)m_sampler->getSampleCount();
                }
#endif // ADAPTIVE_AA
            }
#else ENABLE_AA

            {

                Vector2Bf picCoord(
                    ((x+0.5f) / m_renderTanger->getSize().x)*2 -1,
                    ((y+0.5f) / m_renderTanger->getSize().y)*2 -1
                );

                ray=m_camera->recalculateRay(picCoord);

                finalColour=shadeRay(ray);
            }
#endif // ENABLE_AA
            m_renderTanger->setPixel(Colour::clampColour(finalColour),x,y);

        }




    }
    std::cout<<"DONE\n";
}
Colour RayTracer::shadeRay(const Ray&ray)
{
    Info info = traceRay(ray);
    if(info.m_hit == false)
    {
        return Colour::RoyalBlue;
    }
    Colour finalColor = Colour::Black;
    IMaterial * material= info.m_material;
#ifdef ENABLE_LIGHT
    {

    info.ray=ray;
    finalColor=info.m_material->shade(info);

    }
#else

    {
        finalColor =(material)->m_colour;

    }
#endif

    return finalColor;
}

Info RayTracer::traceRay(const Ray&ray)
{
    d_type::Bfloat minDistance=std::numeric_limits<d_type::Bfloat>::max();
    d_type::Bfloat hitDistance=0.0f;
    Vector3Bf localHitPoint=Vector3Bf(0,0,0);
    Vector3Bf normal=Vector3Bf(0,0,0);

    Info info(Vector3Bf(0,0,0),Vector3Bf(0,0,0),false,(this));



    for(d_type::Bsize i=0; i<m_objectVector.size(); i++)
    {
        if(m_objectVector[i]->intersect(ray,hitDistance,info) && hitDistance< minDistance)
        {
            info.m_hit=true;
            normal=info.m_normal;
            minDistance=hitDistance;
            info.m_hitPoint=ray.getOrigin()+ray.getDirection()*hitDistance;
            localHitPoint=info.m_localHitPoint;
            info.m_material=m_objectVector[i]->getMaterial();
        }


    }
    if(info.m_hit)
    {
        info.m_t=minDistance;
        info.m_normal=normal;
        info.m_localHitPoint=localHitPoint;
    }
    return info;
}
void RayTracer::addLight(ILight* light)
{
    m_lightsVector.push_back(light);
}

