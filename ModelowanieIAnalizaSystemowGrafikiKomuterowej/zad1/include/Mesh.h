#ifndef MESH_H
#define MESH_H
#include "Raycastable.h"
#include <memory>
#include <limits>
#include <vector>
#include "RayTriangle.h"
#include "Box.h"
class Mesh : public IRaycastable
{
public:
    virtual d_type::BBool intersect(const Ray& ray,d_type::Bfloat & distance,Info &info) const
    {
        d_type::Bbyte isHit=false;
        distance=1000;
        d_type::Bfloat t;
        if(m_boundingBox.intersect(ray,t,info)&& t<distance)
        {

            d_type::Bfloat t2;

            for(RayTriangle *a : m_triangles )
            {

                if(a->intersect(ray,t2,info)&& t2<distance )
                {
                    distance=t2;
                    isHit=true;
                   m_material=a->getMaterial();
                }

            }
        }

        return isHit;
    };
    void createBoundingBox()
    {
        d_type::Bfloat
        min_x, max_x,
               min_y, max_y,
               min_z, max_z;
        min_x = max_x = m_triangles[0]->getVertex1().m_position.x;
        min_y = max_y = m_triangles[0]->getVertex1().m_position.y;
        min_z = max_z = m_triangles[0]->getVertex1().m_position.z;

        for (int i = 0; i < m_triangles.size(); i++)
        {
///X
            if(m_triangles[i]->getVertex1().m_position.x > max_x)
            {
                max_x=m_triangles[i]->getVertex1().m_position.x;
            }
            if(m_triangles[i]->getVertex1().m_position.x< min_x)
            {
                min_x=m_triangles[i]->getVertex1().m_position.x;
            }

            if(m_triangles[i]->getVertex2().m_position.x > max_x)
            {
                max_x=m_triangles[i]->getVertex2().m_position.x;
            }
            if(m_triangles[i]->getVertex2().m_position.x< min_x)
            {
                min_x=m_triangles[i]->getVertex2().m_position.x;
            }

            if(m_triangles[i]->getVertex3().m_position.x > max_x)
            {
                max_x=m_triangles[i]->getVertex3().m_position.x;
            }
            if(m_triangles[i]->getVertex3().m_position.x< min_x)
            {
                min_x=m_triangles[i]->getVertex3().m_position.x;
            }
///Y

            if(m_triangles[i]->getVertex1().m_position.y > max_y)
            {
                max_y=m_triangles[i]->getVertex1().m_position.y;
            }
            if(m_triangles[i]->getVertex1().m_position.y< min_y)
            {
                min_y=m_triangles[i]->getVertex1().m_position.y;
            }

            if(m_triangles[i]->getVertex2().m_position.y > max_y)
            {
                max_y=m_triangles[i]->getVertex2().m_position.y;
            }
            if(m_triangles[i]->getVertex2().m_position.y< min_x)
            {
                min_y=m_triangles[i]->getVertex2().m_position.y;
            }

            if(m_triangles[i]->getVertex3().m_position.y > max_y)
            {
                max_y=m_triangles[i]->getVertex3().m_position.y;
            }
            if(m_triangles[i]->getVertex3().m_position.y< min_y)
            {
                min_y=m_triangles[i]->getVertex3().m_position.y;
            }

///Y

            if(m_triangles[i]->getVertex1().m_position.z > max_z)
            {
                max_z=m_triangles[i]->getVertex1().m_position.z;
            }
            if(m_triangles[i]->getVertex1().m_position.z< min_z)
            {
                min_z=m_triangles[i]->getVertex1().m_position.z;
            }

            if(m_triangles[i]->getVertex2().m_position.z > max_z)
            {
                max_z=m_triangles[i]->getVertex2().m_position.z;
            }
            if(m_triangles[i]->getVertex2().m_position.z< min_x)
            {
                min_z=m_triangles[i]->getVertex2().m_position.z;
            }

            if(m_triangles[i]->getVertex3().m_position.z > max_z)
            {
                max_z=m_triangles[i]->getVertex3().m_position.z;
            }
            if(m_triangles[i]->getVertex3().m_position.z< min_z)
            {
                min_z=m_triangles[i]->getVertex3().m_position.z;
            }

        }
        m_boundingBox=Box(Vector3Bf(min_x,min_y,min_z),Vector3Bf(max_x,max_y,max_z));
    }
    Box m_boundingBox;
    std::vector<RayTriangle *> m_triangles;
};

#endif // MESH_H
