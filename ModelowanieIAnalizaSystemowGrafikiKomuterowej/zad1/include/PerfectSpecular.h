#ifndef PERFECTSPECULAR_H
#define PERFECTSPECULAR_H
#include "BRDF.h"

class PerfectSpecular : public BRDF
{
public:
    PerfectSpecular();
    virtual ~PerfectSpecular();
    virtual Colour f(const Info& info,const Vector3Bf &wi,const Vector3Bf &wo) const ;
    virtual Colour sample_f(const Info& info, Vector3Bf &wi,const Vector3Bf &wo) const;
    virtual Colour rho(const Info& info,const Vector3Bf &wo) const ;
protected:
private:
};

#endif // PERFECTSPECULAR_H
