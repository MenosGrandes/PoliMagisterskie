#include "stdafx.h"
#include "Buffer.h"


Buffer::Buffer()
{
}

Buffer::Buffer(int width_, int height_)
{
	Width = width_;
	Height = height_;
	colorBuffer = new Color[Width * Height];
	depthBuffer = new float[Width * Height];
	ClearColorBuffer();
	ClearDepthBuffer();
}

void Buffer::SaveBufferToTga(char* filename)
{
	unsigned short header[9] = { 0x0000, 0x0002, 0x0000, 0x0000, 0x0000, 0x0000, 0x0100, 0x0100, 0x0820};
	FILE *f;
	errno_t err = fopen_s(&f, filename, "wb+");
	if (f == NULL)
		return ;
	header[6] = this->Width;
	header[7] = Width;
	fwrite(header, 2, 9, f);
	fwrite(ColorBufferAsUINT(), 4, Width*Height, f);
	fclose(f);
}

void Buffer::ClearColorBuffer()
{
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			colorBuffer[convert2dto1d(i, j)] = Color::COLOR_BLACK;
		}
	}
}

void Buffer::ClearDepthBuffer()
{
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			depthBuffer[convert2dto1d(i, j)] = FLT_MAX;
		}
	}
}
int Buffer::convert2dto1d(int x, int y) {
	return Width * y + x;
}

uint32_t* Buffer::ColorBufferAsUINT()
{
	uint32_t *buff = new uint32_t[Width*Height];
	for (int i = 0; i < Width; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			buff[convert2dto1d(i, j)] = colorBuffer[convert2dto1d(i, j)].ToUInt32();
		}
	}

	return buff;
}

float Buffer::GetDepthAtPixel(int x_, int y_)
{
	return depthBuffer[convert2dto1d(x_, y_)];
}

void Buffer::SetPixel(int x, int y, const Color &color, float depth_)
{
	colorBuffer[convert2dto1d(x, y)] = color;
	depthBuffer[convert2dto1d(x, y)] = depth_;
}

Buffer::~Buffer()
{
}
