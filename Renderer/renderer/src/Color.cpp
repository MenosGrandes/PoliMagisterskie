#include "stdafx.h"
#include "Color.h"

Color Color::COLOR_BLACK = Color();
Color Color::COLOR_RED = Color(255,0,0);
Color Color::COLOR_GREEN = Color(0,255,0);
Color Color::COLOR_BLUE = Color(0,0,255);
Color::Color()
{
	R = G = B = 0.0f;
	A = 255;
}

Color::Color(short R_, short G_, short B_)
{
	R = R_;
	G = G_;
	B = B_;
	A = 255;
}
Color::Color(short R_, short G_, short B_, short A_)
{
	R = R_;
	G = G_;
	B = B_;
	A = A_;
}

uint32_t Color::ToUInt32() 
{
	uint32_t r = (uint32_t)R;
	uint32_t g = (uint32_t)G;
	uint32_t b = (uint32_t)B;
	uint32_t a = (uint32_t)A;

	return (a << 24) | (r << 16) | (g << 8) | b;
}

Color Color::operator + (const Color &c) const
{
	return Color(R + c.R, G + c.G, B + c.B, A + c.A);
}

Color Color::operator - (const Color &c) const
{
	return Color(R - c.R, G - c.G, B - c.B, A - c.A);
}

Color Color::operator * (float f) const
{
	return Color(R * f, G * f, B * f, A * f);
}

Color::~Color()
{
}
