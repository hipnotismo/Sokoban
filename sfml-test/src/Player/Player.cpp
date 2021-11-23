#include "Player.h"

Player::Player()
{
	pos.x = 0;
	pos.y = 0;
	texture.loadFromFile("res/CloakGuy.png");
	sprite.setTexture(texture);

}

Player::~Player()
{
}

void Player::setPosition(float x1, float y1)
{
	pos.x = x1;
	pos.y = y1;
	sprite.setPosition(x1,y1);
	
}
void Player::setPosition(Vector2f f)
{
	pos = f;
	sprite.setPosition(f);
}
Vector2f Player::getPosition()
{
	return pos;
}

void Player::draw(RenderWindow& win)
{
	win.draw(sprite);
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
