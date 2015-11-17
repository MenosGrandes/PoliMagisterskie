#ifndef IMAPPING_H
#define IMAPPING_H
#include "Vector3.h"

class IMapping
{
public:
    IMapping();
    virtual ~IMapping();
    virtual void getTexelCoord(const Vector3Bf &localHitPoint,const d_type::Bint m_width,const d_type::Bint m_height, d_type::Bint&row,d_type::Bint& column ) const =0;
protected:
private:
};

#endif // IMAPPING_H
