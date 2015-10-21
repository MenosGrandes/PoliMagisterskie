#include "OrtagonalCamera.h"
OrtagonalCamera::OrtagonalCamera(Vector3Bf eyePosition, d_type::Bfloat angle,Vector2Bf cameraSize):m_eyePosition(eyePosition),m_angle(angle),m_cameraSize(cameraSize)
{
m_angle=ToRadians::toRadians(m_angle);
}

OrtagonalCamera::~OrtagonalCamera()
{

}

Ray & OrtagonalCamera::recalculateRay(Vector2Bf position)
{
    Vector3Bf dir(sinf(m_angle),0,cosf(m_angle));
    Vector3Bf::normalize(dir);
    Vector2Bf distanceFromCamera(position.x*m_cameraSize.x,
                                 position.y*m_cameraSize.y);

    Vector3Bf pos(
                  m_eyePosition.x + distanceFromCamera.x*cosf(m_angle),
                  m_eyePosition.y + distanceFromCamera.y,
                  m_eyePosition.z + distanceFromCamera.x*sinf(m_angle));
                  Ray r(pos,dir,DIRECTION);
    return r;
}
