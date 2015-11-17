#ifndef SPERICALMAPPING_H
#define SPERICALMAPPING_H
#include "IMapping.h"

class SpericalMapping : public IMapping
{
public:
    SpericalMapping();
    SpericalMapping(d_type::Bfloat size):m_size(size){};

    void getTexelCoord(const Vector3Bf &localHitPoint, const d_type::Bint m_width, const d_type::Bint m_height, d_type::Bint& row, d_type::Bint& column) const
    {


        d_type::Bfloat theta=acos(localHitPoint.y);
        d_type::Bfloat phi = atan2(localHitPoint.z,localHitPoint.x);
        if(phi<0.0)
        {
            phi+=TWO_PI;
        }
        d_type::Bfloat u=phi*INV_TWO_PI;
        d_type::Bfloat v = 1 - theta* INV_PI;
        column =(int)((m_width-1)*u);
        row =(int)((m_height-1)*v);
    }
    virtual ~SpericalMapping();
protected:
private:
    d_type::Bfloat m_size;
};

#endif // SPERICALMAPPING_H
