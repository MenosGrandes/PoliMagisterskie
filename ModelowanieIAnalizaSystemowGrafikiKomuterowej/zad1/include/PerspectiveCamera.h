#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H
#include "Camera.h"

class PerspectiveCamera : public ICamera
{
private :
    class OrtBase
    {
    public:
        Vector3Bf u,v,w;
        OrtBase(Vector3Bf front,Vector3Bf up)
        {
            w=front;
            Vector3Bf::normalize(w);
            u=Vector3Bf::cross(up,w);
            Vector3Bf::normalize(u);
            v=Vector3Bf::cross(w,u);
        }
        OrtBase():u(Vector3Bf()),v(Vector3Bf()),w(Vector3Bf()) {};

    };
public:
    PerspectiveCamera(Vector3Bf origin,Vector3Bf lookAt,Vector3Bf up,d_type::Bfloat distance,Vector2Bf scale);
    Ray& recalculateRay(Vector2Bf position);
    Vector3Bf recalculateRayDirection(Vector2Bf location);
protected:
private:
    Vector3Bf m_origin,m_lookAt,m_up;
    Vector2Bf m_scale;
    d_type::Bfloat m_distance;
    OrtBase orto;


};


#endif // PERSPECTIVECAMERA_H
