#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
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
	~Block();
	
	void setPosition(int x, int y);
	int getPositionX();
	int getPositionY();
	void setStrideY(int y);
	void setStrideX(int x);

	Sprite getSprite();

	void setActive(bool act);
	bool getActive();

	void reset();

	void draw(RenderWindow& win);
};
