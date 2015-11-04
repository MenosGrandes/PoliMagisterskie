#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "Raycastable.h"
#include "Camera.h"
#include "RenderTarget.h"
#include "Sampler.h"
#include "Info.h"
#include "ILight.h"
#include <limits>
class RayTracer
{
public:
    RayTracer(ICamera *camera,RenderTarget *m_target,Sampler* sampler);
    RayTracer(ICamera *camera,RenderTarget *m_target);

    virtual ~RayTracer();
    void addObject(IRaycastable *ray);
    void addLight(ILight * light);
    void rayTrace();

    void enableLight(d_type::BBool val);
    void enableAA(d_type::BBool val);
private:

    Colour shadeRay(const Ray&ray);
    Info traceRay(const Ray&ray);



    RaycastableVector m_objectVector;
//    PointLightVector m_pLightsVector;
    ICamera *m_camera;
    RenderTarget *m_renderTanger;
    Sampler * m_sampler;

};

#endif // RAYTRACER_H
