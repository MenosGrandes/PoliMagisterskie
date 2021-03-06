#ifndef POINTLIGHT_H
#define POINTLIGHT_H
#include "ILight.h"
#include "Raycastable.h"
#include "RayTracer.h"
class Info;
class PointLight : public ILight
{
public:
    PointLight();
    Vector3Bf getDirection(Info &info)
    {
        Vector3Bf v(m_location-info.m_hitPoint);
        Vector3Bf::normalize(v);
        return v;
    }
    Colour L(Info &info)
    {
        return(m_ls*m_colour);
    }
    virtual ~PointLight();
    d_type::BBool inShadow(const Ray&ray, const Info&info)
    {
        d_type::Bfloat t;
        d_type::Bfloat d=Vector3Bf::distance(m_location,ray.getOrigin());//.distance(ray.getOrigin());
        const std::vector<IRaycastable*> raycastableObjects = info.m_rayTracer->getObjects();
        const d_type::Buint numberOfObjects = raycastableObjects.size();

        for(d_type::Bsize i =0;i<numberOfObjects;i++)
        {
            if(raycastableObjects[i]->shadowHit(ray,t)&&t<d)
            {
                return true;
            }
        }
        return false;

    }
    d_type::Bfloat m_ls;
    Colour m_colour;
    Vector3Bf m_location;
    d_type::Bfloat m_intensittivity;// intensywnosc swiatla do photonow
};

#endif // POINTLIGHT_H
