#include "DirectionalLight.h"
DirectionalLight::DirectionalLight(Vector3Bf pos)
{

}

DirectionalLight::DirectionalLight()
{
    //ctor
}

DirectionalLight::~DirectionalLight()
{
    //dtor
}
Vector3Bf DirectionalLight::calculate(Fragment& f) const
{
   Vector3Bf N, R, V;
	d_type::Bfloat diff, spec;
	N = f.m_normal;
	V = f.m_negativePosToView;
	Vector3Bf::normalize(V);

	R = Vector3Bf::reflect(m_position,N);//m_position.reflect(N);

	diff =Vector3Bf::dotProduct(m_position,N);//   osition.DotProduct(N);
	spec = pow(Vector3Bf::dotProduct(R,V),m_shininess);//R.DotProduct(V), shininess);
	//cout << diff << "   " << spec << endl;
	//return float3(diffuse[0] * diff, diffuse[1] * diff, diffuse[2] * diff);// *attCoefAtPoint(v.position);


	return Vector3Bf(m_ambient.x + m_diffuse.x * diff + m_specular.x * spec, m_ambient.y + m_diffuse.y * diff + m_specular.y * spec, m_ambient.z + m_diffuse.z * diff + m_specular.z * spec);
}
