#ifndef RAYCASTABLE_H
#define RAYCASTABLE_H
#include "Ray.h"
#include <vector>
#include "Info.h"
#include "IMaterial.h"
#include "Box.h"
class IRaycastable
{
public:
    virtual d_type::BBool intersect(const Ray& ray,d_type::Bfloat & distance,Info &info) const=0 ;
    virtual d_type::BBool shadowHit(const Ray& ray,d_type::Bfloat & distance) const=0;
    virtual Box getBoundingBox()const {return Box(-1, 1, -1, 1, -1, 1);}
    virtual IMaterial * getMaterial() const
    {
        return m_material;
    }
    virtual void setMaterial(IMaterial * mat)
    {
        m_material=mat;
    }
    virtual ~IRaycastable()
    {

        //delete this->m_material;


    }
protected:
    mutable IMaterial * m_material;


};
typedef std::vector<IRaycastable*> RaycastableVector;
#endif // RAYCASTABLE_H
