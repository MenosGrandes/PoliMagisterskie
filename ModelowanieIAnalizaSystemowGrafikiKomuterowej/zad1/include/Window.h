#ifndef WINDOW_H
#define WINDOW_H
#include "RenderTarget.h"
#include <SFML/Graphics.hpp>
class Window
{
    public:
        Window(RenderTarget * rt);
        virtual ~Window();

       sf::RenderWindow m_window;
};

#endif // WINDOW_H
