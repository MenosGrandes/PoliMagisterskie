#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "Raycastable.h"
#include "Camera.h"
#include "RenderTarget.h"
#include "PointLight.h"
#include "PerfectDifuse.h"
#include <limits>
class RayTracer
{
public:
    RayTracer(ICamera *camera,RenderTarget *m_target);
    virtual ~RayTracer();
    void addObject(IRaycastable *ray);
    void addLight(PointLight light);
    void rayTrace();
    struct Info
    {
        IRaycastable * object;
        Vector3Bf normal,hitPoint;
        Ray ray;

    };
private:

    Colour shadeRay(const Ray&ray);
    Info traceRay(const Ray&ray);



    RaycastableVector m_objectVector;
    PointLightVector m_pLightsVector;
    ICamera *m_camera;
    RenderTarget *m_renderTanger;

};

#endif // RAYTRACER_H
