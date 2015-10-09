#ifndef COLOUR_H
#define COLOUR_H
#include "structs.hpp"
namespace c
{

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
    const static  Colour Green;
    const static  Colour Yellow;
    const static  Colour White;
    const static  Colour Black;


};
}

#endif // COLOUR_H


