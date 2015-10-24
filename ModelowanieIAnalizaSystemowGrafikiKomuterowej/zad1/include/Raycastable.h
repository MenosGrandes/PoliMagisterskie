#ifndef RAYCASTABLE_H
#define RAYCASTABLE_H
#include "IMaterial.h"
#include "Ray.h"
#include <vector>

class IRaycastable
{
public:
    virtual d_type::BBool intersect(const Ray& ray,d_type::Bfloat & distance,Vector3Bf & normal) const=0 ;
    IMaterial * getMaterial()
    {
        return m_material;
    }
    virtual ~IRaycastable()
{
    delete m_material;
}
    protected:
    IMaterial * m_material;


};
typedef std::vector<IRaycastable*> RaycastableVector;
#endif // RAYCASTABLE_H
