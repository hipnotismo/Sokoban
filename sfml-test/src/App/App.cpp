#include "App.h"

App::App()
{
	
}

App::~App()
{

}

void App::LoopApp()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Sokoban");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();

    }
}
