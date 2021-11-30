#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Tilemap/tilemap.h"
#include "Timer/theomer.h"

class Block;

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

	SoundBuffer buffer;
	Sound sound;

	bool canMove = true;
	float delayCanMove;
	float auxDelayCanMove;

	
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
	void move(Tile board[9][18], Block* blocks[], RenderWindow& win, Theomer clock);
};

