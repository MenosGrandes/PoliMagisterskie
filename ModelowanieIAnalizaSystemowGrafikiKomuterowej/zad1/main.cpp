#include "Triangle.h"
#include "Matrix4.h"
#include "RenderTarget.h"
#include <cstdio>
#include <iostream>
#include <array>
#include <limits>
#include <chrono>
#include <ctime>
#include <vector>
//#define RENDERER
#define FOTO


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


    Ray r2=Ray(r1.getOrigin(),Vector3Bf(0,0,20));
    Ray r3=Ray(r1.getOrigin(),Vector3Bf(0,0,20));
d_type::Bfloat i=100.f;
std::cout<<s.intersect(r1,i)<<"\n";

 i=1000.f;
std::cout<<s.intersect(r2,i)<<"\n";

 i=1000.f;
std::cout<<s.intersect(r3,i)<<"\n";



#else

Matrix4Bfloat m= Matrix4Bfloat(3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3);
Matrix4Bfloat m2= Matrix4Bfloat(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);
Matrix4Bfloat m3= Matrix4Bfloat(2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2);
Vector4Bf v=Vector4Bf(1,2,3,4);

//m3=-m3;
//std::cout<<+m3;


 std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();




    std::array<TriangleFloat*,2> triangleArray;
    TriangleFloat *triangle= new TriangleFloat(Vector3Bf(-0.5f,-0.5f,2.0),Vector3Bf(-0.5f,0.1f,5),Vector3Bf(0.1f,-0.5f,1.0f));
    TriangleFloat *triangle2= new TriangleFloat(Vector3Bf(0,-0.1f,3),Vector3Bf(-0.4f,-0.8f,10),Vector3Bf(-0.5f,0.1f,0));
    triangleArray[0]=triangle;
    triangleArray[1]=triangle2;




    //declare image
    Vector2Bs img_size=Vector2Bs(300,300);

        for(Bsize i=0; i<triangleArray.size(); i++)
    {
        triangleArray[i]->init(img_size);
    }


    RenderTarget *file = new RenderTarget(img_size);



    //file->draw(t);
    file->draw(*triangle);
    file->draw(*triangle2);



    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

    file->drawToFile("file.tga");


    //file->getDepthBuffer();

    for(Bsize i=0; i<triangleArray.size(); i++)
    {
        delete triangleArray[i];
    }
    delete file;
#endif // FOTO
d_type::Bint a;
std::cin>>a;
    return 0;
}
