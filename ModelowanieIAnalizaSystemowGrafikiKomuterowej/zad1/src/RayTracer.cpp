#include "RayTracer.h"

RayTracer::RayTracer(ICamera *camera, RenderTarget *m_target):m_camera(camera),m_renderTanger(m_target)
{

}

RayTracer::~RayTracer()
{
    delete m_camera;
    delete m_renderTanger;
}

void RayTracer::addObject(IRaycastable* ray)
{
    m_objectVector.push_back(ray);
}
void RayTracer::rayTrace()
{
    Ray ray;

    for(Bint x=0; x<m_renderTanger->getSize().x; x++)
    {
        for(Bint y=0; y<m_renderTanger->getSize().y; y++)
        {
            Vector2Bf picCoord(
                ((x+0.5f) / m_renderTanger->getSize().x)*2 -1,
                ((y+0.5f) / m_renderTanger->getSize().y)*2 -1
            );

            ray=m_camera->recalculateRay(picCoord);
///////////////////////////////////////////////////////////////////
            m_renderTanger->setPixel(Colour::clampColour(shadeRay(ray)),x,y);

/////////////////////////////////////////////////////////



        }

    }
    std::cout<<"DONE\n";
}
Colour RayTracer::shadeRay(const Ray&ray)
{
    Info info = traceRay(ray);
    if(info.object == nullptr)
    {
        return Colour::RoyalBlue;
    }
    Colour finalColor = Colour::Black;
    IMaterial * material= info.object->getMaterial();

    for(d_type::Bsize i =0; i<m_pLightsVector.size(); i++)
    {
        finalColor=material->radiance(m_pLightsVector[i],info.hitPoint,info.normal)+finalColor;
    }
    return finalColor;
}

RayTracer::Info RayTracer::traceRay(const Ray&ray)
{
    d_type::Bfloat minDistance=std::numeric_limits<d_type::Bfloat>::max();
    d_type::Bfloat hitDistance=0.0f;
    //Colour c=m_renderTanger->getCleanColour();
    Vector3Bf normal=Vector3Bf(0,0,0);
    Info info;
    info.object=nullptr;
    info.normal=Vector3Bf(0,0,0);
    info.hitPoint=Vector3Bf(0,0,0);

    // std::cout<<normal<<" normal default\n";
    for(d_type::Bsize i=0; i<m_objectVector.size(); i++)
    {
        if(m_objectVector[i]->intersect(ray,hitDistance,normal) && hitDistance< minDistance)
        {
            info.normal=normal;
            minDistance=hitDistance;
            info.object=m_objectVector[i];
            info.hitPoint=ray.getOrigin()+ray.getDirection()*minDistance;
            info.ray=ray;
        }

    }


    return info;
}
void RayTracer::addLight(PointLight light)
{
    m_pLightsVector.push_back(light);
}
