#include "ILight.h"

ILight::ILight()
{
    m_position = Vector3Bf(0.0f, 5.0f, 5.0f);
	m_ambient = Vector3Bf(0.1f, 0.1f, 0.1f);
	m_diffuse = Vector3Bf(0.7f, 0.7f, 0.7f);
	m_specular = Vector3Bf(0.3f, 0.3f, 0.3f);
	m_shininess = 10;
}

ILight::~ILight()
{
    //dtor
}
ILight::ILight(Vector3Bf position):m_position(position)
{

	m_ambient = Vector3Bf(0.1f, 0.1f, 0.1f);
	m_diffuse = Vector3Bf(0.7f, 0.7f, 0.7f);
	m_specular = Vector3Bf(0.5f, 0.5f, 0.5f);
	m_shininess = 10;

}
