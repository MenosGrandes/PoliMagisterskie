#ifndef IMAPPING_H
#define IMAPPING_H
#include "Vector3.h"

class IMapping
{
public:
    IMapping();
    virtual ~IMapping();
    virtual void getTexelCoord(const Vector3Bf localHitPoint,const d_type::Buint m_width,const d_type::Buint m_height, d_type::Buint&row,d_type::Buint& column ) const =0;
protected:
private:
};

#endif // IMAPPING_H
