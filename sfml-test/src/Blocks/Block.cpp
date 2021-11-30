#include "block.h"

Block::Block()
{
	rec.setSize({ 40,40 });
	rec.setPosition(0,0);
	pos.x = 0;
	pos.y = 0;
	active = false;

	texture.loadFromFile("res/Block.png");
	sprite.setTexture(texture);
}

Block::Block(int x1, int y1)
{
	rec.setSize({40,40});
	rec.setPosition(x1,y1);
	pos.x = x1;
	pos.y = x1;
	active = false;

	texture.loadFromFile("res/Block.png");
	sprite.setTexture(texture);
}

Block::~Block()
{

}

void Block::setVPosition(float x1, float y1)
{
	pos.x = x1;
	pos.y = y1;
	sprite.setPosition(x1, y1);
	
}
void Block::setVPosition(Vector2f f)
{
	pos = f;
	sprite.setPosition(f);
}
Vector2f Block::getVPosition()
{
	return pos;
}

void Block::setPosition(int x, int y)
{
	posX = x;
	posY = y;
	sprite.setPosition(x, y);
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

void Block::draw(RenderWindow& win)
{
	if (active)
	{
		win.draw(sprite);	
	}
}
