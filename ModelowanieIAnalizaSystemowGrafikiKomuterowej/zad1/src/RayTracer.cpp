#include "RayTracer.h"

RayTracer::RayTracer(ICamera *camera, RenderTarget *m_target,Sampler *sampler)
    :m_camera(camera),m_renderTanger(m_target),m_sampler(sampler)
{

}
RayTracer::RayTracer(ICamera *camera, RenderTarget *m_target)
    :m_camera(camera),m_renderTanger(m_target)
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
    if(info.m_object == nullptr)
    {
        return Colour::RoyalBlue;
    }
    Colour finalColor = Colour::Black;
//    IMaterial * material= info.m_object->getMaterial();
#ifdef ENABLE_LIGHT
    {


        for(d_type::Bsize i =0; i<m_pLightsVector.size(); i++)
        {
            finalColor=material->radiance(m_pLightsVector[i],info.hitPoint,info.normal)+finalColor;
        }
    }
#else

    {
//        finalColor =static_cast<PerfectDifuse*>(material)->getColor();

    }
#endif

    return finalColor;
}

Info RayTracer::traceRay(const Ray&ray)
{
    d_type::Bfloat minDistance=std::numeric_limits<d_type::Bfloat>::max();
    d_type::Bfloat hitDistance=0.0f;
    Vector3Bf normal=Vector3Bf(0,0,0);
    Info info(nullptr,Vector3Bf(0,0,0),Vector3Bf(0,0,0),false);



    for(d_type::Bsize i=0; i<m_objectVector.size(); i++)
    {
        if(m_objectVector[i]->intersect(ray,hitDistance,normal) && hitDistance< minDistance)
        {
            info.m_normal=normal;
            minDistance=hitDistance;
            info.m_object=m_objectVector[i];
            info.m_hitPoint=ray.getOrigin()+ray.getDirection()*minDistance;
        }


    }
    return info;
}
//void RayTracer::addLight(PointLight light)
//{
//    m_pLightsVector.push_back(light);
//}

