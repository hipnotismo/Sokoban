#pragma once

#include <SFML/Graphics.hpp>

#include<iostream>

#include "Player/player.h"
#include "Tilemap/tilemap.h"
#include "Menu/menu.h"
#include "Credits/credits.h"

using namespace sf;

class App {
private:
	sf::RenderWindow window;
	enum class Screens
	{
		Menu = 0, Gameplay, GameOver, Credits
	};
	Screens currentScreen;
	Player* player;
	Tilemap* TM;
	Menu* menu;
	credits* credit;
	bool check;
	//vector<int> test;
	
	
public:
	App();
	~App();
	void LoopApp();
	void Draw(sf::RenderWindow &win);
	void Input();

};
