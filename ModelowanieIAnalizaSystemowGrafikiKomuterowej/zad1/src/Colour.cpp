#include "Colour.h"
const Colour Colour::Green=Colour(0,1,0,1);
const Colour Colour::Yellow=Colour(1,1,0,1);
const Colour Colour::Black=Colour(0,0,0,1);
const Colour Colour::White=Colour(1,1,1,1);
const Colour Colour::Red=Colour(1,0,0,1);
const Colour Colour::Blue=Colour(0,0,1,1);
const Colour Colour::Gray=Colour(0.5,0.5,0.5,1);
const Colour Colour::RoyalBlue=Colour(67/255,110/255,238/255,1);



Colour Colour::randomColor()
{
    return Colour(std::rand()%255,std::rand()%255,std::rand()%255,1);
}

Colour Colour::clampColour(Colour c)
{
if(c.r>1 || c.g>1 || c.b>1)
{
    c.r=1;c.g=0;c.b=0;
}
return c;
}
Colour Colour::maxToOne(Colour c)
{
    d_type::Bfloat maxC=std::max(c.r,std::max(c.g,c.b));
    if(maxC> 1)
    {
        return c/maxC;
    }
    else
    {
        return c;
    }
}
