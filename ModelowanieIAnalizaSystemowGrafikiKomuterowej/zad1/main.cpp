#include "Image.h"

using namespace d_type;
using namespace d_type::c;
using namespace d_type::eq;
int main(int argc, char **argv)
{

HalfSpaceFloat hs=HalfSpaceFloat(Vector2Bf(100,130),Vector2Bf(150,100),Vector2Bf(100,100));


    //declare image
    Vector2Bs img_size=Vector2Bs(300,300);

    TGAImage *img = new TGAImage(img_size);

    //declare a temporary color variable
    Colour c_inside=Green;
    Colour c_outside=Red;


    //Loop through image and set all pixels to red
    for(Buint x=0; x<img_size.x; x++)
        for(Buint y=0; y<img_size.y; y++)
        {

        hs.calculate(x,y) ? img->setPixel(c_outside,x,y) : img->setPixel(c_inside,x,y);
        }

    //write the image to disk
    img->WriteImage("test.tga");

    delete img;
    return 0;
}
