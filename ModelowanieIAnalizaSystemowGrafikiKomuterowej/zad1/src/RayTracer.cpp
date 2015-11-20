#include "RayTracer.h"

RayTracer::RayTracer(ICamera *camera, RenderTarget *m_target,Sampler *sampler)
    :m_camera(camera),m_renderTanger(m_target),m_sampler(sampler),m_ambientLight(new Ambient())
{

}
RayTracer::RayTracer(ICamera *camera, RenderTarget *m_target)
    :m_camera(camera),m_renderTanger(m_target),m_ambientLight(new Ambient())
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
    std::cout<<m_objectVector.size()<<"\n";
}

//tutaj mozna pokombinowac z watkami
void RayTracer::rayTrace()
{
    Ray ray;
    Colour finalColour=Colour::Black;
    const d_type::Buint simple_count=m_sampler->getSampleCount();
    for(Bint x=0; x<m_renderTanger->getSize().x; x++)
    {
        for(Bint y=0; y<m_renderTanger->getSize().y; y++)
        {
            finalColour=Colour::Black;


            for(d_type::Bint i=0; i<simple_count; i++)
            {
                const Vector2Bf sample = m_sampler->single();
                Vector2Bf picCoord(
                    ((x+sample.x) / m_renderTanger->getSize().x)*2 -1,
                    ((y+sample.y) / m_renderTanger->getSize().y)*2 -1
                );

                ray=m_camera->recalculateRay(picCoord);

                finalColour+=shadeRay(ray);///m_sampler->getSampleCount();

            }
            finalColour/=simple_count;
            m_renderTanger->setPixel(Colour::maxToOne(finalColour),x,y);

        }




    }
    std::cout<<"DONE\n";
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
            info.m_hitPoint=ray.getOrigin()+ray.getDirection()*minDistance;
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
Colour RayTracer::shadeRay(const Ray&ray)
{
    Info info = traceRay(ray);
    if(info.m_hit == false)
    {
        return Colour::RoyalBlue;
    }

    info.m_ray=ray;

    return info.m_material->shade(info);

}
Colour RayTracer::shadeRay(const Ray& ray, d_type::Bint depth)
{

    if(depth>m_depth)
    {
        return Colour::Black;
    }
    else
    {
        Info info = traceRay(ray);
        if(info.m_hit == false)
        {
            return Colour::RoyalBlue;
        }
        else
        {
            info.m_ray=ray;
            info.m_depth=depth;
            //std::cout<<m_depth<<"\n";
            //  std::cout<<info.m_depth<<" depth\n";
            return info.m_material->shade(info);
        }


    }
}
Colour RayTracer::shadeRay(const Ray& ray, d_type::Bfloat& tmin, d_type::Bint depth)
{
    if(depth>m_depth)
    {
        return Colour::Black;
    }
    else
    {
        Info info = traceRay(ray);
        if(info.m_hit == false)
        {
            tmin=1E01;
            return Colour::RoyalBlue;
        }
        else
        {
            info.m_ray=ray;
            info.m_depth=depth;
            tmin=info.m_t;
            //std::cout<<m_depth<<"\n";
            //  std::cout<<info.m_depth<<" depth\n";
            return info.m_material->shade(info);
        }


    }
}
