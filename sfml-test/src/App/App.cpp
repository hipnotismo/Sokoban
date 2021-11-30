#include "app.h"

App::App()
{
    currentScreen = Screens::Menu;
    player = new Player();
    TM = new Tilemap();
    menu = new Menu(800, 450);
    credit = new credits(800, 450);
    check = true;

    if (!font.loadFromFile("res/arial.ttf"))
    {
        // handle error
    }

    UI[0].setFont(font);
    UI[0].setFillColor(sf::Color::Cyan);
    UI[0].setString("P para menu");
    UI[0].setPosition(sf::Vector2f(500, 10));

    UI[1].setFont(font);
    UI[1].setFillColor(sf::Color::Cyan);
    UI[1].setString("R para reinicio");
    UI[1].setPosition(sf::Vector2f(500, 100));


}

App::~App()
{

}

void App::LoopApp()
{

    sf::RenderWindow window(sf::VideoMode(800, 450), "Sokoban");
    sf::Event event;

    if (!music1.openFromFile("res/Wind.ogg"))
    {
        std::cout << "error" << std::endl;
    }

    if (!music2.openFromFile("res/Drip.ogg"))
    {
        std::cout << "error" << std::endl;
    }
    music1.play();
    music2.play();
    music2.setVolume(0);
    
 

    while (window.isOpen())
    {    

        clock.tick();
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
                case sf::Keyboard::P:
                    currentScreen = Screens::Menu;
                    music2.setVolume(0);
                    break;

                case sf::Keyboard::Return:
                    switch (menu->GetPressedItem())
                    {
                    case 0:
                        TM->levelController(player);
                        currentScreen = Screens::Gameplay;
                        break;
                    case 1:
                        currentScreen = Screens::Credits;
                        check = !check;
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

        Music(window);
        Input(window);
        Update();
        Draw(window);
    }
}

void App::Draw(sf::RenderWindow &win)
{
    win.clear();
    switch (currentScreen) {
    case Screens::Menu:      
        menu->draw(win);
        break;
    case Screens::Credits:
        credit->draw(win);
        break;
    case Screens::Gameplay:
        TM->draw(win);
        player->draw(win);
        for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
        {
            window.draw(UI[i]);
        }
        break;
    case Screens::GameOver:
        break;
    default:
        break;
    }
    win.display();
}

void App::Input(RenderWindow& win)
{
    switch (currentScreen) {
    case Screens::Menu:
     
        break;
    case Screens::Credits:
        if (menu->GetPressedItem() && check)
        {
            currentScreen = Screens::Menu;
        }
        break;
    case Screens::Gameplay:
        player->move(TM->board,TM->blocks, win, clock);
        TM->input(player);
        break;
    case Screens::GameOver:
        break;
    default:
        break;
    }
}

void App::Update()
{
    switch (TM->getLevel())
    {
    case 1:
        TM->levelOneWincon(player);
        break;
    case 2:
        TM->levelTwoWincon(player);
        break;
    case 3:
        TM->levelThreeWincon(player);
        break;
    case 4:
        TM->setLevel(1);
        currentScreen = Screens::Menu;
        break;
    default:
        break;
    }
}

void App::Music(RenderWindow& win) {

    switch (currentScreen) {
    case Screens::Menu:
        break;
    case Screens::Credits:

        break;
    case Screens::Gameplay:
        music1.setVolume(20);
        music2.setVolume(50);

        break;
    case Screens::GameOver:

        break;
    default:
        break;
    }
}