#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "Camera.h"
#include "RenderTarget.h"
#include "Sampler.h"
#include "Info.h"
#include <limits>
#include "Ambient.h"
#include "Raycastable.h"
class ILight;
class RayTracer
{
public:
    RayTracer(ICamera *camera,RenderTarget *m_target,Sampler* sampler);
    RayTracer(ICamera *camera,RenderTarget *m_target);
    RayTracer(ICamera *camera,RenderTarget *m_target,Sampler* sampler,Ambient*ambient);

    virtual ~RayTracer();
    void addObject(IRaycastable *ray);
    void addLight(ILight * light);
    void rayTrace();

    ILight* getAmbientLight()
    {
        return m_ambientLight;
    }
    std::vector<ILight*> getLights()
    {
        return m_lightsVector;
    }

private:

    Colour shadeRay(const Ray&ray);
    Info traceRay(const Ray&ray);



    std::vector<IRaycastable*> m_objectVector;
    std::vector<ILight*> m_lightsVector;
    ICamera *m_camera;
    RenderTarget *m_renderTanger;
    Sampler * m_sampler;
    ILight * m_ambientLight;

};

#endif // RAYTRACER_H
