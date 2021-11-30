#include "block.h"

Block::Block()
{
	posX = 0;
	posY = 0;
	rec.setSize({ 40,40 });
	rec.setPosition(0,0);
	active = false;

	texture.loadFromFile("res/Block.png");
	sprite.setTexture(texture);
}

Block::~Block()
{

}

void Block::setPosition(int x, int y)
{
	posX = x;
	posY = y;
}

int Block::getPositionX()
{
	return posX;
}

int Block::getPositionY()
{
	return posY;
}
void Block::setStrideY(int y)
{
	posY = posY + y;
}
void Block::setStrideX(int x)
{
	posX = posX + x;
}
Sprite Block::getSprite() {
	return sprite;
}

void Block::setActive(bool act) {
	active = act;
}
bool Block::getActive() {
	return active;
}

void Block::reset()
{
	posX = -1; //well outside the board
	posY = -1;
	active = false;
}

void Block::draw(RenderWindow& win)
{
	sprite.setPosition((posX * 40) + 40, (posY * 40) + 25);
	
	if (active)
	{
		win.draw(sprite);
	}
}
