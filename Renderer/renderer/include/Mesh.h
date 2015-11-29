#pragma once
#include "Vertex.h"
#include "MyMath.h"
#include "VertexProcessor.h"
#include "Rasterizer.h"
class Mesh
{
public:
	Mesh();
	Mesh(Vertex *vert_, int3 *ind_);
	~Mesh();

	void Draw(Rasterizer &rasterizer, VertexProcessor &vp);
	void MakeNormals();
public:
	int verticesSize;
	int triangleSize;

	Vertex *vertices;
	int3 *indices;
};

