#ifndef VERTEX2_H
#define VERTEX2_H
#include "Vector4.h"
#include "Colour.h"
#include "Matrix4.h"
class Vertex2
{
public:
    Vertex2(const Vector4Bf& thePosition):position(thePosition)
    {}

    Vertex2(const Vector4Bf& thePosition, const Colour& theColor):position(thePosition),color(theColor)
    {}

    Vertex2(const Vector4Bf& thePosition, const Vector2Bf& theTexCoords):position(thePosition),texCoords(theTexCoords)
    {}

    Vertex2(const Vector4Bf& thePosition, const Colour& theColor, const Vector2Bf& theTexCoords):position(thePosition),color(theColor),texCoords(theTexCoords)
    {}

    Vertex2()
    {

    }
    d_type::Bfloat triangleArea(Vertex2 a,Vertex2 b)
    {
        d_type::Bfloat x1=a.position.x-position.x;
        d_type::Bfloat y1=a.position.y-position.y;

        d_type::Bfloat x2=b.position.x-position.x;
        d_type::Bfloat y2=b.position.y-position.y;

        return (x1*y2 -x2*y1);
    }
    Vertex2 perspectiveDivide()
{
    return Vertex2(Vector4Bf(
                  position.x/position.w,
                  position.y/position.w,
                  position.z/position.w,
                  position.w));
}
    Vertex2 transform(Matrix4f  transformM)
    {
        return transformM.Transform(position);
    }

//MEMBERS
    Vector4Bf position;
    Vector2Bf texCoords;
    Colour color;

};
#endif // VERTEX2_H
