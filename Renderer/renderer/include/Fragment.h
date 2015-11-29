#pragma once
#include "Vertex.h"
class Fragment :
	public Vertex
{
public:
	Fragment();
	~Fragment();
public:
	float3 negativePosToView;
};

