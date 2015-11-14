
#include "Bitmap.h"
#include "RenderContext.h"
#include "Vector2.h"
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

    sf::Int64 previousTime=gameClock.restart().asMicroseconds();
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

        window.clear();
        bitmap->clear(0);
        for(int j=100;j<200;j++)
        {
            bitmap->drawScanBuffer(j,300-j,300+j);
        }
        bitmap->fillShape(100,200);
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
