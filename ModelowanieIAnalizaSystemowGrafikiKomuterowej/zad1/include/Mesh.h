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

        for(RayTriangle *a : m_triangles )
        {
            d_type::Bfloat t=std::numeric_limits<d_type::Bfloat>::max();
            if(a->intersect(ray,t,normal) )
            {
                distance=t;
                isHit=true;
                m_material=a->getMaterial();
            }

        }

        return isHit;
    };


    std::vector<RayTriangle *> m_triangles;
};

#endif // MESH_H
