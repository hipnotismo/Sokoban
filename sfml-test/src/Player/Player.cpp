#include "Player.h"

Player::Player()
{
	posX = 0;
	posY = 0;
	texture.loadFromFile("res/CloakGuy.png");
	sprite.setTexture(texture);
	s.push_back(sprite);
}

Player::~Player()
{
}

void Player::draw(RenderWindow& win)
{
	win.draw(s.front());
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		cout << "Moving left" << endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		cout << "Moving right" << endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		cout << "Moving up" << endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		cout << "Moving down" << endl;
	}
}
