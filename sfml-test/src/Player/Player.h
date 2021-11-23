#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Player
{
private:
	Vector2f pos;
	Texture texture;
	Sprite sprite;
public:
	Player();
	~Player();
	void setPosition(float x1, float y1);
	void setPosition(Vector2f f);
	Vector2f getPosition();

	void draw(RenderWindow& win);
	void move();
};

