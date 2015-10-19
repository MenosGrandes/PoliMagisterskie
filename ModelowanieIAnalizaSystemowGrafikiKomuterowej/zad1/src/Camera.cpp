#include "Camera.h"

Camera::Camera():m_position(),m_fov(0),m_nearFarPlane(),m_target(),m_up(0,1,0)
{

}

Camera::Camera(Vector2Bf position, Vector3Bf target):m_position(position),m_target(target),m_nearFarPlane(1,1000),m_up(0,1,0)
{

}

Camera::~Camera()
{

}
