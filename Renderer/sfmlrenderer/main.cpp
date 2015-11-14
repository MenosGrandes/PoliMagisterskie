
#include "Bitmap.h"
#include "RenderContext.h"
#include "src/algorithms.hpp"
float getFPS(const sf::Time& time)
{
    return (1000000.0f / time.asMicroseconds());
}
int main()
{

    Vector2Bf size=Vector2Bf(800,600);
    RenderContext *bitmap=new RenderContext(size.x,size.y);

    sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Renderer!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Clock FPSClock;
        sf::Clock gameClock;

    Vertex2 max,min,mid;
    max.position=Vector4Bf(-1,-1,0,1);
    min.position=Vector4Bf(0,1,0,1);
    mid.position=Vector4Bf(1,-1,0,1);
    Matrix4f projection=Matrix4f();
    projection.InitPerspective((d_type::Bfloat)ToRadians::toRadians(45),size.x/size.y,0.1f,1000.0f);
    d_type::Bfloat rotationV=0;



    Matrix4f translation=Matrix4f();
    translation.InitTranslation(0,2,5);

    Matrix4f rotation=Matrix4f();
    rotation.InitRotation(0,0,0);

    Matrix4f transform=Matrix4f();
    transform=projection.Mul(translation.Mul(rotation));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }

            case sf::Event::KeyPressed :
            {
                break;

            }

            }
        }








    rotationV+=gameClock.restart().asMicroseconds()/1000000.f;
    translation.InitTranslation(0,0,3);

    rotation.InitRotation(0,rotationV,0);
    transform=projection.Mul(translation.Mul(rotation));


        window.clear();
        bitmap->clear(0);

        bitmap->fillTriangle(max.transform(transform),mid.transform(transform),min.transform(transform));
        bitmap->swapBuffers();
        window.draw(*bitmap);
        window.display();


        float fps = getFPS(FPSClock.restart());
        char c[10];
        sprintf(c, "%f", fps);
        std::string string(c);
        window.setTitle(c);
    }

    return 0;
}
