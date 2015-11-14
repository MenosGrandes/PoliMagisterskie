#ifndef SPERICALMAPPING_H
#define SPERICALMAPPING_H
#include "IMapping.h"

class SpericalMapping : public IMapping
{
public:
    SpericalMapping();

    void getTexelCoord(const Vector3Bf localHitPoint, const d_type::Buint m_width, const d_type::Buint m_height, d_type::Buint& row, d_type::Buint& column)
    {
        d_type::Bfloat theta=acosf(localHitPoint.y);
        d_type::Bfloat phi= atan2f(localHitPoint.x,localHitPoint.z);
        if(phi<0.0)
        {
            phi+=TWO_PI;
        }
        d_type::Bfloat u =phi*INV_TWO_PI;
        d_type::Bfloat v=1-theta*INV_PI;

        column = (d_type::Buint)((m_width-1)*u);
        row = (d_type::Buint)((m_height-1)*v);

    }
    virtual ~SpericalMapping();
protected:
private:
};

#endif // SPERICALMAPPING_H
