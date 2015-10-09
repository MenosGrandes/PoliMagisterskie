#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vector2.h"
#include "Vector4.h"
#include "../src/algorithms.hpp"
#include "Drawable.h"
using namespace d_type;
template <typename T>
class Triangle :  Drawable
{
public :
    Triangle(Vector2<T> first,Vector2<T> second,Vector2<T> third):first(first),second(second),third(third)
    {

        Greatest g;
        Smallest s;
        this->rect=Vector4<T>();

        this->rect.x=s.min(first.x,second.x,third.x);
        this->rect.y=g.max(first.x,second.x,third.x);

        this->rect.z=s.min(first.y,second.y,third.y);
        this->rect.w=g.max(first.y,second.y,third.y);
    }

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
        return (( first.x-second.x)*(y-first.y) -(first.y-second.y)*(x - first.x )>0)
               &&((second.x-third.x)*(y-second.y)-(second.y-third.y)*(x - second.x)>0)
               &&((third.x-first.x) *(y-third.y) -(third.y-first.y) *(x - third.x )>0);


    }

    void draw(RenderTarget&target){

    };
    //MEMBERS
    Vector2<T> first;
    Vector2<T> second;
    Vector2<T> third;
    Vector4<T> rect;


};

typedef Triangle<Bfloat> TriangleFloat;
typedef Triangle<Bdouble> TriangleDouble;
typedef Triangle<Buint> TriangleUint;

#endif // TRIANGLE_H
