#ifndef RAYCASTABLE_H
#define RAYCASTABLE_H
#include "IMaterial.h"
#include "Ray.h"
#include <vector>

class IRaycastable
{
public:
    virtual d_type::BBool intersect(const Ray& ray,d_type::Bfloat & distance,Vector3Bf & normal) const=0 ;
    virtual IMaterial * getMaterial()
    {
        return m_material;
    }
    virtual void setMaterial(IMaterial * mat)
    {
        m_material=mat;
    }
    virtual ~IRaycastable()
    {
        delete m_material;
    }
protected:
    mutable IMaterial * m_material;


};
typedef std::vector<IRaycastable*> RaycastableVector;
#endif // RAYCASTABLE_H
