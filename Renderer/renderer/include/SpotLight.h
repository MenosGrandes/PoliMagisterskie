#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
#include "ILight.h"
#include "../src/algorithms.hpp"
class SpotLight: public ILight
{
    public:
        SpotLight();
SpotLight(d_type::Bfloat coneAngle, d_type::Bfloat coneCosinus, d_type::Bfloat linearAtt, Vector3Bf direction,Vector3Bf position, Colour color);

        virtual ~SpotLight();
        Colour calculate(const Fragment& v) const;
        d_type::Bfloat m_coneAngle,m_coneCosinus,m_linearAtt;
        Vector3Bf m_direction;
        Colour m_colour;
};

#endif // SPOTLIGHT_H
