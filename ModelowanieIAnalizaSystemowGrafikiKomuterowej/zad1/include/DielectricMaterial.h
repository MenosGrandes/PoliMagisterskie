#ifndef DIELECTRICMATERIAL_H
#define DIELECTRICMATERIAL_H
#include "PhongMaterial.h"
#include "FresnelReflector.h"
#include "FresnelTransmitter.h"

class DielectricMaterial: public PhongMaterial
{
public:
    DielectricMaterial();
    virtual ~DielectricMaterial();

    void   setKs(const d_type::Bfloat k);

    void   setExp(const d_type::Bfloat exponent);
    void   setRefractionIN(const d_type::Bfloat eta);

    void  setRefractionOUT(const d_type::Bfloat eta);

    void  setCfIn(const Colour& c);

    void  setCfOut(const Colour& c);



    virtual Colour shade(Info& sr);

    virtual Colour area_light_shade(Info& sr);

    virtual Colour path_shade(Info& sr);




protected:
private:
    FresnelReflector * m_fresnelBRDF;
    FresnelTransmitter * m_fresnelBTDF;
    Colour m_in,m_out;
};

#endif // DIELECTRICMATERIAL_H
