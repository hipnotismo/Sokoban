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
	menu[0].setPosition(sf::Vector2f(width / 40, 50));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Creditos");
	menu[1].setPosition(sf::Vector2f(width / 40, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Salida");
	menu[2].setPosition(sf::Vector2f(width / 40, height - 60));


	title.setFont(font);
	title.setFillColor(sf::Color::Cyan);
	title.setString("SOKOBAN");
	title.setCharacterSize(40);
	title.setPosition(sf::Vector2f(width / 40, 10));

	control[0].setFont(font);
	control[0].setFillColor(sf::Color::Cyan);
	control[0].setString("W y S para navegar");
	control[0].setCharacterSize(15);
	control[0].setPosition(sf::Vector2f(width - 300, 30));


	control[1].setFont(font);
	control[1].setFillColor(sf::Color::Cyan);
	control[1].setString("W,A,S,D para mover al personaje");
	control[1].setCharacterSize(15);
	control[1].setPosition(sf::Vector2f(width - 300, 60));


	control[2].setFont(font);
	control[2].setFillColor(sf::Color::Cyan);
	control[2].setString("R para resetear el nivel");
	control[2].setCharacterSize(15);
	control[2].setPosition(sf::Vector2f(width - 300, 90));

	control[3].setFont(font);
	control[3].setFillColor(sf::Color::Cyan);
	control[3].setString("P para volver al menu");
	control[3].setCharacterSize(15);
	control[3].setPosition(sf::Vector2f(width - 300, 110));

	control[3].setFont(font);
	control[3].setFillColor(sf::Color::Cyan);
	control[3].setString("ENTER para interactuar");
	control[3].setCharacterSize(15);
	control[3].setPosition(sf::Vector2f(width - 300, 130));


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

	for (int i = 0; i < MAX_NUMBER_OF_CONTROL; i++)
	{
		window.draw(control[i]);
	}

	window.draw(title);

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
