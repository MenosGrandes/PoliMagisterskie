#include "Image.h"
#include "Triangle.h"
#include "Matrix4.h"

#include <cstdio>
#include <iostream>
#include <array>
#include <limits>


using namespace d_type;
using namespace c;






int main(int argc, char **argv)
{

    TriangleFloat t= TriangleFloat();



    std::array<TriangleFloat*,2> triangleArray;
    TriangleFloat *triangle= new TriangleFloat(Vector2Bf(50,50),Vector2Bf(50,100),Vector2Bf(100,50));
    TriangleFloat *triangle2= new TriangleFloat(Vector2Bf(100,50),Vector2Bf(50,100),Vector2Bf(150,100));
    triangleArray[0]=triangle;
    triangleArray[1]=triangle2;
    //declare image
    Vector2Bs img_size=Vector2Bs(300,300);
    TGAImage *file = new TGAImage(img_size,"file.tga");


    triangle2->rect.x=std::max(triangle2->rect.x,0.f);
    triangle2->rect.y=std::min(triangle2->rect.y,static_cast<Bfloat>(img_size.x-1));
    triangle2->rect.z=std::max(triangle2->rect.z,0.f);
    triangle2->rect.w=std::min(triangle2->rect.w,static_cast<Bfloat>(img_size.y-1));

    triangle->rect.x=std::max(triangle->rect.x,0.f);
    triangle->rect.y=std::min(triangle->rect.y,static_cast<Bfloat>(img_size.x-1));
    triangle->rect.z=std::max(triangle->rect.z,0.f);
    triangle->rect.w=std::min(triangle->rect.w,static_cast<Bfloat>(img_size.y-1));


    for(TriangleFloat *tri : triangleArray)
    {
        for(Bfloat x =tri->rect.x; x<tri->rect.y; x++)
        {
            for(Bfloat y=tri->rect.z; y<tri->rect.w; y++)
            {
                if(tri->calculate(x,y))
                {

                    file->setPixel(tri->calculateLambdaColor(x,y),x,y);

                }

            }
        }

    }
    //file->draw(t);
    file->draw();

    for(Bsize i=0; i<triangleArray.size(); i++)
    {
        delete triangleArray[i];
    }
    delete file;
    return 0;
}
