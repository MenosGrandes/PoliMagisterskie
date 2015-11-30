#ifndef VERTEX3_H
#define VERTEX3_H
#include "Vector3.h"
#include "Colour.h"

template <typename T>
class Vertex3
{
public:
    Vertex3(const Vector3<T>& thePosition,const Vector2<T>& texCoords,const Vector3<T>& normal):m_position(thePosition),m_texCoords(texCoords),m_normal(normal)
    {}

    Vertex3(const Vector3<T>& thePosition,const Colour&color):m_position(thePosition),m_color(color)
    {}
    Vertex3(const Vector3<T>& thePosition,const Vector3<T>& normal,const Colour&color):m_position(thePosition),m_color(color),m_normal(normal)
    {}

    Vertex3()
    {
    }

    Vector3<T> m_position;
    Vector2<T> m_texCoords;
    Vector3<T> m_normal;
    Colour m_color;
};
typedef Vertex3<d_type::Bfloat>Vertex3Bf;
typedef Vector3<Vertex3Bf> Vector3Vertex3Bf;
#endif // VERTEX3_H
