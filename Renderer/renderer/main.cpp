
#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "Triangle.h"
#include "TriangleMesh.h"

int main(int argc, char **argv)
{







    Vector2Bf img_size=Vector2Bf(500,500);






    RenderTarget *file = new RenderTarget(img_size);



///NAJPIERW z -1 -1
///potem obliczanie kamery
///i potem kanoniczne

    render::TriangleMesh *mesh= new render::TriangleMesh();
    mesh->loadOBJ("models/teapod.obj");

    VertexProcessor *vp= new VertexProcessor();


//    sf::RenderWindow window(sf::VideoMode(img_size.x, img_size.y), "SFML works!");

d_type::Bfloat angle=45;
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
////            if (event.type == sf::Event::Closed)
////                window.close();
////
////                if(event.type == sf::Event::Keyboard)
//                switch (event.type)
//                {
//                     case sf::Event::Closed:
//                        window.close();
//                        break;
//
//                        case sf::Event::KeyPressed:
//                        switch(event.key.code)
//                        {
//                        case  sf::Keyboard::A:
//                            {
//                                angle++;
//                                file->drawToFile("file.tga");
//                                std::cout<<angle<<"\n";
//
//                            }
//                        }
//                        break;
//
//
//                }
//
//        }
////////////////////////////////////////////////////////////////////////////////
    vp->setIdentity();
    vp->setLookat(Vector3Bf(0,0,30),Vector3Bf(0,0,0),Vector3Bf(0,1,0));
    vp->setPerspective(angle,1,Vector2Bf(1,110));
//    vp->multByRotation(angle,Vector3Bf(1,0,0));
    std::cout<<angle<<"\n";
//    vp->multByTranslation(Vector3Bf(0,-30,-5));

    vp->transform();
    vp->addTriangle(mesh);
    for(render::Triangle * tri : mesh->getTriangles())
    {
        tri->init(img_size);
        file->draw(*tri);
    }
//////////////////////////////////////////////////////////////////////////////////
//
//
//
//
////        file->clear(0);
//        window.clear();
//        //file->clear(0);
//        file->swapBuffers();
//        window.draw(*file);
//        window.display();
//    }












//
//    file->drawToFile("file.tga");


std::cout<<"asasd";
    d_type::Bint a32;
    std::cin>>a32;
    return 0;
}
