#include "Vertex3.h"

Vertex3::Vertex3(const Vector3Bf& thePosition):position(thePosition)
{}

Vertex3::Vertex3(const Vector3Bf& thePosition, const Colour& theColor):position(thePosition),color(theColor)
{}

Vertex3::Vertex3(const Vector3Bf& thePosition, const Vector3Bf& theTexCoords):position(thePosition),texCoords(theTexCoords)
{}

Vertex3::Vertex3(const Vector3Bf& thePosition, const Colour& theColor, const Vector3Bf& theTexCoords):position(thePosition),color(theColor),texCoords(theTexCoords)
{}
