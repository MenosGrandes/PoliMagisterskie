#include "stdafx.h"
#include "PointLight.h"


PointLight::PointLight() : Light()
{
}

PointLight::PointLight(float3 position_) : Light(position_)
{
}

PointLight::PointLight(float3 position_, float3 ambient_, float3 diffuse_, float3 specular_, float shininess_) : Light(position_, ambient_, diffuse_, specular_, shininess_)
{

}

float3 PointLight::calculate(Fragment& v)
{
	float3 N, R, V, L;
	float diff, spec;
	N = v.normal;
	V = v.negativePosToView;
	L = V - position;
	L.Normalize();
	V.Normalize();
	R = L.Reflect(N);

	diff = L.DotProduct(N);
	spec = pow(R.DotProduct(V), shininess);
	//cout << diff << "   " << spec << endl;
	//return float3(diffuse[0] * diff, diffuse[1] * diff, diffuse[2] * diff);// *attCoefAtPoint(v.position);
	return float3(ambient[0] + diffuse[0] * diff + specular[0] * spec, ambient[1] + diffuse[1] * diff + specular[1] * spec, ambient[2] + diffuse[2] * diff + specular[2] * spec) *attCoefAtPoint(v.position);
}

PointLight::~PointLight()
{
}
