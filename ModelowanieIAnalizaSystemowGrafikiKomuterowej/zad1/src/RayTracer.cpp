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


    for(Bint x=0; x<m_renderTanger->getSize().x; x++)
    {
        for(Bint y=0; y<m_renderTanger->getSize().y; y++)
        {
            Vector2Bf picCoord(
                ((x+0.5f) / m_renderTanger->getSize().x)*2 -1,
                ((y+0.5f) / m_renderTanger->getSize().y)*2 -1
            );

            Ray r=m_camera->recalculateRay(picCoord);
            d_type::Bfloat minDistance=std::numeric_limits<d_type::Bfloat>::max();
            d_type::Bfloat hitDistance=0.0f;
            Colour c=m_renderTanger->getCleanColour();
            d_type::BBool hit;
            for(d_type::Bsize i=0; i<m_objectVector.size(); i++)
            {
                hit=m_objectVector[i]->intersect(r,minDistance);
                if(hit&& hitDistance< minDistance)
                {
                    minDistance=hitDistance;
                    c=m_objectVector[i]->getMaterial()->getColor();
                }

            }

            m_renderTanger->setPixel(c,x,y);

        }

    }
    std::cout<<"DONE\n";
}
