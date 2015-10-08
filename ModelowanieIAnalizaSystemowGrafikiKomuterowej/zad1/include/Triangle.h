#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vector2.h"
using namespace d_type;
template <typename T>
class Triangle
{
public :
    Triangle(Vector2<T> first,Vector2<T> second,Vector2<T> third):first(first),second(second),third(third) {}

    Triangle() :first(0),second(0),third(0) {};


    BBool calculate(Vector2<T> current)
    {
        if(!first || !second || !third)
        {
            return false;
        }
        return ((first.x-second.x)*(current.y-first.y) -(first.y-second.y)*(current.x - first.x )>0)
               &&((second.x-third.x)*(current.y-second.y)-(second.y-third.y)*(current.x - second.x)>0)
               &&((third.x-first.x) *(current.y-third.y) -(third.y-first.y) *(current.x - third.x )>0);
    }

    BBool calculate(T x,T y)
    {
        return ((first.x-second.x)*(y-first.y) -(first.y-second.y)*(x - first.x )>0)
               &&((second.x-third.x)*(y-second.y)-(second.y-third.y)*(x - second.x)>0)
               &&((third.x-first.x) *(y-third.y) -(third.y-first.y) *(x - third.x )>0);


    }

    //MEMBERS
    Vector2<T> first;
    Vector2<T> second;
    Vector2<T> third;

};

typedef Triangle<Bfloat> TriangleFloat;
typedef Triangle<Bdouble> TriangleDouble;
typedef Triangle<Buint> TriangleUint;

#endif // TRIANGLE_H
