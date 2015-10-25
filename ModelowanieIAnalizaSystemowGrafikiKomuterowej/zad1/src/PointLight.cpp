#include "PointLight.h"

PointLight::PointLight(Vector3Bf pos, Colour c):m_position(pos),ILight(c)
{

}

PointLight::~PointLight()
{

}

void PointLight::setPosition(const Vector3Bf& pos)
{
    this->m_position=pos;
}

Vector3Bf PointLight::getPosition() const
{
    return m_position;
}
