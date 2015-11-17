#ifndef PERFECTSPECULAR_H
#define PERFECTSPECULAR_H
#include "Colour.h"
#include "BRDF.h"
class PerfectSpecular : public BRDF
{
    public:
        PerfectSpecular();
        virtual ~PerfectSpecular();
        void setCr(const Colour & colour)
        {
            m_cr=colour;
        }
        void setKr(const d_type::Bfloat kr)
        {
            m_kr=kr;
        }
        Colour getCr() const
        {
            return m_cr;
        }
        d_type::Bfloat getKr() const
        {
            return m_kr;
        }
    virtual Colour f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const ;
    virtual Colour sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const;
    virtual Colour rho(const Info& info,const Vector3Bf &wo) const ;
    protected:
    private:
    d_type::Bfloat m_kr;
    Colour m_cr;
};

#endif // PERFECTSPECULAR_H
