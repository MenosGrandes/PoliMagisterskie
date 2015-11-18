#ifndef GLOSSYREFLECTION_H
#define GLOSSYREFLECTION_H
#include "PhongMaterial.h"
#include "GlossySpecular.h"
class GlossyReflection : public PhongMaterial
{
    public:
        GlossyReflection();
        virtual ~GlossyReflection();
        void setSamples(const d_type::Bint samples,const d_type::Bfloat exp);
        virtual Colour shade(Info&info);
        virtual Colour areaLightShade(Info&info);
        virtual Colour pathShade(Info&info);
        void setCr(Colour & c);
        void setKr(d_type::Bfloat kr);
    protected:
    private:
        GlossySpecular * m_glossySpecular;
};

#endif // GLOSSYREFLECTION_H
