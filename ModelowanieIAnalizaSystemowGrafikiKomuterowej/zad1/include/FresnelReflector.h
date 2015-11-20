#ifndef FRESNELREFLECTOR_H
#define FRESNELREFLECTOR_H
#include "BRDF.h"

class FresnelReflector : public BRDF
{
    public:
        FresnelReflector();
        virtual ~FresnelReflector();
        d_type::Bfloat fresnel(const Info & info) const;
        void setRefractionIN(const d_type::Bfloat in);
        void  setRefractionOUT(const d_type::Bfloat out);
        virtual Colour  f(const Info& sr, const Vector3Bf& wi, const Vector3Bf& wo) const;
        virtual Colour  sample_f(const Info& sr,  Vector3Bf& wr, const Vector3Bf& wo) const;
        virtual Colour rho(const Info& sr, const Vector3Bf& wo)const;
    protected:
    private:
    d_type::Bfloat m_refractionIN;           // index of refraction in
    d_type::Bfloat m_refractionOUT;          // index of refraction out
};

#endif // FRESNELREFLECTOR_H
