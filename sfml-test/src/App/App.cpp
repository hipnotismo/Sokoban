#include "App.h"

App::App()
{
    currentScreen = Screens::Menu;
    player = new Player();
}

App::~App()
{

}

void App::LoopApp()
{
    sf::RenderWindow window(sf::VideoMode(800, 450), "Sokoban");
    sf::Event event;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    q.push(shape);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Draw(window);

    }
}

void App::Draw(sf::RenderWindow &win)
{
    win.clear();
    switch (currentScreen) {
    case Screens::Menu:
        //sf::CircleShape temp = q.
        win.draw(q.front());
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
