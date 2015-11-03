#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Vector4.h"
#include "Vector3.h"
#include "Colour.h"
#include "../src/algorithms.hpp"
#include <iostream>
using namespace d_type;
namespace render
{


template <typename T>
class Triangle
{
public :
    Triangle(Vector3<T> first,Vector3<T> second,Vector3<T> third):first(first),second(second),third(third) {}

    void init(const Vector2Bs& m_size)
    {

        Greatest g;
        Smallest s;

//CANONIC VIEW
        this->first.x=(this->first.x+1)*m_size.x*0.5f;
        this->first.y=(this->first.y+1)*m_size.y*0.5f;

        this->second.x=(this->second.x+1)*m_size.x*0.5f;
        this->second.y=(this->second.y+1)*m_size.y*0.5f;

        this->third.x=(this->third.x+1)*m_size.x*0.5f;
        this->third.y=(this->third.y+1)*m_size.y*0.5f;

//Calculate rect where this triangle is
        this->rect=Vector4<T>(s.min(first.x,second.x,third.x),g.max(first.x,second.x,third.x),s.min(first.y,second.y,third.y),g.max(first.y,second.y,third.y));
//Ommit those pixel that are not in buffer.
        this->rect.x=std::max(this->rect.x,0.f);
        this->rect.y=std::min(this->rect.y,static_cast<Bfloat>(m_size.x-1));
        this->rect.z=std::max(this->rect.z,0.f);
        this->rect.w=std::min(this->rect.w,static_cast<Bfloat>(m_size.y-1));
//calculate the constants
        this->dx=Vector3<T>(first.x-second.x,second.x-third.x,third.x-first.x);
        this->dy=Vector3<T>(first.y-second.y,second.y-third.y,third.y-first.y);
//TopLeft
        this->topLeft =Vector3Bb(dy.x < 0 || (dy.x == 0 && dx.x > 0), dy.y < 0 || (dy.y == 0 && dx.y > 0), dy.z < 0 || (dy.z == 0 && dx.z > 0) );

    }

    Triangle() :first(),second(),third()
    {

    };



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
        return false;

    }


    T calculateDepth(Vector3<T> lambda)
    {
        //std::cout<<(lambda.x * first.z + lambda.y *second.z + lambda.z * third.z)<<"\n";
        return (lambda.x * first.z + lambda.y *second.z + lambda.z * third.z);
    }
    ColorDepth calculateLambdaColor(T x,T y,const Colour &c,const Colour &c2,const Colour &c3)
    {
        T l1=((dy.y)*(x-third.x)+(third.x - second.x)*(y-third.y) ) /((dy.y)*(first.x-third.x)+(third.x - second.x)*(first.y-third.y));
        T l2= (dy.z*(x-third.x)+(first.x-third.x)*(y-third.y))/((dy.z*dx.y) +( (first.x-third.x)*(dy.y)));
        T l3= 1 - l1 - l2;

        Colour tmp = l1*c +l2*c2+l3*c3 ;//+ l2 * c2 + l3 * c3;

        ColorDepth d;
        d.color=tmp;
        d.depth=calculateDepth(Vector3<T>(l1,l2,l3));

        return d;


    }
    ColorDepth calculateLambdaColor(T x,T y)
    {
        T l1=((dy.y)*(x-third.x)+(third.x - second.x)*(y-third.y) ) /((dy.y)*(first.x-third.x)+(third.x - second.x)*(first.y-third.y));
        T l2= (dy.z*(x-third.x)+(first.x-third.x)*(y-third.y))/((dy.z*dx.y) +( (first.x-third.x)*(dy.y)));
        T l3= 1 - l1 - l2;


        ColorDepth d;
        d.color=Colour(l1*255,l2*255,l3*255 ,255);
        d.depth=calculateDepth(Vector3<T>(l1,l2,l3));

        return d;

    }

//MEMBERS

    Vector3<T> first;
    Vector3<T> second;
    Vector3<T> third;
    Vector4<T> rect;
private :



    Vector3<T> dx;
    Vector3<T> dy;
    Vector3Bb topLeft;


};

typedef Triangle<Bfloat> TriangleFloat;
typedef Triangle<Bdouble> TriangleDouble;
typedef Triangle<Buint> TriangleUint;
}
#endif // TRIANGLE_H
