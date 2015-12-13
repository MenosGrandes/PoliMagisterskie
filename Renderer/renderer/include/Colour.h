#ifndef COLOUR_H
#define COLOUR_H
#include "structs.hpp"
#include "Vector2.h"
#include "Vector3.h"
#include <random>
#include <iostream>
#include <ctime>
#include <SFML/Graphics/Color.hpp>
#include "../src/algorithms.hpp"
class Colour
{
public :
    d_type::Bfloat r,g,b,a;
    Colour(d_type::Bfloat _r,d_type::Bfloat _g,d_type::Bfloat _b,d_type::Bfloat _a):r(_r),g(_g),b(_b),a(_a) {};

    Colour(d_type::Bfloat _r,d_type::Bfloat _g,d_type::Bfloat _b):r(_r),g(_g),b(_b),a(1)
    {

    };
    Colour ToColour(const sf::Color &r){
    return Colour(r.r*255,r.g*255,r.b*255,255);
    }
    Colour():r(1),g(1),b(1),a(1) {};
    Colour(const Colour& next):r(next.r),g(next.g),b(next.b),a(next.a) {};


    static Colour clampColour(Colour r);
    static Colour maxToOne(Colour r);

    static Colour randomColor();
    const static  Colour Green;
    const static  Colour Yellow;
    const static  Colour White;
    const static  Colour Black;
    const static  Colour Red;
    const static  Colour Blue;
    const static  Colour Gray;
    const static  Colour RoyalBlue;



};
inline std::ostream& operator<< (std::ostream& stream, const Colour& v)
{
    stream<<"COLOUR :"<<(d_type::Bfloat)v.r<<" "<<(d_type::Bfloat)v.g<<" "<<(d_type::Bfloat)v.b<<"\n";

    return stream;
}
inline Colour operator +( const Colour& left,const  Colour&right)
{
    return Colour(left.r+right.r,left.g+right.g,left.b+right.b,1);
}

template <typename T>
inline Colour operator *( const Colour& left,const  T right)
{
    return Colour(left.r*right,left.g*right,left.b*right,1);
}

template <typename T>
inline Colour operator *( const T left,const  Colour &right)
{
    return Colour(right.r*left,right.g*left,right.b*left,1);
}
template <typename T>
inline Colour operator -( const Colour& left,const  Colour &right)
{
    return Colour(left.r-right.r,left.g-right.g,left.b-right.b,1);
}
inline Colour operator *( const Colour& left,const  Colour &right)
{
    return Colour(left.r*right.r,left.g*right.g,left.b*right.b,1);
}
template <typename T>
inline Colour operator /( const Colour& left,const  T right)
{

    return (Colour (left.r / right, left.g / right, left.b / right,1));
}
template <typename T>
inline void operator /=(  Colour& left,const  T right)
{
    left= Colour(left.r / right, left.g / right, left.b / right,1);


}
inline Colour operator +=(Colour& left, const Colour& right)
{
    left.r += right.r;
    left.g += right.g;
    left.b += right.b;
    left.a =1;

    return left;
}
struct ColorDepth
{
    Colour color;
    d_type::Bfloat depth;
};



#endif // COLOUR_H


