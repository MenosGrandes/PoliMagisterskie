#include "Colour.h"
const Colour Colour::Green=Colour(0,1,0);
const Colour Colour::Yellow=Colour(1,1,0);
const Colour Colour::Black=Colour(0,0,0);
const Colour Colour::White=Colour(1,1,1);
const Colour Colour::Red=Colour(1,0,0);
const Colour Colour::Blue=Colour(0,0,1);
const Colour Colour::Gray=Colour(0.5,0.5,0.5);
const Colour Colour::RoyalBlue=Colour(0.2626,0.5,0.9333);


Colour Colour::powc(d_type::Bfloat p) const
{
    return (Colour(pow(r, p), pow(g, p), pow(b, p)));

}
d_type::Bfloat Colour::getAVG()
{
    return (r+g+b)/3;
}

Colour Colour::randomColor()
{

    return Colour(static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
                  static_cast <float> (rand()) / static_cast <float> (RAND_MAX),
                  static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
}

Colour Colour::clampColour(Colour c)
{
return Colour(std::min(std::max(c.r,0.0f),1.0f),std::min(std::max(c.g,0.0f),1.0f),std::min(std::max(c.b,0.0f),1.0f));

}
Colour Colour::maxToOne(Colour c)
{
    d_type::Bfloat maxC=std::max(std::max(c.r,c.g),c.b);
    if(maxC> 1)
    {
        return c/maxC;
    }
    else
    {
        return c;
    }
}
