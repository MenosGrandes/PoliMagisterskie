#include "Info.h"

Info::Info( Vector3Bf normal, Vector3Bf hitPoint, d_type::BBool hit,RayTracer*rt):m_normal(normal),m_hitPoint(hitPoint),m_hit(hit),m_rayTracer(rt)
{

}

Info::~Info()
{

}
