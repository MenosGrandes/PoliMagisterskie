#ifndef CAMERA_H
#define CAMERA_H
#include "Vector2.h"
#include "Vector3.h"

class Camera
{
    public:
        Camera();
        Camera(Vector2Bf position,Vector3Bf target);
        virtual ~Camera();
    protected:
        Vector2Bf m_position,m_nearFarPlane;
        Vector3Bf m_target,m_up;
        d_type::Bfloat m_fov;

};

#endif // CAMERA_H
