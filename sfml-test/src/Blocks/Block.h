#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Block{
private:
	RectangleShape rec;
	int posX;
	int posY;
	bool active;
	Texture texture;
	Sprite sprite;
public:
	Block(int x, int y);
	~Block();
}
