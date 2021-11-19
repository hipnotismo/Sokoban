#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include "Player/Player.h"


class App {
private:
	sf::RenderWindow window;
	enum class Screens
	{
		Menu = 0, Gameplay, GameOver, Credits
	};
	Screens currentScreen;
	sf::CircleShape shape;
	std::queue<sf::CircleShape> q;
	Player* player;
	//vector<int> test;
	
	
public:
	App();
	~App();
	void LoopApp();

	void Draw(sf::RenderWindow &win);
};