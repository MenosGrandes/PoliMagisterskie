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

            d_type::Bfloat minDistance=std::numeric_limits<d_type::Bfloat>::max();
            d_type::Bfloat hitDistance=0.0f;
            //Colour c=m_renderTanger->getCleanColour();
            Vector3Bf normal;
            Info info;
            info.object=nullptr;


            for(d_type::Bsize i=0; i<m_objectVector.size(); i++)
            {

                if(m_objectVector[i]->intersect(ray,minDistance,normal) && hitDistance< minDistance)
                {
                    minDistance=hitDistance;
                    info.object=m_objectVector[i];
                    info.normal=normal;
                }

            }
            if(info.object!=nullptr)
            {
                info.hitPoint=ray.getOrigin()+ray.getDirection()*minDistance;

                Colour finalColour=Colour::Yellow;
                for(PointLight p :m_pLightsVector)
                {
                    finalColour+=info.object->getMaterial()->radiance(p,info.hitPoint,info.normal);
                }


                PerfectDifuse * p=static_cast<PerfectDifuse*>(info.object->getMaterial());
                m_renderTanger->setPixel(p->getColor(),x,y);

            }
            else
            {
                m_renderTanger->clearPixel(x,y);

            }




        }

    }
    std::cout<<"DONE\n";
}
void RayTracer::addLight(PointLight light)
{
    m_pLightsVector.push_back(light);
}
