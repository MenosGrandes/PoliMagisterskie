#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include "Color.h"
#include <string>
#include <stdio.h>
class Buffer
{
public:
	Buffer();
	Buffer(int width_, int height_);
	~Buffer();

	int GetBufferWidth() { return Width; }
	int GetBufferHeight() { return Height; }
	void ClearColorBuffer();
	void ClearDepthBuffer();
	float GetDepthAtPixel(int x_, int y_);
	void SetPixel(int x, int y, const Color &color, float depth_);

	void SaveBufferToTga(char* filename);
private:
	Color * colorBuffer;
	float * depthBuffer;
	int Width;
	int Height;
	float minX;
	float maxX;
	float minY;
	float maxY;
	float lenght;
	int convert2dto1d(int x, int y);
	uint32_t *ColorBufferAsUINT();
};

