#include "credits.h"

credits::credits(float width, float height)
{
	//app = new App();

	if (!font.loadFromFile("res/arial.ttf"))
	{
		// handle error
	}

	credit[0].setFont(font);
	credit[0].setFillColor(sf::Color::Red);
	credit[0].setString("Creado por Martin Concetti y Matias Karplus. V0.8");
	credit[0].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 8) * 1));

	credit[1].setFont(font);
	credit[1].setFillColor(sf::Color::Red);
	credit[1].setString("Usando SFML");
	credit[1].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 8) * 2));

	credit[2].setFont(font);
	credit[2].setFillColor(sf::Color::Red);
	credit[2].setString("V0.7");
	credit[2].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 8) * 3));

	texture.loadFromFile("res/background.png");
	sprite.setTexture(texture);

}

credits::~credits()
{

}

void credits::draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(credit[i]);
	}
}

void credits::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		//app->change(0);
	}
}
