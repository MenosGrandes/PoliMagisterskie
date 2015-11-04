#ifndef INFO_H
#define INFO_H
#include "Ray.h"

class IRaycastable;
class Info
{
public:
    Info(Vector3Bf normal,Vector3Bf hitPoint,d_type::BBool hit);
    virtual ~Info();
    IRaycastable* m_obj;
    Vector3Bf m_normal,m_hitPoint,m_localHitPoint,m_dir;
    d_type::BBool m_hit;
    Ray ray;
    d_type::Buint m_depth;
    d_type::Bfloat m_t;


};

#endif // INFO_H
