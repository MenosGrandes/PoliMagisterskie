#pragma once
#include "Light.h"
class DirectionalLight :
	public Light
{
public:
	DirectionalLight();
	DirectionalLight(float3 position_);
	DirectionalLight(float3 position_, float3 ambient_, float3 diffuse_, float3 specular_, float shininess_);
	virtual float3 calculate(Fragment& v);

	~DirectionalLight();
};

