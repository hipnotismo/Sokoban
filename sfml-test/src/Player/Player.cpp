#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Blocks/Block.h"
#include "Tilemap/Tilemap.h"
using namespace std;
using namespace sf;

Player::Player()
{
	pos.x = 0;
	pos.y = 0;
	posX = 0;
	posY = 0;
	texture.loadFromFile("res/CloakGuy.png");
	sprite.setTexture(texture);

}

Player::~Player()
{
}

void Player::setVPosition(float x1, float y1)
{
	pos.x = x1;
	pos.y = y1;
	sprite.setPosition(x1,y1);
	
}
void Player::setVPosition(Vector2f f)
{
	pos = f;
	sprite.setPosition(f);
}
Vector2f Player::getVPosition()
{
	return pos;
}

void Player::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

int Player::getPositionX()
{
	return posX;
}

int Player::getPositionY()
{
	return posY;
}

void Player::draw(RenderWindow& win)
{
	win.draw(sprite);
}

void Player::move()
{
	bool canMove = true;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//for (int i = 0; i < 10; i++) //Length 10 is the amount of blocks created in Tilemap.cpp
		//{
		//	if (blocks[i]->getPositionY() == posY + 1 && blocks[i]->getPositionX() == posX && board[posX][posY + 2].id == 6 && blocks[i]->getActive()) {
		//		
		//	}
		//}
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
