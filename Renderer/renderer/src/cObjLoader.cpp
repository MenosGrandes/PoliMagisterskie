#include "stdafx.h"
#include "cObjLoader.h"

/* Konstruktory i desktruktory*/
cObjLoader::cObjLoader()
{
}


cObjLoader::~cObjLoader()
{
}

/* G³ówna metoda parsuj¹ca */
Mesh cObjLoader::Load(char* filename)
{

	/* Wektor przechowujacy indeksy wierzcho³ków*/
	std::vector< int3 > vertexPositionIndices, uvIndices, normalIndices;
	std::vector< float3 > temp_vertices_pos;
	std::vector< float3 > temp_normals;
	std::vector< vec2UV > temp_uvs;
	char* temp_mat_name = new char[80];

	/*
	PARSOWANIE OBJ
	*/
	FILE * file;
	errno_t errorCode = fopen_s(&file, filename, "r");
	if (file == NULL){
		printf("Nie moge odczytac podanego pliku .obj !\n");
		return Mesh();
	}

	while (1){

		char lineHeader[128];
		// Wczytuje pierwszy wyraz pliku
		int res = fscanf_s(file, "%s", lineHeader, 128);
		if (res == EOF)
			break;
		// Parsowanie
		if (strcmp(lineHeader, "v") == 0){
			float3 vertex;
			fscanf_s(file, "%f %f %f\n", &vertex.x(), &vertex.y(), &vertex.z());
			temp_vertices_pos.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0){
			vec2UV uv;
			fscanf_s(file, "%f %f\n", &uv.u, &uv.v);
			//uv.v = -uv.v; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0){
			float3 normal;
			fscanf_s(file, "%f %f %f\n", &normal.x(), &normal.y(), &normal.z());
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0){
			std::string vertex1, vertex2, vertex3;
			int3 vertexIndex, uvIndex, normalIndex;
			int matches = fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if (matches != 9){
				printf("Plik nie moze zostac sparsowany. Jego format jest nieobslugiwany \n");
				return Mesh();
			}

			int tmp = vertexIndex[0];
			vertexIndex[0] = vertexIndex[1];
			vertexIndex[1] = tmp;
			vertexIndex[0] -= 1;
			vertexIndex[1] -= 1;
			vertexIndex[2] -= 1;
			uvIndex[0] -= 1;
			uvIndex[1] -= 1;
			uvIndex[2] -= 1;
			normalIndex[0] -= 1;
			normalIndex[1] -= 1;
			normalIndex[2] -= 1;

			vertexPositionIndices.push_back(vertexIndex);
			uvIndices.push_back(uvIndex);
			normalIndices.push_back(normalIndex);
		}
	}

	Mesh tmpMesh = Mesh();
	tmpMesh.triangleSize = vertexPositionIndices.size();
	tmpMesh.verticesSize = temp_vertices_pos.size();
	tmpMesh.indices = new int3[tmpMesh.triangleSize];
	tmpMesh.vertices = new Vertex[tmpMesh.verticesSize];

	for (int i = 0; i < temp_vertices_pos.size(); i++)
	{
		// TO DO: normalne!!!
		tmpMesh.vertices[i] = Vertex(temp_vertices_pos[i], float3());
	}

	for (int i = 0; i < vertexPositionIndices.size(); i++)
	{
		tmpMesh.indices[i] = vertexPositionIndices[i];
	}	
	
	
	return tmpMesh;
}