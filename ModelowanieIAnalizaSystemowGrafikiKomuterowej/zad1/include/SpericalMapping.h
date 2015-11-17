#ifndef SPERICALMAPPING_H
#define SPERICALMAPPING_H
#include "IMapping.h"
#include "Sphere.h"
class SpericalMapping : public IMapping
{
public:
    SpericalMapping(const Sphere* s):m_sphere(s){};
    SpericalMapping(d_type::Bfloat size):m_size(size){};
    SpericalMapping();
    void getTexelCoord(const Vector3Bf &localHitPoint, const d_type::Bint m_width, const d_type::Bint m_height, d_type::Bint& row, d_type::Bint& column) const
    {

        Vector3Bf normal=localHitPoint - m_sphere->getCenter();
        Vector3Bf::normalize(normal);
//        d_type::Bfloat theta=acos(normal.y);
//        d_type::Bfloat phi = atan2(normal.z,normal.x);
//        if(phi<0.0)
//        {
//            phi+=TWO_PI;
//        }
        d_type::Bfloat u=0.5+atan2(normal.z,normal.x)*INV_TWO_PI;
        d_type::Bfloat v = 0.5-asin(normal.y)*INV_PI;
        column =(int)(m_width*u);
        row =(int)(m_height)*v;
    }
    virtual ~SpericalMapping();
protected:
private:
    d_type::Bfloat m_size;
    const Sphere* m_sphere;
};

#endif // SPERICALMAPPING_H
