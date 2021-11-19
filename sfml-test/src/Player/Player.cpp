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
