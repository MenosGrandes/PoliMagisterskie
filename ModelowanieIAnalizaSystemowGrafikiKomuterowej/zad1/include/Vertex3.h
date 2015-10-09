#ifndef VERTEX3_H
#define VERTEX3_H
#include "Vector3.h"
#include "Colour.h"
using namespace c;
class Vertex3
{
    Vertex3();

    Vertex3(const Vector3Bf& thePosition);
    Vertex3(const Vector3Bf& thePosition, const Colour& theColor);
    Vertex3(const Vector3Bf& thePosition, const Vector3Bf& theTexCoords);
    Vertex3(const Vector3Bf& thePosition, const Colour& theColor, const Vector3Bf& theTexCoords);
//MEMBERS
    Vector3Bf position;
    Vector3Bf texCoords;
    Colour color;
};

#endif // VERTEX3_H
