#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Block {
private:
	RectangleShape rec;
	int posX;
	int posY;
	Texture texture;
	Sprite sprite;
	bool active;
public:
	Block();
	Block(int x1, int y1);
	~Block();
	
	void setPosition(int x, int y);
	int getPositionX();
	int getPositionY();
	void setStrideY(int y);
	void setStrideX(int x);

	Sprite getSprite();

	void setActive(bool act);
	bool getActive();

	void draw(RenderWindow& win);
};
