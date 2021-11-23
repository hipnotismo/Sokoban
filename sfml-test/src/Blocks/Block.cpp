#include "Block.h"

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

void Block::setPosition(float x1, float y1)
{
	pos.x = x1;
	pos.y = y1;
	sprite.setPosition(x1, y1);

}
void Block::setPosition(Vector2f f)
{
	pos = f;
	sprite.setPosition(f);
}
void Block::setActive(bool act) {
	active = act;
}

Vector2f Block::getPosition()
{
	return pos;
}
bool Block::getActive() {
	return active;
}

void Block::draw(RenderWindow& win)
{
	win.draw(sprite);
}
