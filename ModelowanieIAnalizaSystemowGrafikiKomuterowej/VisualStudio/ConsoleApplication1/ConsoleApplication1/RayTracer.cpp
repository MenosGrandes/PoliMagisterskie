#include "RayTracer.h"

RayTracer::RayTracer(ICamera *camera, RenderTarget *m_target):m_camera(camera),m_renderTanger(m_target)
{

}

RayTracer::~RayTracer()
{

}

void RayTracer::addObject(IRaycastable* ray)
{
    m_objectVector.push_back(ray);
}
void RayTracer::rayTrace()
{
    Colour * c=new Colour[m_objectVector.size()];
    c[0]=Colour::Black;
    c[1]=Colour::Yellow;
    c[2]=Colour::Red;
    c[3]=Colour::Green;
    c[3]=Colour::Blue;

    for(Bint x=0; x<m_renderTanger->getSize().x; x++)
    {
        for(Bint y=0; y<m_renderTanger->getSize().y; y++)
        {
            Vector2Bf picCoord(
                ((x+0.5f) / m_renderTanger->getSize().x)*2 -1,
                ((y+0.5f) / m_renderTanger->getSize().y)*2 -1
            );

            Ray r=m_camera->recalculateRay(picCoord);

            for(d_type::Bsize i=0; i<m_objectVector.size(); i++)
            {
                Vector3BfVector v=m_objectVector[i]->intersect(r);
                if(!v.empty())
                {
                    m_renderTanger->setPixel(c[i],x,y);

                }

            }

        }

    }
    std::cout<<"DONE\n";
    delete [] c;
}
