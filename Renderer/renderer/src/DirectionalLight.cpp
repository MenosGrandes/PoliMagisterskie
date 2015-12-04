#include "DirectionalLight.h"
DirectionalLight::DirectionalLight(Vector3Bf pos):ILight(pos)
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
Colour DirectionalLight::calculate(const Fragment& f) const
{
   Vector3Bf N, R, V;
	d_type::Bfloat diff, spec;
	N = f.m_normal;
	V = f.m_negativePosToView;
	Vector3Bf::normalize(V);

//	std::cout<<f.m_normal<<"\n";
//	Vector3Bf::normalize(N);

	R = Vector3Bf::reflect(N,m_position );//m_position.reflect(N);
//	std::cout<<R<<" R\n";
//    R= m_position.reflect(N);
	diff =Vector3Bf::dotProduct(N,m_position);//   osition.DotProduct(N);
	spec = pow(Vector3Bf::dotProduct(R,V),m_shininess);//R.DotProduct(V), shininess);
//	std::cout << diff << "   " << spec << std::endl;
	//return float3(diffuse[0] * diff, diffuse[1] * diff, diffuse[2] * diff);// *attCoefAtPoint(v.position);


	return Colour((m_ambient.x + m_diffuse.x) * diff + m_specular.x * spec, (m_ambient.y + m_diffuse.y) * diff + m_specular.y * spec, (m_ambient.z + m_diffuse.z )* diff + m_specular.z * spec);
}
