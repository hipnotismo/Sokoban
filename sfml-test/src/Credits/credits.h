#pragma once


#include <SFML/Graphics.hpp>

//#include "App/app.h"

using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class credits
{
private:
	sf::Font font;
	sf::Text credit[MAX_NUMBER_OF_ITEMS];
	Texture texture;
	Sprite sprite;
	//App* app;
public:
	credits(float width, float height);
	~credits();
	void draw(sf::RenderWindow& window);
	void input();

};

