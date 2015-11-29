#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "MyMath.h"
#include "Mesh.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

class cObjLoader
{
public:
	/* Konstruktory i desktruktory*/
	cObjLoader();
	~cObjLoader();

	/* Metody pomocnicze */
	std::vector<float3> getVerticesPostions();
	std::vector<float3> getVerticesNormals();
	std::vector<vec2UV> getVerticesUVs();

	/* G³ówna metoda parsuj¹ca */
	Mesh Load(char* filename);
private:
	std::vector<float3> VerticesPositions;
	std::vector<vec2UV> VerticesUVs;
	std::vector<float3> VerticesNormals;
};

