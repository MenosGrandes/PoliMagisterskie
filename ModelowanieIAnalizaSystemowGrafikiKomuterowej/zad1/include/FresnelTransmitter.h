#ifndef FRESNELTRANSMITTER_H
#define FRESNELTRANSMITTER_H
#include "BTDF.h"

class FresnelTransmitter : public BTDF
{
    public:
        FresnelTransmitter();
        virtual ~FresnelTransmitter();
        void setRefIN(d_type::Bfloat k);
        void setRefOUT(d_type::Bfloat k);
        virtual Colour f(const Info& info, const Vector3Bf& wi, const Vector3Bf& wo) const ;
        virtual Colour sample_f(const Info& info, const Vector3Bf& wo, Vector3Bf& wt) const ;
        virtual Colour  rho(const Info& info, const Vector3Bf& wo) const ;
        d_type::BBool tir(const Info&info) const;
        d_type::Bfloat fresnel(const Info&info) const;
    protected:
    private:
    d_type::Bfloat m_refractionIN;           // index of refraction in
    d_type::Bfloat m_refractionOUT;          // index of refraction out

};

#endif // FRESNELTRANSMITTER_H
