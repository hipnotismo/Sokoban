#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include<iostream>

#include "Player/player.h"
#include "Tilemap/tilemap.h"
#include "Menu/menu.h"
#include "Credits/credits.h"
#include "Timer/theomer.h"

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
	Music music1;
	Music music2;
	Theomer clock;

	sf::Font font;
	sf::Text UI1;
	sf::Text UI2;

	bool check;
	//vector<int> test;
	
	
public:
	App();
	~App();
	void LoopApp();
	void Draw(sf::RenderWindow &win);
	void Input(RenderWindow &win);
	void Update();
	void Music(RenderWindow& win);

};
