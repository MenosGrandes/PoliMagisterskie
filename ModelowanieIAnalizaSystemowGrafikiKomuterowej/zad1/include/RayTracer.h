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
    RayTracer();
//    RayTracer(const RayTracer&rt);
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
    void setAmbientLight(Ambient* am)
    {
        this->m_ambientLight=am;
    }
    std::vector<IRaycastable*> getObjects()
    {
        return m_objectVector;
    }
    void setDepth(const d_type::Bint depth)
    {
        m_depth=depth;
    }
    Colour shadeRay(const Ray&ray);
    Info traceRay(const Ray&ray);
    Colour shadeRay(const Ray&ray,d_type::Bint depth);
    Colour shadeRay(const Ray&ray,d_type::Bfloat& tmin,d_type::Bint depth);






    std::vector<IRaycastable*> m_objectVector;
    std::vector<ILight*> m_lightsVector;
    ICamera *m_camera;
    RenderTarget *m_renderTanger;
    Sampler * m_sampler;
    ILight * m_ambientLight;
    d_type::Bint m_depth;
};

#endif // RAYTRACER_H
