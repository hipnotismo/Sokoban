#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Block {
private:
	RectangleShape rec;
	Vector2f pos;
	int posX;
	int posY;
	Texture texture;
	Sprite sprite;
	bool active;
public:
	Block();
	Block(int x1, int y1);
	~Block();
	void setVPosition(float x1, float y1);
	void setVPosition(Vector2f f);
	Vector2f getVPosition();

	void setPosition(int x, int y);
	int getPositionX();
	int getPositionY();

	Sprite getSprite();

	void setActive(bool act);
	bool getActive();

	void draw(RenderWindow& win);
};
