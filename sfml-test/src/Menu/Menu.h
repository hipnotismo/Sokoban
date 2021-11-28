#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "App/App.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	//void Input();
	int GetPressedItem() { return selectedItemIndex; }
	//sf::Event event;

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

