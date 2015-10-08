#include "Image.h"
#include <array>
#include <limits>
#include "Triangle.h"
#include "Vector2.h"
#include "Vector3.h"
using namespace d_type;
using namespace c;






int main(int argc, char **argv)
{


Vector3Bf a= Vector3Bf(2.04f,2.12f,2.04f);
Vector3Bf a2= Vector3Bf(2.04f,2.12f,2.04f);
a+=a2;
std::cout<<a.x<<" "<<a.y<<" "<<a.z<<"\n";
    std::array<TriangleFloat*,2> triangleArray;
    TriangleFloat *triangle= new TriangleFloat(Vector2Bf(50,50),Vector2Bf(50,100),Vector2Bf(100,50));
    TriangleFloat *triangle2= new TriangleFloat(Vector2Bf(150,150),Vector2Bf(150,200),Vector2Bf(200,150));
    triangleArray[0]=triangle;
    triangleArray[1]=triangle2;
    //declare image
    Vector2Bs img_size=Vector2Bs(300,300);

    TGAImage *img = new TGAImage(img_size);

    //declare a temporary color variable
    Colour c_inside=Colour::Green,c_outside=Colour::Yellow;

    //Loop through image and set all pixels to red
    for(Buint x=0; x<img_size.x; x++)
        for(Buint y=0; y<img_size.y; y++)
        {
            img->setPixel(c_outside,x,y);
        }



    for(Buint x=0; x<img_size.x; x++)
        for(Buint y=0; y<img_size.y; y++)
        {
            for(TriangleFloat *tri : triangleArray)
            {
                if(tri->calculate(x,y))
                {
                    img->setPixel(c_inside,x,y);
                }


            }

        }

    //write the image to disk
    img->WriteImage("test.tga");
    delete triangle;
    delete img;
    return 0;
}
