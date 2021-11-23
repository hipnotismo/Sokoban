#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Player.h"
#include "Tilemap/Tilemap.h"
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
	//vector<int> test;
	
	
public:
	App();
	~App();
	void LoopApp();

	void Draw(sf::RenderWindow &win);
	void Input();
};