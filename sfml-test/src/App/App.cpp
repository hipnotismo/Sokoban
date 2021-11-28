#include "App.h"
#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "Tilemap/Tilemap.h"
using namespace sf;

App::App()
{
    currentScreen = Screens::Menu;
    player = new Player();
    TM = new Tilemap();
}

App::~App()
{

}

void App::LoopApp()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "Sokoban");
    sf::Event event;
    TM->levelOne(player);
    
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Input();
        Draw(window);

    }
}

void App::Draw(sf::RenderWindow &win)
{
    win.clear();
    switch (currentScreen) {
    case Screens::Menu:
        TM->draw(win);
        player->draw(win);
        
        break;
    case Screens::Credits:
        break;
    case Screens::Gameplay:
        break;
    case Screens::GameOver:
        break;
    default:
        break;
    }
    win.display();
}

void App::Input()
{
    //player->move();
    switch (currentScreen) {
    case Screens::Menu:
        player->move();
        break;
    case Screens::Credits:
        break;
    case Screens::Gameplay:
        break;
    case Screens::GameOver:
        break;
    default:
        break;
    }
}
