#ifndef BRDF_H
#define BRDF_H
#include "Sampler.h"
#include "Colour.h"
#include "Info.h"
class BRDF
{
public:
    BRDF();
    virtual ~BRDF();
    //RETURN BRDF ITSELF
    virtual Colour f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const =0;
    ///COMPUTE THE DIRECTIONAL OR REFLECTED RAYS FOR SIMULATING REFLECTIVE MATERIALS AND DIFFUSE-DIFFUSE LIGHT TRANSPORT
    virtual Colour sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const=0;
    ///RETURN BISFERICAL REFLECTIONS
    virtual Colour rho(const Info& info,const Vector3Bf &wo) const =0;

protected:
    Sampler* m_sampler;
};

#endif // BRDF_H
