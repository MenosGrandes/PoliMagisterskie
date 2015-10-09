#include "Vertex2.h"

Vertex2::Vertex2(const Vector2Bf& thePosition):position(thePosition)
{}

Vertex2::Vertex2(const Vector2Bf& thePosition, const Colour& theColor):position(thePosition),color(theColor)
{}

Vertex2::Vertex2(const Vector2Bf& thePosition, const Vector2Bf& theTexCoords):position(thePosition),texCoords(theTexCoords)
{}

Vertex2::Vertex2(const Vector2Bf& thePosition, const Colour& theColor, const Vector2Bf& theTexCoords):position(thePosition),color(theColor),texCoords(theTexCoords)
{}
