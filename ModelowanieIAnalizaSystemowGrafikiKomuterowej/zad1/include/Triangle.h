#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vector2.h"
#include "Vector4.h"
#include "Vector3.h"

#include "../src/algorithms.hpp"
#include "Drawable.h"
#include "Colour.h"
#include <iostream>
using namespace d_type;
using namespace c;
template <typename T>
class Triangle :  Drawable
{
public :
    Triangle(Vector2<T> first,Vector2<T> second,Vector2<T> third):first(first),second(second),third(third)
    {

        Greatest g;
        Smallest s;


        this->rect=Vector4<T>(
                       s.min(first.x,second.x,third.x),
                       g.max(first.x,second.x,third.x),
                       s.min(first.y,second.y,third.y),
                       g.max(first.y,second.y,third.y));

        /*
        this->rect=Vector4<T>();

        this->rect.x=s.min(first.x,second.x,third.x);
        this->rect.y=g.max(first.x,second.x,third.x);

        this->rect.z=s.min(first.y,second.y,third.y);
        this->rect.w=g.max(first.y,second.y,third.y);
        */
        this->dx=Vector3<T>(first.x-second.x,second.x-third.x,third.x-first.x);
        this->dy=Vector3<T>(first.y-second.y,second.y-third.y,third.y-first.y);

        this->topLeft =Vector3Bb(dy.x < 0 || (dy.x == 0 && dx.x > 0), dy.y < 0 || (dy.y == 0 && dx.y > 0), dy.z < 0 || (dy.z == 0 && dx.z > 0) );


    }

    Triangle() :first(0),second(0),third(0) {};

    BBool calculate(Vector2<T> current)
    {
        if(!first || !second || !third)
        {
            return false;
        }
        return ((dx.x) * (current.y-first.y) - (dy.x)*(current.x - first.x )>0)
               &&((dx.y) * (current.y-second.y)- (dy.y)*(current.x - second.x)>0)
               &&((dx.z) * (current.y-third.y) - (dy.z) *(current.x - third.x)>0);
    }

    BBool calculate(T x,T y)
    {


        if(topLeft.x && topLeft.y &&!topLeft.z)
        {
            return   ((dx.x) * (y-first.y) - (dy.x) * (x - first.x )>0)
                   &&((dx.y) * (y-second.y)- (dy.y) * (x - second.x)>0)
                   &&((dx.z) * (y-third.y) - (dy.z) * (x - third.x )>=0);
        }
        else if(topLeft.x && !topLeft.y&&!topLeft.z)
        {
            return   ((dx.x) * (y-first.y) - (dy.x) * (x - first.x )>0)
                   &&((dx.y) * (y-second.y)- (dy.y) * (x - second.x)>=0)
                   &&((dx.z) * (y-third.y) - (dy.z) * (x - third.x )>=0);
        }
        else if (topLeft.y && !topLeft.x&&!topLeft.z)
        {
            return   ((dx.x) * (y-first.y) - (dy.x) * (x - first.x )>=0)
                   &&((dx.y) * (y-second.y)- (dy.y) * (x - second.x)>0)
                   &&((dx.z) * (y-third.y) - (dy.z) * (x - third.x )>=0);
        }
        else if (topLeft.y && topLeft.z && !topLeft.x)
        {
            return   ((dx.x) * (y-first.y) - (dy.x) * (x - first.x )>=0)
                   &&((dx.y) * (y-second.y)- (dy.y) * (x - second.x)>0)
                   &&((dx.z) * (y-third.y) - (dy.z) * (x - third.x )>0);
        }
        else  if(topLeft.z && !topLeft.y && !topLeft.x)

        {
            return   ((dx.x) * (y-first.y) - (dy.x) * (x - first.x )>=0)
                   &&((dx.y) * (y-second.y)- (dy.y) * (x - second.x)>=0)
                   &&((dx.z) * (y-third.y) - (dy.z) * (x - third.x )>0);
        }
        else if (topLeft.z && topLeft.x && !topLeft.y)
        {
            return   ((dx.x) * (y-first.y) - (dy.x) * (x - first.x )>0)
                   &&((dx.y) * (y-second.y)- (dy.y) * (x - second.x)>=0)
                   &&((dx.z) * (y-third.y) - (dy.z) * (x - third.x )>0);
        }

    }



    Colour calculateLambdaColor(T x,T y,const Colour &c,const Colour &c2,const Colour &c3)
    {
        T l1=((dy.y)*(x-third.x)+(third.x - second.x)*(y-third.y) ) /((dy.y)*(first.x-third.x)+(third.x - second.x)*(first.y-third.y));
        T l2= (dy.z*(x-third.x)+(first.x-third.x)*(y-third.y))/((dy.z*dx.y) +( (first.x-third.x)*(dy.y)));
        T l3= 1 - l1 - l2;

        return Colour(
        l1*c.r,
        c2.g*l2,
        l3*c3.b ,255);

    }
    Colour calculateLambdaColor(T x,T y)
    {
        T l1=((dy.y)*(x-third.x)+(third.x - second.x)*(y-third.y) ) /((dy.y)*(first.x-third.x)+(third.x - second.x)*(first.y-third.y));
        T l2= (dy.z*(x-third.x)+(first.x-third.x)*(y-third.y))/((dy.z*dx.y) +( (first.x-third.x)*(dy.y)));
        T l3= 1 - l1 - l2;

        return Colour(l1*255,l2*255,l3*255 ,255);

    }
    void draw(RenderTarget&target)
    {
        //target.draw();
    };
//MEMBERS
    Vector2<T> first;
    Vector2<T> second;
    Vector2<T> third;
    Vector4<T> rect;
private :
    Vector3<T> dx;
    Vector3<T> dy;
    Vector3Bb topLeft;



};

typedef Triangle<Bfloat> TriangleFloat;
typedef Triangle<Bdouble> TriangleDouble;
typedef Triangle<Buint> TriangleUint;

#endif // TRIANGLE_H
