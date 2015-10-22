#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "Raycastable.h"
#include "Camera.h"
#include "RenderTarget.h"
class RayTracer
{
public:
    RayTracer(ICamera *camera,RenderTarget *m_target);
    virtual ~RayTracer();
    void addObject(IRaycastable *ray);
    void rayTrace();
private:
    RaycastableVector m_objectVector;
    ICamera *m_camera;
    RenderTarget *m_renderTanger;

};

#endif // RAYTRACER_H
