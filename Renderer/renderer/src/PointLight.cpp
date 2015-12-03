#include "PointLight.h"

PointLight::PointLight()
{
    //ctor
}
PointLight::PointLight(Vector3Bf pos):ILight(pos)
{

}
PointLight::~PointLight()
{
    //dtor
}
Colour PointLight::calculate(const Fragment& v) const
{

	Vector3Bf N, R, V, L;
	d_type::Bfloat diff, spec;
	N = v.m_normal;
	V = v.m_negativePosToView;
	L = V - m_position;
	Vector3Bf::normalize(L);//L.Normalize();
	Vector3Bf::normalize(V);//V.Normalize();
	R =Vector3Bf::reflect(L,N);
	// L.Reflect(N);

	diff = Vector3Bf::dotProduct(L,N); //L.DotProduct(N);
	spec = pow(Vector3Bf::dotProduct(R,V), m_shininess);
	//cout << diff << "   " << spec << endl;
	//return float3(diffuse[0] * diff, diffuse[1] * diff, diffuse[2] * diff);// *attCoefAtPoint(v.position);
	return Colour(m_ambient.x + m_diffuse.x * diff + m_specular.x * spec, m_ambient.y + m_diffuse.y * diff + m_specular.y * spec,m_ambient.z + m_diffuse.z * diff + m_specular.z * spec) ;//*attCoefAtPoint(v.position);

}
