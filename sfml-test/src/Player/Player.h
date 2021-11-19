#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;

class Player
{
private:
	int posX;
	int posY;
	Texture texture;
	Sprite sprite;
	std::vector<Sprite> s;

public:
	Player();
	~Player();
	void draw(RenderWindow& win);
};

