#include "stdafx.h"
#include "Mesh.h"


Mesh::Mesh()
{
}

Mesh::Mesh(Vertex *vert_, int3 *ind_)
{
	vertices = vert_;
	indices = ind_;
	MakeNormals();
}

void Mesh::Draw(Rasterizer &rasterizer, VertexProcessor &vp)
{
	for (int i = 0; i < triangleSize; i++)
	{
	 //cout << "Triangle:\n[" << indices[i].a() << "] " << vertices[indices[i].a()].position << "[" << indices[i].b() << "] " << vertices[indices[i].b()].position << "[" << indices[i].c() << "] "<< vertices[indices[i].c()].position << "SIZE T: " << triangleSize << ", SIZE V: " << verticesSize << endl;
		//cout << vertices[indices[i].a()].position << ", " << vertices[indices[i].b()].position << ", " << vertices[indices[i].c()].position << endl << endl << vp.tr(vertices[indices[i].a()].position) << ", " << vp.tr(vertices[indices[i].b()].position) << ", " << vp.tr(vertices[indices[i].c()].position) << endl << endl;
		rasterizer.Triangle(
			vp.tr(vertices[indices[i].a()]),
			vp.tr(vertices[indices[i].b()]),
			vp.tr(vertices[indices[i].c()]));
	}
}

void Mesh::MakeNormals()
{
	for (int i = 0; i < verticesSize; i++)
	{
		vertices[i].normal = float3::ZERO;
	}

	float3 n;
	for (int i = 0; i < triangleSize; i++)
	{
		n = (vertices[indices[i].c()].position - vertices[indices[i].a()].position).CrossProduct(
			 vertices[indices[i].b()].position - vertices[indices[i].a()].position);
		n.Normalize();

		vertices[indices[i].a()].normal += n;
		vertices[indices[i].b()].normal += n;
		vertices[indices[i].c()].normal += n;
	}

	for (int i = 0; i < verticesSize; i++)
	{
		vertices[i].normal.Normalize();
	}
}

Mesh::~Mesh()
{
}
