#include "stdafx.h"
#include "VertexProcessor.h"


VertexProcessor::VertexProcessor()
{
}

void VertexProcessor::SetPerspective(float FOVy_, float aspect, float near, float far)
{
	float fovy = FOVy_ * PI_ / 360.0f;
	float f = cos(fovy) / sin(fovy);
	viewToProjection[0] = float4(f / aspect, 0.0f, 0.0f, 0.0f);
	viewToProjection[1] = float4(0.0f, f, 0.0f, 0.0f);
	viewToProjection[2] = float4(0.0f, 0.0f, (far + near) / (near - far), -1.0f);
	viewToProjection[3] = float4(0.0f, 0.0f, 2.0f * far *near / (near - far), 0.0f);
}

void VertexProcessor::SetLookAt(float3 eye, float3 center, float3 up)
{
	float3 f = center - eye;
	f.Normalize();
	up.Normalize();
	float3 s = float3::CrossProduct(f, up);
	float3 u = float3::CrossProduct(s, f);

	worldToView[0] = float4(s[0], u[0], -f[0], 0.0f);
	worldToView[1] = float4(s[1], u[1], -f[1], 0.0f);
	worldToView[2] = float4(s[2], u[2], -f[2], 0.0f);
	worldToView[3] = float4(-eye.x(), - eye.y(), - eye.z(), 1.0f);
}

void VertexProcessor::MultByTranslation(float3 v)
{
	float4x4 m = float4x4(
		float4(1.0f, 0.0f, 0.0f, 0.0f),
		float4(0.0f, 1.0f, 0.0f, 0.0f),
		float4(0.0f, 0.0f, 1.0f, 0.0f),
		float4(v.x(), v.y(), v.z(), 1.0f));
	objToWorld = float4x4::MultiplyFloat4x4ByFloat4x4(m, objToWorld);
}

void VertexProcessor::MultByScale(float3 v)
{
	float4x4 m = float4x4(
		float4(v.x(), 0.0f, 0.0f, 0.0f),
		float4(0.0f, v.y(), 0.0f, 0.0f),
		float4(0.0f, 0.0f, v.z(), 0.0f),
		float4(0.0f, 0.0f, 0.0f, 1.0f));
	objToWorld = float4x4::MultiplyFloat4x4ByFloat4x4(m, objToWorld);
}

void VertexProcessor::MultByRotation(float angle, float3 v)
{
	v.Normalize();
	float s = sin(angle * PI_ / 180.0f);
	float c = cos(angle * PI_ / 180.0f);

	float4x4 m = float4x4(
		float4(v.x() * v.x() * (1.0f - c) + c,		   v.y() * v.x() * (1.0f - c) + v.z() * s, v.x() * v.z() * (1.0f - c) - v.y() * s, 0.0f),
		float4(v.x() * v.y() * (1.0f - c) - v.z() * s, v.y() * v.y() * (1.0f - c) + c		 , v.y() * v.z() * (1.0f - c) + v.x() * s, 0.0f),
		float4(v.x() * v.z() * (1.0f - c) + v.y() * s, v.y() * v.z() * (1.0f - c) - v.x() * s, v.z() * v.z() * (1.0f - c) + c		 , 0.0f),
		float4(0.0f, 0.0f, 0.0f, 1.0f));
	objToWorld = float4x4::MultiplyFloat4x4ByFloat4x4(m, objToWorld);
}

Vertex VertexProcessor::tr(Vertex v)
{
	Fragment frag = Fragment();

	PointLight light = PointLight(float3(0.0f, 5.0f, 5.0f));
	//DirectionalLight light = DirectionalLight(float3(0.0f, 10.0f, 20.0f));
	float4 p = float4x4::MultiplyFloat4x4ByFloat3(objToProjection, v.position);

	// Przekszta³cenia do wyliczenia œwiat³a
	float4 lp = float4x4::MultiplyFloat4x4ByFloat3(objToView, -v.position);
	float4 n = float4x4::MultiplyFloat4x4ByFloat3(objToView, v.normal);

	frag.position = v.position;
	frag.normal = float3(n.x() / n.w(), n.y() / n.w(), n.z() / n.w());
	frag.normal.Normalize();
	frag.negativePosToView = float3(lp.x() / lp.w(), lp.y() / lp.w(), lp.z() / lp.w());

	float3 L = light.calculate(frag);
	//cout << L;
	return Vertex(float3(p.x() / p.w(), p.y() / p.w(), p.z() / p.w()),
		v.normal,
		L);
}

float3 VertexProcessor::lt(float3)
{
	return float3();
}

void VertexProcessor::transformObjToProj()
{
	objToView = float4x4::MultiplyFloat4x4ByFloat4x4(worldToView, objToWorld);
	objToProjection = float4x4::MultiplyFloat4x4ByFloat4x4(viewToProjection, objToView);
}

void VertexProcessor::SetIdentity()
{
	objToWorld = float4x4(
		float4(1.0f, 0.0f, 0.0f, 0.0f),
		float4(0.0f, 1.0f, 0.0f, 0.0f),
		float4(0.0f, 0.0f, 1.0f, 0.0f),
		float4(0.0f, 0.0f, 0.0f, 1.0f));
}

VertexProcessor::~VertexProcessor()
{
}
