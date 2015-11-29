#pragma once
#include "MyMath.h"
#include "Fragment.h"
class Light
{
public:
	Light();
	Light(float3 position_);
	Light(float3 position_, float3 ambient_, float3 diffuse_, float3 specular_, float shininess_);

	float attCoefAtPoint(float3 pos_);
	virtual float3 calculate(Fragment& v) = 0;
	~Light();
public:
	float3 position;
	float3 ambient;
	float3 diffuse;
	float3 specular;
	float shininess;

	float cAttenuation;
	float lAttenuation;
	float qAttenuation;
};

