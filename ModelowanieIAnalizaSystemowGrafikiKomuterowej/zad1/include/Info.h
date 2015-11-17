#ifndef INFO_H
#define INFO_H
#include "Ray.h"
#include "IMaterial.h"
class RayTracer;
class Info
{
public:
    Info(Vector3Bf normal,Vector3Bf hitPoint,d_type::BBool hit,RayTracer * rt);
    virtual ~Info();
    IMaterial* m_material;
    Vector3Bf m_normal,m_hitPoint,m_localHitPoint,m_dir;
    d_type::BBool m_hit;
    Ray m_ray;
    d_type::Buint m_depth;
    d_type::Bfloat m_t;
    RayTracer * m_rayTracer;
    Vector2Bf m_uv;

};

#endif // INFO_H
