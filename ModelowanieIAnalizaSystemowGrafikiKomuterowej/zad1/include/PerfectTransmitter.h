#ifndef PERFECTTRANSMITTER_H
#define PERFECTTRANSMITTER_H
#include "BTDF.h"

class PerfectTransmitter:public BTDF
{
    public:
        PerfectTransmitter();
        virtual ~PerfectTransmitter();
        virtual Colour f(const Info& info, const Vector3Bf& wi, const Vector3Bf& wo) const ;
        virtual Colour sample_f(const Info& info, const Vector3Bf& wo, Vector3Bf& wt) const ;
        virtual Colour  rho(const Info& info, const Vector3Bf& wo) const ;
        void setIndexRef(const d_type::Bfloat k);
        void setTransmissionCoof(const d_type::Bfloat k);
        d_type::BBool tir(const Info& info)const;
    protected:
    private:
       d_type::Bfloat m_transmissionCoof;
       d_type::Bfloat m_indexOdRef;
};

#endif // PERFECTTRANSMITTER_H
