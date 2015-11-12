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

//#define RENDERER
  #define FOTO

using namespace d_type;
#ifdef RENDERER
#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "TriangleMesh.h"
#include <SFML/Graphics.hpp>
#endif // RENDERER

#ifdef FOTO
#include "Sphere.h"
#include "Plane.h"
#include "OrtagonalCamera.h"
#include "PerspectiveCamera.h"

#include "RayTracer.h"
#include "RandomSampleGenerator.h"
#include "Sampler.h"
#include "SquareSampleDistributor.h"
#include "RegularSampleGenerator.h"
#include "DiskSampleDistributor.h"
#include "JitteredSampleGenerator.h"
#include "RayTriangle.h"
#include "FileLoader.h"
#include "MultiJitteringSampleGenerator.h"
#include "PointLight.h"
#include "MatteMaterial.h"
#include "PhongMaterial.h"
#include "CheckCPU.h"
#include "DirectionalLight.h"
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
CheckCPU cpu;
std::cout<<"There are "<<cpu.getNumberOfCores()<<" cores in CPU.\n";


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

    Vector2Bs img_size=Vector2Bs(800,800);


    RenderTarget *file = new RenderTarget(img_size);
    file->setCleanColour(Colour::Black);

    ICamera * orto=new OrtagonalCamera(Vector3Bf(0,0,0),0,Vector2Bf(10,10));
    // X Z Y
    ICamera *persp = new PerspectiveCamera(Vector3Bf(30,10,10),
                                           Vector3Bf(0,0,0),
                                           Vector3Bf::Up,
                                           2,
                                           Vector2Bf(1,1));


    Sampler * s= new Sampler(new SquareSampleDistributor(),new RandomSampleGenerator(),4,1);
    RayTracer *rt = new RayTracer(persp,file,s);
    #define MATERIALS1
#ifdef MATERIALS1
    MatteMaterial* mat=new MatteMaterial();
    mat->setKa(0.25f);
    mat->setKd(0.6f);
    mat->setCd(Colour::Red);


    MatteMaterial* mat2=new MatteMaterial();
    mat2->setKa(0.5);
    mat2->setKd(0.15f);
    mat2->setCd(Colour::Green);

    IRaycastable * plane= new Plane(Vector3Bf(0,-2,0),Vector3Bf(0,1,0));


    PhongMaterial* mat3=new PhongMaterial();
    mat3->setKa(0.25f);
    mat3->setKd(0.6f);
    mat3->setKs(0.5f);
    mat3->setCd(Colour::Red);
    mat3->setExponent(0.6f);


    plane->setMaterial(mat2);
    rt->addObject(plane);



    IRaycastable *sphere3=new Sphere(Vector3Bf(12,0,3)  , 2);
    sphere3->setMaterial(mat3);

   rt->addObject(sphere3);

    Mesh * m =FileLoader::loadMesh(("models/cube.obj"));

    rt->addObject(m);

    Ambient*ambient= new Ambient(0.5f,Colour::White);
    rt->setAmbientLight(ambient);

    PointLight * light= new PointLight();
    light->m_location=Vector3Bf(10,10,10);
    light->m_ls=5.00f;
    light->m_colour=Colour::White;
    rt->addLight(light);
#endif // MATERIALS1





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





    Vector2Bs img_size=Vector2Bs(500,500);






    RenderTarget *file = new RenderTarget(img_size);







    std::array<render::TriangleFloat*,2> triangleArray;
    render::TriangleFloat *triangle= new render::TriangleFloat(Vector3Bf(-0.5f,0.1f,5),Vector3Bf(0.1f,-0.5f,1.0f),Vector3Bf(-0.5f,-0.5f,2.0));
//    render::TriangleFloat *triangle2= new render::TriangleFloat(Vector3Bf(1,-0.1f,3),Vector3Bf(-0.4f,-1.0f,10),Vector3Bf(-0.5f,0.1f,2));


    render::TriangleFloat *triangle2= new render::TriangleFloat(Vector3Bf(0,0,0),Vector3Bf(0.5f,0.5f,0),Vector3Bf(0.5f,0,0));

    triangleArray[0]=triangle;
    triangleArray[1]=triangle2;


///NAJPIERW z -1 -1
///potem obliczanie kamery
///i potem kanoniczne

    render::TriangleMesh *mesh= new render::TriangleMesh();
    mesh->loadOBJ("models/cube.obj");

    VertexProcessor *vp= new VertexProcessor();
//
//
    vp->setIdentity();
    vp->setLookat(Vector3Bf(0,0,50),Vector3Bf(0,0,0),Vector3Bf(0,1,0));
    vp->setPerspective(45,1,Vector2Bf(0.1f,10000));
    vp->transform();
    vp->addTriangle(triangle2);
    vp->addTriangle(triangle);
    vp->addTriangle(mesh);

//    triangle2->first= vp->addTriangle(triangle2->first);
//    triangle2->second=vp->addTriangle(triangle2->second);
//    triangle2->third=vp->addTriangle(triangle2->third);
//
//    triangle->first= vp->addTriangle(triangle->first);
//    triangle->second=vp->addTriangle(triangle->second);
//    triangle->third=vp->addTriangle(triangle->third);


    for(Bsize i=0; i<triangleArray.size(); i++)
    {
        triangleArray[i]->init(img_size);
    }
    for(render::TriangleFloat * tri : mesh->getTriangles())
    {
        tri->init(img_size);
    }
    for(render::TriangleFloat * tri : mesh->getTriangles())
    {
       file->draw(*tri);
    }
    file->draw(*triangle2);
    file->draw(*triangle);

//
//    std::cout<<triangle2->first<<" "<<triangle2->second<< " "<<triangle2->third<< "\n";

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




//    Matrix4Bfloat m1=Matrix4Bfloat(8.f,4.f,2.f,5.f,6.f,9.f,8.f,5.f,21.f,4.f,7.f,5.f,1.f,1.f,5.f,6.f);
//    Matrix4Bfloat m2=Matrix4Bfloat(7.25,1.25,2.58,2.78,7.69,6.58,5.78,7.1,	22.2,22.999,2.85,5.89,	3.64,95.695,	964.69,6);
//
//    std::cout<<"!@#!@#!@#!@\n";
//    std::cout<<m1*m2;








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

