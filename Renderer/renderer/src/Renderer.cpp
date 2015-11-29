// Renderer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyMath.h"
#include "Buffer.h"
#include "Rasterizer.h"
#include "VertexProcessor.h"
#include "SimpleTriangle.h"
#include "Mesh.h"
#include "cObjLoader.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Rasterizer rast = Rasterizer();
	VertexProcessor processor = VertexProcessor();

	processor.SetPerspective(60.0f, 1.0f, 0.1f, 100.0f);
	processor.SetLookAt(float3(0.0f, 0.0f, 20.0f), float3(0.0f, 0.0f, 0.0f), float3(0.0f, 1.0f, 0.0f));
	processor.SetIdentity();

	//SimpleTriangle tri = SimpleTriangle();
	//processor.MultByScale(float3(1.5f, 1.5f, 1.5f));
	////processor.MultByRotation(90.0f, float3(0.0f, 0.0f, 1.0f));
	////processor.MultByTranslation(float3(-1.0f, 0.0f, 0.0f));
	//processor.transformObjToProj();
	//tri.Draw(rast, processor);

	//processor.SetIdentity();
	//processor.MultByScale(float3(1.5f, 1.5f, 1.5f));
	////processor.MultByRotation(90.0f, float3(0.0f, 0.0f, 1.0f));
	//processor.MultByTranslation(float3(5.0f, 0.0f, 10.0f));
	//processor.transformObjToProj();
	//tri.Draw(rast, processor);

	//processor.SetIdentity();
	//tri = SimpleTriangle(float3(-0.5f, 0.0f, 0.f), float3(0.0f, 0.5f, 0.f), float3(0.5f, 0.0f, 0.f));
	//processor.MultByRotation(30.0f, float3(0.0f, 1.0f, 0.0f));
	//processor.MultByScale(float3(2.0f, 2.0f, 2.0f));
	//processor.MultByTranslation(float3(10.0f, 0.0f, 0.0f));
	//processor.transformObjToProj();
	//tri.Draw(rast, processor);

	//processor.SetIdentity();
	//processor.MultByRotation(-45.0f, float3(0.0f, 0.0f, 1.0f));
	//processor.MultByScale(float3(2.0f, 2.0f, 2.0f));
	//processor.MultByTranslation(float3(30.0f, 1.0f, 1.0f));
	//processor.transformObjToProj();
	//processor.MultByTranslation(float3(1.0f, 1.0f, 1.0f));
	//tri.Draw(rast, processor);


	Mesh mesh = cObjLoader().Load("Torus2.obj");
	processor.SetIdentity();
	processor.MultByRotation(90.0f, float3(1.0f, 1.0f, 0.0f));
	processor.MultByTranslation(float3(-3.0f, 0.0f, 0.0f));
	processor.transformObjToProj();
	mesh.Draw(rast, processor);

	processor.SetIdentity();
	processor.MultByRotation(90.0f, float3(-1.0f, -1.0f, 0.0f));
	processor.MultByTranslation(float3(5.0f, 0.0f, 0.0f));
	processor.transformObjToProj();
	mesh.Draw(rast, processor);


	mesh = cObjLoader().Load("pyramid.obj");	
	processor.SetIdentity();
	processor.MultByRotation(45.0f, float3(1.0f, 1.0f, 1.0f));
	processor.MultByTranslation(float3(-1.0f, -1.5f, 2.0f));
	processor.MultByScale(float3(1.5f,1.5f, 1.5f));
	processor.transformObjToProj();
	mesh.Draw(rast, processor);

	mesh = cObjLoader().Load("Teapot.obj");
	processor.SetIdentity();
	processor.MultByRotation(50.0f, float3(1.0f, -1.0f, 0.0f));
	processor.MultByTranslation(float3(0.0f, 5.0f, -3.0f));
	//processor.MultByScale(float3(1.5f,1.5f, 1.5f));
	processor.transformObjToProj();
	mesh.Draw(rast, processor);

	processor.SetIdentity();
	processor.MultByRotation(130.0f, float3(0.0f, 1.0f, 0.0f));
	processor.MultByRotation(30.0f, float3(1.0f, 0.0f, 0.0f));
	processor.MultByTranslation(float3(-6.0f, -2.0f, 0.0f));
	//processor.MultByScale(float3(1.5f,1.5f, 1.5f));
	processor.transformObjToProj();
	mesh.Draw(rast, processor);

	mesh = cObjLoader().Load("Sphere.obj");
	processor.SetIdentity();
	//processor.MultByScale(float3(1.5f,1.5f, 1.5f));
	processor.transformObjToProj();
	mesh.Draw(rast, processor);

	rast.SaveBuffer("render.tga");
	//getchar();
	return 0;
}

