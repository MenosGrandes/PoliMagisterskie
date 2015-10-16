#include "Triangle.h"
#include "Matrix4.h"
#include "RenderTarget.h"
#include "GLFWWindow.h"
#include <cstdio>
#include <iostream>
#include <array>
#include <limits>
#include <chrono>
#include <ctime>
#include <vector>





//#define RENDERER
#define FOTO
#define ZAD1FOTO

using namespace d_type;
using namespace c;

#ifdef FOTO
#include "Sphere.h"
#include "Plane.h"
#else

#endif // FOTO




int main(int argc, char **argv)
{


#ifdef OPENGL
    GLFWWindow *w=new GLFWWindow(300,300);

    w->loop();
    w->terminate();
#endif // OPENGL


#ifdef FOTO
#ifdef ZAD1FOTO
    std::cout<<"R1\n";

    Sphere s= Sphere(Vector3Bf(),10);
    Ray r1=Ray(Vector3Bf(0,0,-20),Vector3Bf(0,0,0));
    Vector3BfVector r1V=s.intersect(r1);
    for(Vector3Bf n :r1V)
    {
        std::cout<<n<<"\n";
    }
////////////////////////////////////////////////////////
    std::cout<<"R2\n";

    Ray r2=Ray(Vector3Bf(0,0,-20),Vector3Bf(0,20,0));
    Vector3BfVector r2V=s.intersect(r2);
    for(Vector3Bf n :r2V)
    {
        std::cout<<n<<"\n";
    }
//////////////////////////////////////////////////////////
    std::cout<<"R3\n";
    Ray r3=Ray(Vector3Bf(-10,0,-20),Vector3Bf(-10,0,20));
    Vector3BfVector r3V=s.intersect(r3);
    for(Vector3Bf n :r3V)
    {
        std::cout<<n<<"\n";
    }
////////////////////////////////////////////////////////
    std::cout<<"Plane1\n";
    Plane p(Vector3Bf(100,100,100),Vector3Bf(0,cos(45)*10,cos(45)*10));
    Vector3BfVector r4V=p.intersect(r2);
    for(Vector3Bf n :r4V)
    {
        std::cout<<n<<"\n";
    }





#endif // ZAD1FOTO
#ifdef ZAD2FOTO

#endif // ZAD2FOTO
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
