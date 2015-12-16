#include "SpotLight.h"

SpotLight::SpotLight():ILight()
{
    //ctor
    std::cout<<"asdsad";
}

SpotLight::~SpotLight()
{
    //dtor
}
SpotLight::SpotLight(d_type::Bfloat coneAngle, d_type::Bfloat coneCosinus, d_type::Bfloat linearAtt, Vector3Bf direction,Vector3Bf position, Colour color):ILight(position)
{
m_coneAngle=coneAngle;
m_coneCosinus=coneCosinus;
m_linearAtt=linearAtt;
m_direction=direction;
m_colour=color;

}

Colour SpotLight::calculate(const Fragment& fragment) const
{

d_type::Bfloat distance = Vector3Bf::distance(fragment.m_position,m_position);

Vector3Bf direction=fragment.m_negativePosToView - m_position;
Vector3Bf::normalize(direction);

d_type::Bfloat cosin=Vector3Bf::dotProduct(m_direction,direction);
d_type::Bfloat fDif=1.0f-m_coneCosinus;
d_type::Bfloat fFactor=Min(Max(((cosin-m_coneCosinus)/fDif),0.0f),1.0f);

if(cosin > m_coneCosinus)
{
    return m_colour * fFactor/(distance*m_linearAtt);
}
return Colour(0,0,0);



}
