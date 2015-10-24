#ifndef COLOUR_H
#define COLOUR_H
#include "structs.hpp"
#include "Vector2.h"
#include "Vector3.h"
#include <random>
#include <iostream>


class Colour
{
public :
    d_type::Bubyte r,g,b,a;
    Colour(d_type::Bubyte _r,d_type::Bubyte _g,d_type::Bubyte _b,d_type::Bubyte _a):r(_r),g(_g),b(_b),a(_a) {};

    Colour(d_type::Bubyte _r,d_type::Bubyte _g,d_type::Bubyte _b):r(_r),g(_g),b(_b)
    {
        this->a=255;
    };

    Colour():r(255),g(255),b(255),a(255) {};
    Colour(const Colour& next):r(next.r),g(next.g),b(next.b),a(next.a) {};

    static Colour clampColour(Colour r);

    const static  Colour Green;
    const static  Colour Yellow;
    const static  Colour White;
    const static  Colour Black;
    const static  Colour Red;
    const static  Colour Blue;
    const static  Colour Gray;


};

inline Colour operator +( const Colour& left,const  Colour&right)
{
    return Colour(left.r+right.r,left.g+right.g,left.b+right.b,255);
}

template <typename T>
inline Colour operator *( const Colour& left,const  T right)
{
    return Colour(left.r*right,left.g*right,left.b*right,255);
}

template <typename T>
inline Colour operator *( const T left,const  Colour &right)
{
    return Colour(right.r*left,right.g*left,right.b*left,255);
}
template <typename T>
inline Colour operator -( const Colour& left,const  Colour &right)
{
    return Colour(left.r-right.r,left.g-right.g,left.b-right.b,255);
}
inline Colour operator *( const Colour& left,const  Colour &right)
{
    return Colour(left.r*right.r,left.g*right.g,left.b*right.b,255);
}
template <typename T>
inline Colour operator /( const Colour& left,const  T right)
{
    return Colour(left.r/right,left.g/right,left.b/right,255);
}

inline Colour operator +=(Colour& left, const Colour& right)
{
    left.r += right.r;
    left.g += right.g;
    left.b += right.b;
    left.a =255;

    return left;
}
struct ColorDepth
{
    Colour color;
    d_type::Bfloat depth;
};
#endif // COLOUR_H


