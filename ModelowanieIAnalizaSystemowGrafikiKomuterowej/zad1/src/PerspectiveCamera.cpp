#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(Vector3Bf origin, Vector3Bf lookAt, Vector3Bf up, d_type::Bfloat distance,Vector2Bf scale)
    :m_origin(origin),m_lookAt(lookAt),m_up(up),m_distance(distance),m_scale(scale)
{
    orto=OrtBase(m_origin-m_lookAt,m_up);
}


Ray& PerspectiveCamera::recalculateRay(Vector2Bf position)
{
    Ray r(m_origin,recalculateRayDirection(position*m_scale),DIRECTION);
    return r;
}

Vector3Bf PerspectiveCamera::recalculateRayDirection(Vector2Bf location)
{
    return Vector3Bf(orto.u*location.x + orto.v*location.y+orto.w*(-m_distance));

}
