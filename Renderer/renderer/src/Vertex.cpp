#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex()
{
	position = float3();
	normal = float3();
	normal = float3(1.0f, 1.0f, 1.0f);
}

Vertex::Vertex(float3 pos_, float3 norm_)
{
	position = pos_;
	normal = norm_;
	normal = float3(1.0f, 1.0f, 1.0f);
}

Vertex::Vertex(float3 pos_, float3 norm_, float3 color_)
{
	position = pos_;
	normal = norm_;
	color = color_;
}

Vertex::~Vertex()
{

}
