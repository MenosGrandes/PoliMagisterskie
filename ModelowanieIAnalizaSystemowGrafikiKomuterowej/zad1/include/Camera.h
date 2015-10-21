#ifndef CAMERA_H
#define CAMERA_H
#include "Vector2.h"
#include "Ray.h"

class ICamera
{
public:
    virtual Ray& recalculateRay(Vector2Bf position)=0;
};

#endif // CAMERA_H
