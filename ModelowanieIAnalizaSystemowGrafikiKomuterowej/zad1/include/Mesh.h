#ifndef MESH_H
#define MESH_H
#include "Raycastable.h"
#include <memory>
#include <limits>
#include <vector>
#include "RayTriangle.h"
class Mesh : public IRaycastable
{
public:
    virtual d_type::BBool intersect(const Ray& ray,d_type::Bfloat & distance,Vector3Bf & normal) const
    {
        d_type::Bbyte isHit=false;
        d_type::Buint counter,triIndex=0;

        for(RayTriangle *a : m_triangles )
        {
            d_type::Bfloat t=std::numeric_limits<d_type::Bfloat>::max();
            if(a->intersect(ray,t,normal) && t<distance)
            {
                distance=t;
                triIndex=counter;
                isHit|=true;
            }
            counter++;
        }

        return isHit;
    };


    std::vector<RayTriangle *> m_triangles;
};

#endif // MESH_H
