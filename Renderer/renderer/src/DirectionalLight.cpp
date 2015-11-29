#include "stdafx.h"
#include "DirectionalLight.h"


DirectionalLight::DirectionalLight() : Light()
{
}

DirectionalLight::DirectionalLight(float3 position_) : Light(position_)
{
}

DirectionalLight::DirectionalLight(float3 position_, float3 ambient_, float3 diffuse_, float3 specular_, float shininess_) : Light(position_, ambient_, diffuse_, specular_, shininess_)
{

}

float3 DirectionalLight::calculate(Fragment& v)
{
	float3 N, R, V;
	float diff, spec;
	N = v.normal;
	V = v.negativePosToView;
	V.Normalize();
	R = position.Reflect(N);

	diff = position.DotProduct(N);
	spec = pow(R.DotProduct(V), shininess);
	//cout << diff << "   " << spec << endl;
	//return float3(diffuse[0] * diff, diffuse[1] * diff, diffuse[2] * diff);// *attCoefAtPoint(v.position);
	return float3(ambient[0] + diffuse[0] * diff + specular[0] * spec, ambient[1] + diffuse[1] * diff + specular[1] * spec, ambient[2] + diffuse[2] * diff + specular[2] * spec);
}

DirectionalLight::~DirectionalLight()
{
}
