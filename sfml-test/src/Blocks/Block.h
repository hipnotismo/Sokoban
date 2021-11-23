#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Block {
private:
	RectangleShape rec;
	Texture texture;
	Sprite sprite;
	int posX;
	int posY;
	bool active;
public:
	Block(int x, int y);
	~Block();
};
