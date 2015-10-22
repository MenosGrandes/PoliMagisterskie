#ifndef ORTAGONALCAMERA_H
#define ORTAGONALCAMERA_H
#include "Camera.h"
#include "algorithms.hpp"
class OrtagonalCamera : public ICamera
{
public:
    OrtagonalCamera(Vector3Bf m_eyePosition, d_type::Bfloat m_angle,Vector2Bf m_cameraSize);
    virtual ~OrtagonalCamera();
    virtual Ray& recalculateRay(Vector2Bf position);

protected:
private:
    Vector3Bf m_eyePosition;
    d_type::Bfloat m_angle;
    Vector2Bf m_cameraSize;
};

#endif // ORTAGONALCAMERA_H
