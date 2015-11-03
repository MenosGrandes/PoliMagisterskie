#include "Matrix4.h"
#include "Vertex2.h"
#include <cstdio>
#include <iostream>
#include <array>
#include <limits>
#include <chrono>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>

#define RENDERER
//#define FOTO

using namespace d_type;
#ifdef RENDERER
#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "Triangle.h"
#include <SFML/Graphics.hpp>
#endif // RENDERER

#ifdef FOTO
#include "Sphere.h"
#include "Plane.h"
#include "OrtagonalCamera.h"
#include "PerspectiveCamera.h"

#include "RayTracer.h"
#include "RandomSampleGenerator.h"
#include "PerfectDifuse.h"
#include "Sampler.h"
#include "SquareSampleDistributor.h"
#include "RegularSampleGenerator.h"
#include "DiskSampleDistributor.h"
#include "JitteredSampleGenerator.h"
#include "RayTriangle.h"
#include "FileLoader.h"
#include "MultiJitteringSampleGenerator.h"
#else

#endif // FOTO


#ifdef FOTO
#define DRAWRAY
#define ZAD3OBJECTS
#define ZAD2OBJECTS
#define ZAD4OBJECTS
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
#ifdef DRAWRAY
//Mesh * mesh=
//
//
//mesh->setMaterial(new PerfectDifuse(Colour::Red));


    Vector2Bs img_size=Vector2Bs(600,600);


    RenderTarget *file = new RenderTarget(img_size);
    file->setCleanColour(Colour::Black);

    ICamera * orto=new OrtagonalCamera(Vector3Bf(0,0,0),0,Vector2Bf(10,10));

    ICamera *persp = new PerspectiveCamera(Vector3Bf(0,0,-25),
                                           Vector3Bf(0,0,0),
                                           Vector3Bf::Up,
                                           1,
                                           Vector2Bf(1,1));


    Sampler * s= new Sampler(new DiskSampleDistributor(),new MultiJitteringSampleGenerator(),9,1);
    RayTracer *rt = new RayTracer(persp,file,s);



    PerfectDifuse * pd1=new PerfectDifuse(Colour::Red);
    PerfectDifuse * pd2=new PerfectDifuse(Colour::Green);
    PerfectDifuse * pd3=new PerfectDifuse(Colour::Blue);
    PerfectDifuse * pd4=new PerfectDifuse(Colour::Gray);


#ifdef ZAD2OBJECTS
//    rt->addObject(new Sphere(Vector3Bf(-4.f,0,0) , 2,pd1));
//    rt->addObject(new Sphere(Vector3Bf( 4,0,0)  , 2,pd2));
//    rt->addObject(new Sphere(Vector3Bf(0,0,3)  , 2,pd3));
//    rt->addObject(new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0),pd4));
#endif // ZAD2
#ifdef ZAD3OBJECTS

    Mesh * m =FileLoader::loadMesh(("models/teapod.obj"));

    rt->addObject(m);
//   rt->addObject(FileLoader::loadMesh(("models/teapod.obj")));

#endif // ZAD3

#ifdef ZAD4OBJECTS
    rt->addLight( PointLight(Vector3Bf(5,5,0),Colour::White));
#endif // ZAD4OBJECTS



#endif // ZAD2

#ifdef DRAWRAY
    rt->rayTrace();
#endif // DRAWRAY




#ifdef CLOCK

    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
#endif // CLOCK


#ifdef DRAWRAY
    file->drawToFile("file.tga");
    delete file;
#endif // ZAD2
    d_type::Bint a;
    std::cin>>a;
    return 0;
}
#endif
#ifdef RENDERER
float getFPS(const sf::Time& time)
{
    return (1000000.0f / time.asMicroseconds());
}
int main(int argc, char **argv)
{





    Vector2Bs img_size=Vector2Bs(800,600);






    RenderTarget *file = new RenderTarget(img_size);







    std::array<render::TriangleFloat*,2> triangleArray;
    render::TriangleFloat *triangle= new render::TriangleFloat(Vector3Bf(-0.5f,0.1f,5),Vector3Bf(0.1f,-0.5f,1.0f),Vector3Bf(-0.5f,-0.5f,2.0));
//    render::TriangleFloat *triangle2= new render::TriangleFloat(Vector3Bf(1,-0.1f,3),Vector3Bf(-0.4f,-1.0f,10),Vector3Bf(-0.5f,0.1f,2));


    render::TriangleFloat *triangle2= new render::TriangleFloat(Vector3Bf(0,0,0),Vector3Bf(0.5f,0.5f,0),Vector3Bf(0.5f,0,0));

    triangleArray[0]=triangle;
    triangleArray[1]=triangle2;


    for(Bsize i=0; i<triangleArray.size(); i++)
    {
        triangleArray[i]->init(img_size);
    }



    VertexProcessor *vp= new VertexProcessor();
//
//
    vp->setIdentity();
    vp->setPerspective(45,4/3,Vector2Bf(1,10000));
    vp->setLookat(Vector3Bf(0,0,-1),Vector3Bf(0,0,0),Vector3Bf(0,1,0));
    vp->transform();
    triangle2->first= vp->addTriangle(triangle2->first);
    triangle2->second=vp->addTriangle(triangle2->second);
    triangle2->third=vp->addTriangle(triangle2->third);
    file->draw(*triangle2);



//
//    render::TriangleFloat * t,t2;
//
//
//    t=new render::TriangleFloat();
//    t->first=vp->addTriangle(triangle2->first);
//    t->second=vp->addTriangle(triangle2->second);
//    t->third=vp->addTriangle(triangle2->third);


    //file->draw(t);
//    file->draw(*t);


    file->drawToFile("file.tga");
//
//
//    //file->getDepthBuffer();
//
//    for(Bsize i=0; i<triangleArray.size(); i++)
//    {
//        delete triangleArray[i];
//    }
//    delete file;













//
//
//
//
//
//    sf::RenderWindow window(sf::VideoMode(img_size.x, img_size.y), "RENDERER!");
//
//
//
//
//    sf::Texture texture;
//    if (!texture.create(img_size.x, img_size.y))
//    {
//        std::cout<<"ERROR WITH TEXTURE\n";
//    }








//    sf::Sprite sprite(texture);
//
//    sf::Uint8 * pixels = new sf::Uint8[img_size.x*img_size.y*4];
//    sf::Clock FPSClock;
//    std::stringstream ss;
//            file->rewritePixelForTexture(pixels);
//        texture.update(pixels);
////    sf::View view1;
////    view1.setSize(img_size.x,img_size.y);
////    view1.setViewport(sf::FloatRect(0, 0, 1, 1));
////    window.setView(view1);
////    view1.rotate(90);
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//
//        file->rewritePixelForTexture(pixels);
//        texture.update(pixels);
//
//        window.clear();
//        window.draw(sprite);
////texture.update(window);
//        window.display();
//
//        ss<<getFPS(FPSClock.restart());
//
//       window.setTitle(ss.str());
//       ss.str("");
//
//
//    }







    d_type::Bint a32;
    std::cin>>a32;
    return 0;
}
#endif // RENDERER

