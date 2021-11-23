#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Block {
private:
	RectangleShape rec;
	Vector2f pos;
	Texture texture;
	Sprite sprite;
	bool active;
public:
	Block();
	Block(int x1, int y1);
	~Block();
	void setPosition(float x1, float y1);
	void setPosition(Vector2f f);
	void setActive(bool act);
	Vector2f getPosition();
	bool getActive();

	void draw(RenderWindow& win);
};
