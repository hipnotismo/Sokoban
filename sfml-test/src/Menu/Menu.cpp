#include "menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("res/arial.ttf"))
	{
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("Jugar");
	menu[0].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Creditos");
	menu[1].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Salida");
	menu[2].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));



	control.setFont(font);
	control.setFillColor(sf::Color::Cyan);
	control.setString("W y S para navegar ENTER para interactuar");
	control.setCharacterSize(15);
	control.setPosition(sf::Vector2f(width - 300 ,  30 ));


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
	window.draw(control);

}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
	}
}
