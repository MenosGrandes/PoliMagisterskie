#ifndef INFO_H
#define INFO_H
#include "Raycastable.h"
#include "Ray.h"

class Info
{
public:
    Info(IRaycastable * object,Vector3Bf normal,Vector3Bf hitPoint,d_type::BBool hit);
    virtual ~Info();
    IRaycastable * m_object;
    Vector3Bf m_normal,m_hitPoint;
    d_type::BBool m_hit;
};

#endif // INFO_H
