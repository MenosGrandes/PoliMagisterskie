#include "Image.h"

using namespace d_type;
using namespace d_type::c;

int main(int argc, char **argv)
{

    //declare image
    Vector2Bs img_size=Vector2Bs(800,800);

    TGAImage *img = new TGAImage(img_size);

    //declare a temporary color variable
    Colour c=Green;


    //Loop through image and set all pixels to red
    for(int x=0; x<img_size.x; x++)
        for(int y=0; y<img_size.y; y++)
        {
            img->setPixel(c,x,y);
        }

    //write the image to disk
    img->WriteImage("test.tga");

    delete img;
    return 0;
}
