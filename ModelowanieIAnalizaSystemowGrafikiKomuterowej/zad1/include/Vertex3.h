#ifndef VERTEX3_H
#define VERTEX3_H
#include "Vector3.h"
#include "Colour.h"
using namespace c;
template <typename T>
class Vertex3
{

Vertex3(const Vector3<T>& thePosition):position(thePosition)
{}


Vertex3(const Vector3<T>& thePosition, const Colour& theColor):position(thePosition),color(theColor)
{}


Vertex3(const Vector3<T>& thePosition, const Vector3<T>& theTexCoords):position(thePosition),texCoords(theTexCoords)
{}


Vertex3(const Vector3<T>& thePosition, const Colour& theColor, const Vector3<T>& theTexCoords):position(thePosition),color(theColor),texCoords(theTexCoords)
{}


Vertex3()
{
}

    Vector3<T> position;
    Vector3<T> texCoords;
    Colour color;
};

#endif // VERTEX3_H
