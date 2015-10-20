#include "Triangle.h"
#include "Matrix4.h"
#include "RenderTarget.h"
#include "GLFWWindow.h"
#include "VertexProcessor.h"
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


    std::cout<<"R1\n";

    Sphere s= Sphere(Vector3Bf(),1  );
    Ray r1=Ray(Vector3Bf(0,0,-20),Vector3Bf(0,0,0),DESTINATION);
    Vector3BfVector r1V=s.intersect(r1);
    for(Vector3Bf n :r1V)
    {
        std::cout<<n<<"\n";
    }
////////////////////////////////////////////////////////
    std::cout<<"R2\n";

    Ray r2=Ray(Vector3Bf(0,0,-20),Vector3Bf(0,10,-20),DIRECTION);
    Vector3BfVector r2V=s.intersect(r2);
    for(Vector3Bf n :r2V)
    {
        std::cout<<n<<"\n";
    }
//////////////////////////////////////////////////////////
    std::cout<<"R3\n";
    Ray r3=Ray(Vector3Bf(-10,0,-20),Vector3Bf(-10,0,20),DESTINATION);
    Vector3BfVector r3V=s.intersect(r3);
    for(Vector3Bf n :r3V)
    {
        std::cout<<n<<"\n";
    }
////////////////////////////////////////////////////////
    std::cout<<"Plane1\n";
    Plane p(Vector3Bf(0,0,0),Vector3Bf(23,cosf(M_PI/4),cosf(M_PI/4)));
    Vector3BfVector r4V=p.intersect(r2);
    for(Vector3Bf n :r4V)
    {
        std::cout<<n<<"\n";
    }



#ifdef CLOCK
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
#endif // CLOCK


    Vector2Bs img_size=Vector2Bs(800,600);


    std::array<TriangleFloat*,2> triangleArray;
    TriangleFloat *triangle= new TriangleFloat(Vector3Bf(-0.5f,0.1f,5),Vector3Bf(0.1f,-0.5f,1.0f),Vector3Bf(-0.5f,-0.5f,2.0));
    TriangleFloat *triangle2= new TriangleFloat(Vector3Bf(0,-0.1f,3),Vector3Bf(-0.4f,-1.0f,10),Vector3Bf(-0.5f,0.1f,2));
    triangleArray[0]=triangle;
    triangleArray[1]=triangle2;


    for(Bsize i=0; i<triangleArray.size(); i++)
    {
        triangleArray[i]->init(img_size);
    }


    RenderTarget *file = new RenderTarget(img_size);






    d_type::Bfloat widthPixel,heightPixel;
    d_type::Bfloat centerX,centerY;

    widthPixel=2.0f/file->getSize().x;
    heightPixel=2.0f/file->getSize().y;
    std::cout<<widthPixel<<" "<<heightPixel<<"\n";
    for(Bint x=0; x<file->getSize().x; x++)
    {
        for(Bint y=0; y<file->getSize().y; y++)
        {
            centerX=-1.0f + (x+0.5f)*widthPixel;
            centerY=1.0f - (y+0.5f)*heightPixel;
            Ray r(Vector3Bf(0,0,-20),Vector3Bf(centerX,centerY,0),DESTINATION);
            Vector3BfVector v=s.intersect(r);
            if(!v.empty())
            {
                file->setPixel(Colour::Red,x,y);

            }
            else
            {
                // std::cout<<"EMPTY";
                file->setPixel(Colour::Black,x,y);
            }

        }

    }

    VertexProcessor *vp= new VertexProcessor();


    vp->setLookat(Vector3Bf(0,-1,0),Vector3Bf(0,0,0),Vector3Bf(0,1,0));
    vp->setPerspective(10
                       ,800/600,Vector2Bf(1,1000));
    //vp->multByRotation(90,Vector3Bf(1,0,0));
    vp->setIdentity();
    vp->transform();

    TriangleFloat* t,t2;


t=new TriangleFloat();
        t->first=vp->addTriangle(triangle2->first);
        t->second=vp->addTriangle(triangle2->second);
        t->third=vp->addTriangle(triangle2->third);


    //file->draw(t);
    file->draw(*t);

#ifdef CLOCK

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
#endif // CLOCK
    file->drawToFile("file.tga");


    //file->getDepthBuffer();

    for(Bsize i=0; i<triangleArray.size(); i++)
    {
        delete triangleArray[i];
    }
    delete file;

    d_type::Bint a;
    std::cin>>a;
    return 0;
}
