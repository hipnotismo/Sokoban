#include "menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("res/arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
	texture.loadFromFile("res/background.png");
	sprite.setTexture(texture);


}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}

}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
/*
void Menu::Input()
{

	switch (event.type)
	{
	case sf::Event::KeyReleased:
		switch (event.key.code)
		{
			case (sf::Keyboard::isKeyPressed(sf::Keyboard::W)):
			MoveUp();
			break;

		case sf::Keyboard::Down:
			MoveDown();
			break;

		case sf::Keyboard::Return:
			switch (GetPressedItem())
			{
			case 0:
				std::cout << "Play button has been pressed" << std::endl;
				break;
			case 1:
				std::cout << "Option button has been pressed" << std::endl;
				break;
			case 2:
			//	window.close();
				break;
			}

			break;
		}

		break;
	case sf::Event::Closed:
	//	window.close();

		break;

	}
}

*/