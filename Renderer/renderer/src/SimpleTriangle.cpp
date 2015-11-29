#include "stdafx.h"
#include "SimpleTriangle.h"


SimpleTriangle::SimpleTriangle()
{
	verticesSize = 3;
	triangleSize = 1;
	vertices = new Vertex[3];
	indices = new int3[1];

	vertices[0].position = float3(-0.5f, 0.0f, 0.f);
	vertices[1].position = float3(0.0f, 0.5f, 0.f);
	vertices[2].position = float3(0.5f, 0.0f, 0.f);
	indices[0] = int3(0, 1, 2);
}

SimpleTriangle::SimpleTriangle(float3 a, float3 b, float3 c)
{
	verticesSize = 3;
	triangleSize = 1;
	vertices = new Vertex[3];
	indices = new int3[1];

	vertices[0].position = a;
	vertices[1].position = b;
	vertices[2].position = c;
	indices[0] = int3(0, 1, 2);
}

SimpleTriangle::~SimpleTriangle()
{
}
