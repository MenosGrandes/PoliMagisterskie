#include "RenderTarget.h"
#include "VertexProcessor.h"
#include "TriangleMesh.h"
#include <sstream>
float getFPS(const sf::Time& time)
{
    return (1000000.0f / time.asMicroseconds());
}
int main(int argc, char **argv)
{
    Vector2Bi size(800,800);


    VertexProcessor vp;
    RenderTarget rt(size);
    rt.setCleanColour(Colour::White);

////
//    PointLight * light= new PointLight(Vector3Bf(10.0f, 0.0f, .0f));
//    vp.addLight(light);
//
    PointLight * light2= new PointLight(Vector3Bf(-10.0f, 0.0f, 0.0f));
    vp.addLight(light2);

//        DirectionalLight * light3= new DirectionalLight(Vector3Bf(0.0f, 0.0f, 0.0f));
//    vp.addLight(light3);

    vp.setPerspective(60.0f,1.0f,Vector2Bf(0.1f,30.0f));
    vp.setLookat(Vector3Bf(0,0,20.0f),Vector3Bf(0,0,0),Vector3Bf::Up);
    vp.setIdentity();

    render::TriangleMesh *cube=new render::TriangleMesh();
    cube->loadOBJ("models/cube.obj");

    render::TriangleMesh *dragon =new render::TriangleMesh();
    dragon->loadOBJ("models/DRAGON.obj");

    render::TriangleMesh *sphere =new render::TriangleMesh();
    sphere->loadOBJ("models/sphere.obj");

    render::TriangleMesh *ex1 =new render::TriangleMesh();
    ex1->loadOBJ("models/EX1.obj");


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



    d_type::Bfloat angle=10.0f;


    sf::RenderWindow window(sf::VideoMode(size.x, size.y), "My window");
    sf::Clock FPSClock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
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
            }
        }





        vp.setIdentity();
        vp.multByScale(Vector3Bf(0.2f,0.2f,0.2f));
        vp.multByTranslation(Vector3Bf(0.0,5.f,-3.0f));

        vp.multByRotation(angle,Vector3Bf(1.0f,-1.0f,0.0f));

        vp.transform();

        cube->draw(vp, rt);

///////////////////
        vp.setIdentity();
//    vp.multByScale(Vector3Bf(0.2f,0.2f,0.2f));
        vp.multByTranslation(Vector3Bf(0.0,5.f,-3.0f));

        vp.multByRotation(angle,Vector3Bf(1.0f,-1.0f,0.0f));

        vp.transform();

        dragon->draw(vp, rt);
/////////////////////

        vp.setIdentity();
        vp.multByTranslation(Vector3Bf(10.-5,5.f,1.0f));

        vp.multByScale(Vector3Bf(0.2f,0.2f,0.2f));
        vp.transform();
        sphere->draw(vp, rt);
////////////////////////
        vp.setIdentity();
        vp.multByRotation(76,Vector3Bf(0,1,0));
        vp.multByRotation(10,Vector3Bf(0,0,1));
        vp.multByTranslation(Vector3Bf(10.-5,5.f,1.0f));

        vp.multByScale(Vector3Bf(0.3f,0.3f,0.3f));
        vp.transform();
        ex1->draw(vp, rt);




        rt.swapBuffers();
        window.clear(sf::Color::Black);

        window.draw(rt.m_sprite);

        window.draw(text);

        window.display();

        angle+=1.f;
        rt.clear();
        ss.str(std::string());
        ss<<getFPS(FPSClock.restart());
        text.setString(ss.str()) ;
    }



    rt.drawToFile("dupa.tga");






    d_type::Bint a32;
    std::cin>>a32;

    delete cube,dragon,sphere;
    return 0;
}
