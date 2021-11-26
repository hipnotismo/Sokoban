#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Blocks/Block.h"
#include "Tilemap/Tilemap.h"
using namespace std;
using namespace sf;

class Player
{
private:
	Vector2f pos;
	int posX;
	int posY;
	Texture texture;
	Sprite sprite;
public:
	Player();
	~Player();

	void setVPosition(float x1, float y1);
	void setVPosition(Vector2f f);
	Vector2f getVPosition();

	void setPosition(int x, int y);
	int getPositionX();
	int getPositionY();

	void draw(RenderWindow& win);
	void move();
};

