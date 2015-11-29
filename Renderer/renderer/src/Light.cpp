#include "stdafx.h"
#include "Light.h"


Light::Light()
{
	position = float3(0.0f, 5.0f, 5.0f);
	ambient = float3(0.1f, 0.1f, 0.1f);
	diffuse = float3(0.7f, 0.7f, 0.7f);
	specular = float3(0.3f, 0.3f, 0.3f);
	shininess = 100;

	cAttenuation = 0.1f;
	lAttenuation = 0.1f;
	qAttenuation = 0.1f;
}

Light::Light(float3 position_)
{
	position = position_;
	ambient = float3(0.1f, 0.1f, 0.1f);
	diffuse = float3(0.7f, 0.7f, 0.7f);
	specular = float3(0.2f, 0.2f, 0.2f);
	shininess = 2;
	cAttenuation = 0.02f;
	lAttenuation = 0.02f;
	qAttenuation = 0.02f;
}

Light::Light(float3 position_, float3 ambient_, float3 diffuse_, float3 specular_, float shininess_)
{
	position = position_;
	ambient = ambient_;
	diffuse = diffuse_;
	specular = specular_;
	shininess = shininess_;
	cAttenuation = 0.02f;
	lAttenuation = 0.02f;
	qAttenuation = 0.02f;
}

float Light::attCoefAtPoint(float3 pos_)
{
	float d = (pos_ - position).Length();
	//cout << 1.0f / (cAttenuation + lAttenuation * d + qAttenuation * d * d) << endl;
	return 1.0f / (cAttenuation + lAttenuation * d + qAttenuation * d * d);
}

Light::~Light()
{
}
