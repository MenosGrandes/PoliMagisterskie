#include "Triangle.h"
#include "Matrix4.h"
#include "RenderTarget.h"
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

using namespace d_type;
using namespace c;

#ifdef FOTO
#include "Sphere.h"
#include "Plane.h"
#include "OrtagonalCamera.h"
#include "PerspectiveCamera.h"
#include "RayTracer.h"
#include "RandomSampleGenerator.h"
#else

#endif // FOTO



#ifdef FOTO
#define ZAD2
#define CLOCK
int main(int argc, char **argv)
{



#ifdef CLOCK
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
#endif // CLOCK

#ifdef ZAD1
    std::cout<<"R1\n";

    Sphere *s= new Sphere(Vector3Bf(),10  );


    Ray r1=Ray(Vector3Bf(0,0,-20),Vector3Bf(0,0,0),DESTINATION);
    Vector3BfVector r1V=s->intersect(r1);
    for(Vector3Bf n :r1V)
    {
        std::cout<<n<<"\n";
    }
////////////////////////////////////////////////////////
    std::cout<<"R2\n";

    Ray r2=Ray(Vector3Bf(0,0,-20),Vector3Bf(0,10,-20),DIRECTION);
    Vector3BfVector r2V=s->intersect(r2);
    for(Vector3Bf n :r2V)
    {
        std::cout<<n<<"\n";
    }
//////////////////////////////////////////////////////////
    std::cout<<"R3\n";
    Ray r3=Ray(Vector3Bf(-10,0,-20),Vector3Bf(-10,0,20),DESTINATION);
    Vector3BfVector r3V=s->intersect(r3);
    for(Vector3Bf n :r3V)
    {
        std::cout<<n<<"\n";
    }
////////////////////////////////////////////////////////
    std::cout<<"Plane1\n";
    Plane *p=new Plane(Vector3Bf(0,0,0),Vector3Bf(0,cosf(ToRadians::toRadians(45)),cosf(ToRadians::toRadians(45))));
    Vector3BfVector r4V=p->intersect(r2);
    for(Vector3Bf n :r4V)
    {
        std::cout<<n<<"\n";
    }
#endif // ZAD1
#ifdef ZAD2
    Vector2Bs img_size=Vector2Bs(800,400);
    RenderTarget *file = new RenderTarget(img_size);

    ICamera * orto=new OrtagonalCamera(Vector3Bf(0,0,-5),0,Vector2Bf(5,5));

    ICamera *persp = new PerspectiveCamera(Vector3Bf(0,1,-8),
                                           Vector3Bf(0,0,0),
                                           Vector3Bf(0,-1,0),
                                           1,
                                           Vector2Bf(2,1));

    RayTracer *rt = new RayTracer(persp,file);
    rt->addObject(new Plane(Vector3Bf(0,2,0),Vector3Bf(0,1,0)));
    rt->addObject(new Sphere(Vector3Bf(-4.f,0,0) , 2));
    rt->addObject(new Sphere(Vector3Bf(4,0,0)  , 2));
    rt->addObject(new Sphere(Vector3Bf(0,0,3)  , 2));

    // rt->addObject(p);
    rt->rayTrace();




    RandomSampleGenerator *r = new RandomSampleGenerator();

//    for(d_type::Bsize i=0;i<3;i++)
//    {
//        std::cout<<a2[i]<<"  ";
//    }
//        std::cout<<"\n!!!!!!!!!!!!!!!!!!!!!!!!\n";
//
//            Vector2Bf* a3= r->generateSamples(3);
//    for(d_type::Bsize i=0;i<3;i++)
//    {
//        std::cout<<a3[i]<<"  ";
//    }
//        std::cout<<"\n!!!!!!!!!!!!!!!!!!!!!!!!\n";

#endif // ZAD2








#ifdef CLOCK

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
#endif // CLOCK


#ifdef ZAD2
    file->drawToFile("file.tga");
    delete file;
#endif // ZAD2
    d_type::Bint a;
    std::cin>>a;
    return 0;
}
#endif
#ifdef RENDERER
int main(int argc, char **argv)
{


#ifdef OPENGL
    GLFWWindow *w=new GLFWWindow(300,300);

    w->loop();
    w->terminate();
#endif // OPENGL

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



    VertexProcessor *vp= new VertexProcessor();


    vp->setLookat(Vector3Bf(0,-1,0),Vector3Bf(0,0,0),Vector3Bf(0,1,0));
    vp->setPerspective(10,800/600,Vector2Bf(1,1000));
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
#endif // RENDERER

