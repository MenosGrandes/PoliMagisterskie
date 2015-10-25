#include "Colour.h"
const Colour Colour::Green=Colour(0,255,0,255);
const Colour Colour::Yellow=Colour(255,255,0,255);
const Colour Colour::Black=Colour(0,0,0,255);
const Colour Colour::White=Colour(255,255,255,255);
const Colour Colour::Red=Colour(255,0,0,255);
const Colour Colour::Blue=Colour(0,0,255,255);
const Colour Colour::Gray=Colour(128,128,128,255);
const Colour Colour::RoyalBlue=Colour(67,110,238,255);




Colour Colour::clampColour(Colour c)
{
//    c.r =c.r <0 ? 0 :  c.r> 255 ? 255 :c.r ;
//    c.g =c.g <0 ? 0 :  c.g> 255 ? 255 :c.g ;
    c.b =c.b <0 ? 0 :  c.b> 255 ? 255 :c.b ;
if(c.r<0)
{

    c.r=0;

}
else if(c.r>255)
{
    c.r=255;
}

///////////////////////////////

if(c.g<0)
{

    c.g=0;

}
else if(c.g>255)
{
    c.g=255;
}
///////////////////////////////
if(c.b<0)
{

    c.b=0;

}
else if(c.b>255)
{
    c.g=255;
}
    c.a=255;
    return c;
}
