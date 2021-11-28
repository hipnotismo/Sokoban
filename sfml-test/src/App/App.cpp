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
    menu = new Menu(800, 450);
}

App::~App()
{

}

void App::LoopApp()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "Sokoban");
    sf::Event event;
    TM->levelOne(player);
    
  //  sf::Event event2;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::W:
                    menu->MoveUp();
                    break;

                case sf::Keyboard::S:
                    menu->MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu->GetPressedItem())
                    {
                    case 0:
                     //   std::cout << "Play button has been pressed" << std::endl;
                        currentScreen = Screens::Gameplay;
                        break;
                    case 1:
                        std::cout << "Option button has been pressed" << std::endl;
                        break;
                    case 2:
                        window.close();
                        break;
                    }

                    break;
                }

                break;
            case sf::Event::Closed:
                window.close();

                break;

            }

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
        //TM->draw(win);
        //player->draw(win);
        menu->draw(win);
        break;
    case Screens::Credits:
        break;
    case Screens::Gameplay:
        TM->draw(win);
        player->draw(win);
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
       // player->move();
        //menu->Input();
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
