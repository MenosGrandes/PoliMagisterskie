#ifndef VERTEX2_H
#define VERTEX2_H
#include "Vector2.h"
#include "Colour.h"

template <typename T>
class Vertex2
{
public:
    Vertex2(const Vector2<T>& thePosition):position(thePosition)
    {}

    Vertex2(const Vector2<T>& thePosition, const Colour& theColor):position(thePosition),color(theColor)
    {}

    Vertex2(const Vector2<T>& thePosition, const Vector2<T>& theTexCoords):position(thePosition),texCoords(theTexCoords)
    {}

    Vertex2(const Vector2<T>& thePosition, const Colour& theColor, const Vector2<T>& theTexCoords):position(thePosition),color(theColor),texCoords(theTexCoords)
    {}

    Vertex2()
    {

    }

//MEMBERS
    Vector2<T> position;
    Vector2<T> texCoords;
    Colour color;

};

#endif // VERTEX2_H
