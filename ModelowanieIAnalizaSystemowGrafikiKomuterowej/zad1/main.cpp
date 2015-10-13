#include "Image.h"
#include "Triangle.h"
#include "Matrix4.h"

#include <cstdio>
#include <iostream>
#include <array>
#include <limits>


#define RENDERER
//#define FOTO


using namespace d_type;
using namespace c;

#ifdef FOTO
#include <Sphere.h>

#else

#endif // FOTO




int main(int argc, char **argv)
{
#ifdef FOTO
    Sphere s= Sphere(Vector3Bf(),10);
    Ray r1=Ray(Vector3Bf(0,0,-20),s.getCenter());
    Ray r2=Ray(r1.getOrigin(),r1.getOrigin());
    Ray r3=Ray(r1.getOrigin(),Vector3Bf(0,0,20));





Bfloat i=11;
        std::cout<<s.intersect(r1,i)<<" -> ";
         Vector3Bf pos=r1.getOrigin()+i;
         std::cout<<"PUNKT PRZECIECIA :"<<pos.x<<" "<<pos.y<<" "<<pos.z<<"\n";
i=11;
        std::cout<<s.intersect(r2,i)<<" -> ";
         pos=r2.getOrigin()+i;
         std::cout<<"PUNKT PRZECIECIA :"<<pos.x<<" "<<pos.y<<" "<<pos.z;
        //std::cout<<s.intersect(r3,i);

        std::cout<<"\n";



#else



    TriangleFloat t= TriangleFloat();



    std::array<TriangleFloat*,2> triangleArray;
    TriangleFloat *triangle= new TriangleFloat(Vector2Bf(50,50),Vector2Bf(50,100),Vector2Bf(100,50));
    TriangleFloat *triangle2= new TriangleFloat(Vector2Bf(100,50),Vector2Bf(50,100),Vector2Bf(150,100));
    triangleArray[0]=triangle;
    triangleArray[1]=triangle2;
    //declare image
    Vector2Bs img_size=Vector2Bs(300,300);
    RenderTarget *file = new RenderTarget(img_size);



    //file->draw(t);
    file->draw(*triangle);
    file->draw(*triangle2);
    file->drawToFile("file.tga");
    for(Bsize i=0; i<triangleArray.size(); i++)
    {
        delete triangleArray[i];
    }
    delete file;
#endif // FOTO
    return 0;
}
