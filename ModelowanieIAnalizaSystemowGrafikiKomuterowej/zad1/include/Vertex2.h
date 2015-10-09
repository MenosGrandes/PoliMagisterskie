#ifndef VERTEX2_H
#define VERTEX2_H
#include "Vector2.h"
#include "Colour.h"
using namespace c;
class Vertex2
{
public:
    Vertex2();

    Vertex2(const Vector2Bf& thePosition);
    Vertex2(const Vector2Bf& thePosition, const Colour& theColor);
    Vertex2(const Vector2Bf& thePosition, const Vector2Bf& theTexCoords);
    Vertex2(const Vector2Bf& thePosition, const Colour& theColor, const Vector2Bf& theTexCoords);
//MEMBERS
    Vector2Bf position;
    Vector2Bf texCoords;
    Colour color;

};

#endif // VERTEX2_H
