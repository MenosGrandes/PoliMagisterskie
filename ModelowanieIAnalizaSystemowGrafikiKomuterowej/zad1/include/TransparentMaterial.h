#ifndef TRANSPARENTMATERIAL_H
#define TRANSPARENTMATERIAL_H
#include "PhongMaterial.h"
#include "PerfectSpecular.h"
#include "PerfectTransmitter.h"

class TransparentMaterial : public PhongMaterial
{
    public:
        TransparentMaterial();
        virtual ~TransparentMaterial();
        void setExp(const d_type::Bfloat ks);
        void setCr(const Colour & c);
        void setIndexRef(const d_type::Bfloat k);
        void setTransmissionCoof(const d_type::Bfloat k);
        virtual Colour shade(Info&info);
        void setKs(const d_type::Bfloat k);
        void setKr(const d_type::Bfloat k);

    protected:
    private:
        PerfectTransmitter *m_transmitter;
        PerfectSpecular* m_specular;
};

#endif // TRANSPARENTMATERIAL_H
