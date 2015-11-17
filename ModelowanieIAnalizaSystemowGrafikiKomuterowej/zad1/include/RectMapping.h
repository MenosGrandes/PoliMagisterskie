#ifndef RECTMAPPING_H
#define RECTMAPPING_H
#include "IMapping.h"

class RectMapping : public IMapping
{
public:
    RectMapping();

    void getTexelCoord(const Vector3Bf &localHitPoint, const d_type::Bint m_width, const d_type::Bint m_height, d_type::Bint& row, d_type::Bint& column) const
    {
        d_type::Bfloat u=(localHitPoint.z+1)/2;
        d_type::Bfloat v =(localHitPoint.x-1)/2;
        column =(int)((m_width-1)*u);
        row =(int)((m_height-1)*v);
    }
    virtual ~RectMapping();
protected:
private:
};

#endif // RECTMAPPING_H
