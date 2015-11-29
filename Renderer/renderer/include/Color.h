#pragma once
#include <stdint.h>
class Color
{
public:
	Color();
	Color(short R_, short G_, short B_);
	Color(short R_, short G_, short B_, short A_);
	uint32_t ToUInt32();
	Color operator + (const Color &c) const;
	Color operator - (const Color &c) const;
	Color operator * (float f) const;
	~Color();
public:
	short R;
	short G;
	short B;
	short A;

	static Color COLOR_BLACK;
	static Color COLOR_RED;
	static Color COLOR_GREEN;
	static Color COLOR_BLUE;
};

