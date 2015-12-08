#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "TriangleMesh.h"
#include <sstream>
#include "FPS.hpp"


int main(int argc, char **argv)
{
    Vector2Bi size(800,800);

    FPS fps = FPS();
    VertexProcessor vp;
    RenderTarget rt(size);
    rt.setCleanColour(Colour::White);

////
//    PointLight * light= new PointLight(Vector3Bf(10.0f, 0.0f, .0f));
//    vp.addLight(light);
//
//    PointLight * light2= new PointLight(Vector3Bf(-10.0f, 0.0f, 0.0f));
//    vp.addLight(light2);


    PointLight * light4= new PointLight(Vector3Bf(10.0f, -10.0f, 10.0f));
    vp.addLight(light4);

        DirectionalLight * light3= new DirectionalLight(Vector3Bf(0.0f, 0.0f, 0.0f));
    vp.addLight(light3);



    render::TriangleMesh *cube=new render::TriangleMesh();
    cube->loadOBJ("models/cube.obj");

    render::TriangleMesh *dragon =new render::TriangleMesh();
    dragon->loadOBJ("models/DRAGON.obj");

    render::TriangleMesh *sphere =new render::TriangleMesh();
    sphere->loadOBJ("models/sphere.obj");

    render::TriangleMesh *ex1 =new render::TriangleMesh();
    ex1->loadOBJ("models/EX1.obj");

    render::TriangleMesh *teapod =new render::TriangleMesh();
    teapod->loadOBJ("models/teapod.obj");
// FPS
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout<<"Can't load font\n";
    }
    sf::Text text;
    text.setFont(font); // font is a sf::Font
    text.setCharacterSize(24); // in pixels, not points!
    text.setString("Hello world");
    text.setColor(sf::Color::Red);
    std::ostringstream ss;
////////////////


    // angle of rotation for the camera direction
    d_type::Bfloat angle=0.0f;
    // actual vector representing the camera's direction
    d_type::Bfloat lx=0.0f,lz=-1.0f;
    // XZ position of the camera
    d_type::Bfloat x=0.0f,z=15.0f;

    d_type::Bfloat angleRotation=0.0f;


    sf::RenderWindow window(sf::VideoMode(size.x, size.y), "My window");
    sf::Clock FPSClock;
    sf::Clock gameClock;

//////////////////////

    const d_type::Bfloat fovy=60.0f,aspect=1.0f;
    const Vector2Bf nearfar(0.1f,100.0f);
    const Vector3Bf scale02(0.2f,0.2f,0.2f);




















    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered sincdragone the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the wind1ow
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
                else if(event.key.code == sf::Keyboard::A)
                {
                    angle -= 0.01f;
                    lx = sin(angle);
                    lz = -cos(angle);
                }
                else if(event.key.code == sf::Keyboard::D)
                {
                    angle += 0.01f;
                    lx = sin(angle);
                    lz = -cos(angle);
                }
                else if(event.key.code == sf::Keyboard::W)
                {
                    x += lx * 0.1f;
                    z += lz * 0.1f;
                }
                else if(event.key.code == sf::Keyboard::S)
                {
                    x -= lx * 0.1f;
                    z -= lz * 0.1f;
                }
            }
        }


        vp.setPerspective(fovy,aspect,nearfar);
        vp.setLookat(Vector3Bf(x,1.0f,z),Vector3Bf(x+lx,1.0f,z+lz),Vector3Bf::Up);
        vp.setIdentity();

//
        vp.setIdentity();
        vp.multByScale(Vector3Bf(0.3f,0.3f,0.3f));

        vp.multByTranslation(Vector3Bf(0.0,5.f,0.0f));
        vp.multByRotation(-angleRotation,Vector3Bf(0.0f,1.0f,0.0f));


        vp.transform();

        teapod->draw(vp, rt);
//
///////////////////////
//        vp.setIdentity();
////    vp.multByScale(Vector3Bf(0.2f,0.2f,0.2f));
////        vp.multByTranslation(Vector3Bf(0.0,5.f,-3.0f));
//        vp.multByRotation(180,Vector3Bf(1.0f,0.0f,0.0f));
//
//        vp.multByRotation(angleRotation,Vector3Bf(0.0f,-1.0f,0.0f));
//
//        vp.transform();
//
//        dragon->draw(vp, rt);
///////////////////////

        vp.setIdentity();
//        vp.multByRotation(angle,Vector3Bf(0,1,0));

        vp.multByTranslation(Vector3Bf(10.-5,5.f,1.0f));

//        vp.multByScale(Vector3Bf(0.2f,0.2f,0.2f));
        vp.transform();
        sphere->draw(vp, rt);
//////////////////////////
        vp.setIdentity();
        vp.multByTranslation(Vector3Bf(10.-5,5.f,1.0f));

        vp.multByRotation(76,Vector3Bf(0,1,0));
        vp.multByRotation(10,Vector3Bf(0,0,1));
        vp.multByRotation(angleRotation,Vector3Bf(0,1,0));


        vp.multByScale(Vector3Bf(0.3f,0.3f,0.3f));
        vp.transform();
        ex1->draw(vp, rt);
///////////////////////////////
//        vp.setIdentity();
//        vp.multByRotation(76,Vector3Bf(0,1,0));
//        vp.multByRotation(10,Vector3Bf(0,0,1));
//        vp.multByTranslation(Vector3Bf(15.5,5.f,1.0f));
//
//        vp.multByScale(Vector3Bf(0.3f,0.3f,0.3f));
//        vp.transform();
//        ex1->draw(vp, rt);
//////////////////////////




//
        rt.swapBuffers();
        window.clear(sf::Color::Black);

        window.draw(rt);

        window.draw(text);

        window.display();

        angleRotation+=1.f;
        rt.clear();
        fps.update();


        ss.str(std::string());
        ss<<fps.getFPS();
        text.setString(ss.str()) ;



    }



    rt.drawToFile("dupa.tga");






    d_type::Bint a32;
    std::cin>>a32;

    delete cube,dragon,sphere,ex1,teapod;
    return 1;
}
